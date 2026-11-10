#ifndef RPC_INTERFACE_H
#define RPC_INTERFACE_H

#include <kj/async.h>
#include <capnp/rpc-twoparty.h>
#include <mp/proxy.capnp.h>
#include "chain.capnp.h"
#include "rpc.capnp.h"
#include <univalue.h>
#include <string>

// All methods return kj::Promise and must be called from the KJ event-loop thread.
// Each returned UniValue already contains "result" and "error" fields;
// the caller adds "id" after the promise resolves.
class RpcInterface {
public:
    RpcInterface(::mp::ThreadMap::Client threadMap,
                 ::mp::Thread::Client thread,
                 ::ipc::capnp::messages::Chain::Client chainInterface,
                 ::ipc::capnp::messages::Rpc::Client rpcInterface);

    kj::Promise<UniValue> getBlockHash(int32_t height);
    kj::Promise<UniValue> getBlockCount();
    kj::Promise<UniValue> getBestBlockHash();
    kj::Promise<UniValue> getBlockchainInfo();
    kj::Promise<UniValue> getChainTips();
    kj::Promise<UniValue> sendInitMessage(std::string message);

private:
    kj::Promise<UniValue> executeCoreRpc(std::string method);

    ::mp::ThreadMap::Client threadMap;
    ::mp::Thread::Client thread;
    ::ipc::capnp::messages::Chain::Client chainInterface;
    ::ipc::capnp::messages::Rpc::Client rpcInterface;
};

#endif // RPC_INTERFACE_H