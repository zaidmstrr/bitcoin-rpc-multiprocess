#include "rpc_interface.h"
#include "utils.h"
#include <algorithm>
#include <vector>

// Stores the Cap'n Proto capabilities needed to issue chain requests.
RpcInterface::RpcInterface(
    ::mp::ThreadMap::Client threadMap,
    ::mp::Thread::Client thread,
    ::ipc::capnp::messages::Chain::Client chainInterface)
    : threadMap(kj::mv(threadMap)),
      thread(kj::mv(thread)),
      chainInterface(kj::mv(chainInterface)) {}

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