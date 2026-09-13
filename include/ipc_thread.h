#ifndef IPC_THREAD_H
#define IPC_THREAD_H

#include <kj/async.h>
#include <atomic>
#include <future>
#include <string>
#include <thread>

struct event_base;
struct evhttp_request;
class RpcInterface;

// Runs the KJ event loop and all Cap'n Proto state on a dedicated thread.
// The libevent thread hands work to the KJ thread via kj::Executor; completed
// responses are posted back with event_base_once(), the only thread-safe
// libevent function.
class IpcThread {
public:
    struct Work {
        evhttp_request* req;     // owned caller must call evhttp_request_own first
        std::string body;        // raw JSON request body
        struct event_base* base; // target libevent base for the response callback
    };

    explicit IpcThread(const std::string& socketPath);
    ~IpcThread();

    // Hands work to the KJ event-loop thread. Rejects with HTTP 503 if the IPC
    // thread has shut down or is overloaded.
    void submit(Work work);

private:
    std::thread thread;
    kj::Own<const kj::Executor> executor;        // lets other threads schedule calls on the KJ loop
    kj::Own<kj::PromiseFulfiller<void>> shutdownFulfiller; // fulfilled to unblock run()'s wait
    RpcInterface* rpc{nullptr};   // owned by run()'s stack; valid while the KJ thread is alive
    kj::TaskSet* tasks{nullptr};  // owned by run()'s stack; valid while the KJ thread is alive

    std::atomic<size_t> inFlight{0};
    // Max requests outstanding which is submitted but not yet responded to and before submit() rejects new work.
    static constexpr size_t kMaxInFlight = 10000;

    void run(const std::string& socketPath, std::promise<void> ready);
    void dispatchWork(Work work); // runs on the KJ thread via executor->executeSync()
};

#endif // IPC_THREAD_H
