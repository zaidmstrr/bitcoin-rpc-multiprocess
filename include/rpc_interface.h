#ifndef RPC_INTERFACE_H
#define RPC_INTERFACE_H

#include <capnp/rpc-twoparty.h>
#include <kj/async-io.h>
#include <mutex>
#include "../ipc/init.capnp.h"
#include "../ipc/chain.capnp.h"
#include <mp/proxy.capnp.h>
#include <string>

class RpcInterface {
private:
    capnp::Capability::Client rawThreadMap;
    capnp::Capability::Client rawThread;
    capnp::Capability::Client rawChain;
    
    ::mp::ThreadMap::Client threadMap;
    ::mp::Thread::Client thread;
    ::ipc::capnp::messages::Chain::Client chainInterface;
    std::mutex mutex;

public:
    RpcInterface(::mp::ThreadMap::Client threadMap,
                 ::mp::Thread::Client thread,
                 ::ipc::capnp::messages::Chain::Client chainInterface);
    
    std::string getBlockHash(int32_t height, kj::WaitScope& waitScope);
    bool sendInitMessage(const std::string& message, kj::WaitScope& waitScope);
};

#endif // RPC_INTERFACE_H