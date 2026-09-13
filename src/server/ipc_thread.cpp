#include "ipc_thread.h"
#include "rpc_interface.h"
#include <kj/async.h>
#include <kj/async-io.h>
#include <kj/debug.h>
#include <capnp/rpc-twoparty.h>
#include "init.capnp.h"
#include <event2/event.h>
#include <event2/http.h>
#include <event2/buffer.h>
#include <event2/keyvalq_struct.h>
#include <univalue.h>
#include <future>
#include <iostream>
#include <stdexcept>

namespace {

// Builds a JSON-RPC error response with result=null.
static UniValue makeErrorResp(int code, const std::string& msg, UniValue id) {
    UniValue error(UniValue::VOBJ);\
    error.pushKV("code", code);
    error.pushKV("message", msg);
    UniValue resp(UniValue::VOBJ);
    resp.pushKV("result", UniValue(UniValue::VNULL));
    resp.pushKV("error", std::move(error));
    resp.pushKV("id", std::move(id));
    return resp;
}

// Parses the JSON body and dispatches to the correct RpcInterface method.
// The returned promise resolves to a complete JSON-RPC response (result/error/id).
static kj::Promise<UniValue> dispatch(RpcInterface& rpc, const std::string& body) {
    UniValue req;
    if (!req.read(body) || !req.isObject()) {
        return makeErrorResp(-32700, "Parse error: invalid JSON", UniValue(UniValue::VNULL));
    }
    if (!req.exists("method") || !req["method"].isStr()) {
        return makeErrorResp(-32600, "Invalid Request: missing or invalid 'method'",
            req.exists("id") ? req["id"] : UniValue(UniValue::VNULL));
    }

    std::string method = req["method"].get_str();
    UniValue params = req.exists("params") ? req["params"] : UniValue(UniValue::VARR);
    UniValue id     = req.exists("id")     ? req["id"]     : UniValue(UniValue::VNULL);

    if (method == "getblockhash") {
        if (params.size() < 1 || !params[0].isNum()) {
            return makeErrorResp(-32602, "Invalid params: height must be an integer", id);
        }
        return rpc.getBlockHash(params[0].get_int()).then([id](UniValue result) mutable {
            result.pushKV("id", std::move(id));
            return result;
        });
    }
    if (method == "initmessage") {
        if (params.size() < 1 || !params[0].isStr()) {
            return makeErrorResp(-32602, "Invalid params: message must be a string", id);
        }
        return rpc.sendInitMessage(params[0].get_str()).then([id](UniValue result) mutable {
            result.pushKV("id", std::move(id));
            return result;
        });
    }

    return makeErrorResp(-32601, "Method not found: " + method, std::move(id));
}

struct ResponseCtx {
    evhttp_request* req;
    std::string body;
};

// Runs on the libevent thread, scheduled via event_base_once().
static void sendResponseCb(evutil_socket_t, short, void* arg) {
    auto* ctx = static_cast<ResponseCtx*>(arg);
    struct evkeyvalq* headers = evhttp_request_get_output_headers(ctx->req);
    evhttp_add_header(headers, "Content-Type", "application/json");
    struct evbuffer* buf = evbuffer_new();
    if (buf) {
        evbuffer_add(buf, ctx->body.c_str(), ctx->body.size());
        evhttp_send_reply(ctx->req, HTTP_OK, "OK", buf);
        evbuffer_free(buf);
    } else {
        evhttp_send_error(ctx->req, HTTP_INTERNAL, "Internal Server Error");
    }
    // evhttp_send_reply hands ownership back to libevent.
    delete ctx;
}

// Schedules the HTTP response on the libevent event base.
static void postResponse(struct event_base* base,
                         evhttp_request* req, UniValue response) {
    static constexpr timeval zero = {0, 0};
    auto* ctx = new ResponseCtx{req, response.write()};
    event_base_once(base, -1, EV_TIMEOUT, sendResponseCb, ctx, &zero);
}

} // namespace

// Spawns the KJ thread and blocks until it has connected to bitcoin-node or throws.
IpcThread::IpcThread(const std::string& socketPath) {
    std::promise<void> ready;
    auto readyFuture = ready.get_future();

    thread = std::thread([this, socketPath, p = std::move(ready)]() mutable {
        run(socketPath, std::move(p));
    });

    try {
        readyFuture.get(); // propagates any startup exception to the caller
    } catch (...) {
        // The KJ thread set the exception and returned; join before rethrowing
        // so std::thread::~thread() doesn't call std::terminate().
        if (thread.joinable()) thread.join();
        throw;
    }
}

// Fulfills the shutdown promise on the KJ thread so run()'s wait() returns, then joins it.
IpcThread::~IpcThread() {
    if (executor) {
        try {
            executor->executeSync([this]() { shutdownFulfiller->fulfill(); });
        } catch (const kj::Exception&) {
            // KJ thread's event loop already exited; nothing left to signal.
        }
    }
    if (thread.joinable()) thread.join();
}

// Builds the dispatch promise and registers it with the KJ thread's TaskSet.
// Runs on the KJ thread, invoked cross-thread via executor->executeSync().
void IpcThread::dispatchWork(Work work) {
    evhttp_request* req   = work.req;
    struct event_base* eb = work.base;
    tasks->add(
        dispatch(*rpc, work.body).then(
            [this, req, eb](UniValue result) {
                inFlight.fetch_sub(1, std::memory_order_relaxed);
                postResponse(eb, req, std::move(result));
            },
            [this, req, eb](kj::Exception&& e) {
                inFlight.fetch_sub(1, std::memory_order_relaxed);
                postResponse(eb, req,
                    makeErrorResp(-32603,
                        std::string("Internal error: ") +
                            e.getDescription().cStr(),
                        UniValue(UniValue::VNULL)));
            }));
}

// Hands work to the KJ thread via kj::Executor. Rejects with the error 503 if the KJ
// event loop has already exited or too many requests are outstanding.
void IpcThread::submit(Work work) {
    evhttp_request* req = work.req;

    if (inFlight.fetch_add(1, std::memory_order_relaxed) >= kMaxInFlight) {
        inFlight.fetch_sub(1, std::memory_order_relaxed);
        evhttp_send_error(req, HTTP_SERVUNAVAIL, "Server overloaded");
        return;
    }

    try {
        executor->executeSync([this, w = std::move(work)]() mutable {
            dispatchWork(std::move(w));
        });
    } catch (const kj::Exception&) {
        inFlight.fetch_sub(1, std::memory_order_relaxed);
        evhttp_send_error(req, HTTP_SERVUNAVAIL, "Server shutting down");
    }
}

// Sets up the event loop, Cap'n Proto connection, and publishes the cross-thread executor.
void IpcThread::run(const std::string& socketPath, std::promise<void> ready) {
    try {
        auto ioCtx = kj::setupAsyncIo();
        auto& waitScope = ioCtx.waitScope;

        std::string normalised = socketPath;
        if (normalised.substr(0, 5) != "unix:" &&
            normalised.find('/') != std::string::npos) {
            normalised = "unix:" + normalised;
        }
        std::cout << "Connecting to bitcoin-node: " << normalised << "\n";

        auto addr = ioCtx.provider->getNetwork()
            .parseAddress(normalised.c_str()).wait(waitScope);
        auto socket = addr->connect().wait(waitScope);

        auto capnpClient = kj::heap<capnp::TwoPartyClient>(*socket);
        auto initClient =
            capnpClient->bootstrap().castAs<ipc::capnp::messages::Init>();

        auto constructResp = initClient.constructRequest().send().wait(waitScope);
        KJ_REQUIRE(constructResp.hasThreadMap(), "No ThreadMap capability");
        auto threadMap = constructResp.getThreadMap();

        auto makeThreadResp = threadMap.makeThreadRequest().send().wait(waitScope);
        KJ_REQUIRE(makeThreadResp.hasResult(), "No Thread capability");
        auto thread = makeThreadResp.getResult();

        auto makeChainReq = initClient.makeChainRequest();
        makeChainReq.getContext().setThread(thread);
        auto makeChainResp = makeChainReq.send().wait(waitScope);
        KJ_REQUIRE(makeChainResp.hasResult(), "No Chain capability");

        auto rpcOwner = std::make_unique<RpcInterface>(
            kj::mv(threadMap), kj::mv(thread), makeChainResp.getResult());
        rpc = rpcOwner.get();

        struct TaskErrHandler final : kj::TaskSet::ErrorHandler {
            void taskFailed(kj::Exception&& e) override {
                KJ_LOG(ERROR, "Unexpected IPC task failure", e);
            }
        } errHandler;
        kj::TaskSet taskSet(errHandler);
        tasks = &taskSet;

        auto shutdownPaf = kj::newPromiseAndFulfiller<void>();
        shutdownFulfiller = kj::mv(shutdownPaf.fulfiller);
        executor = kj::getCurrentThreadExecutor().addRef();
        ready.set_value();
        shutdownPaf.promise.wait(waitScope);

    } catch (const kj::Exception& e) {
        // kj::Exception must be destroyed on the thread that created it (KJ aborts
        // otherwise); convert to a plain exception before it crosses the promise/future.
        try {
            ready.set_exception(std::make_exception_ptr(std::runtime_error(e.getDescription().cStr())));
        } catch (...) {}
    } catch (...) {
        try { ready.set_exception(std::current_exception()); } catch (...) {}
    }
}
