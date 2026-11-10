#include "rpc_interface.h"
#include "utils.h"
#include <algorithm>
#include <vector>

// Stores the Cap'n Proto capabilities needed to issue chain requests.
RpcInterface::RpcInterface(
    ::mp::ThreadMap::Client threadMap,
    ::mp::Thread::Client thread,
    ::ipc::capnp::messages::Chain::Client chainInterface,
    ::ipc::capnp::messages::Rpc::Client rpcInterface)
    : threadMap(kj::mv(threadMap)),
      thread(kj::mv(thread)),
      chainInterface(kj::mv(chainInterface)),
      rpcInterface(kj::mv(rpcInterface)) {}

// Fetches the block hash at the given height and returns it as a hex string.
kj::Promise<UniValue> RpcInterface::getBlockHash(int32_t height) {
    auto req = chainInterface.getBlockHashRequest();
    req.getContext().setThread(thread);
    req.setHeight(height);
    return req.send().then([](auto response) -> UniValue {
        auto raw = response.getResult().asBytes();
        std::vector<uint8_t> bytes(raw.begin(), raw.end());
        std::reverse(bytes.begin(), bytes.end());
        UniValue resp(UniValue::VOBJ);
        resp.pushKV("result", util::toHex(bytes));
        resp.pushKV("error", UniValue(UniValue::VNULL));
        return resp;
    });
}

// Returns the current active-chain height
kj::Promise<UniValue> RpcInterface::getBlockCount() {
    return executeCoreRpc("getblockcount");
}

// Fetches the current active-chain tip hash via the RPC interface.
kj::Promise<UniValue> RpcInterface::getBestBlockHash() {
    return executeCoreRpc("getbestblockhash");
}

// Executes a zero-argument RPC request through the IPC layer and returns the standard JSON-RPC fields.
kj::Promise<UniValue> RpcInterface::executeCoreRpc(std::string method) {
    UniValue params(UniValue::VARR);
    UniValue request(UniValue::VOBJ);
    request.pushKV("method", method);
    request.pushKV("params", std::move(params));
    request.pushKV("id", 1);
    request.pushKV("jsonrpc", "2.0");

    auto req = rpcInterface.executeRpcRequest();
    req.getContext().setThread(thread);
    req.setRequest(request.write());
    req.setUri("/");
    req.setUser("");
    return req.send().then([](auto response) -> UniValue {
        UniValue rpcResponse;
        KJ_REQUIRE(rpcResponse.read(response.getResult().cStr()),
                   "Invalid JSON response from Bitcoin Core RPC");

            UniValue result(UniValue::VOBJ);
            result.pushKV("result", rpcResponse.exists("result")
                ? rpcResponse["result"] : UniValue(UniValue::VNULL));
            result.pushKV("error", rpcResponse.exists("error")
                ? rpcResponse["error"] : UniValue(UniValue::VNULL));
            return result;
        });
}

// Fetches general blockchain metadata via the RPC interface.
kj::Promise<UniValue> RpcInterface::getBlockchainInfo() {
    return executeCoreRpc("getblockchaininfo");
}

// Fetches the active chain tips via the RPC interface.
kj::Promise<UniValue> RpcInterface::getChainTips() {
    return executeCoreRpc("getchaintips");
}

// Sends an init message to bitcoin-node over Cap'n Proto.
kj::Promise<UniValue> RpcInterface::sendInitMessage(std::string message) {
    auto req = chainInterface.initMessageRequest();
    req.getContext().setThread(thread);
    req.setMessage(message);
    return req.send().then([](auto) -> UniValue {
        UniValue resp(UniValue::VOBJ);
        resp.pushKV("result", "Message sent successfully");
        resp.pushKV("error", UniValue(UniValue::VNULL));
        return resp;
    });
}