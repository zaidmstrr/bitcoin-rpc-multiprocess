#include "rpc_interface.h"
#include "../../include/utils.h"
#include <iostream>
#include <bits/algorithmfwd.h>
#include <algorithm>

RpcInterface::RpcInterface(::mp::ThreadMap::Client threadMap,
             ::mp::Thread::Client thread,
             ::ipc::capnp::messages::Chain::Client chainInterface)
    : rawThreadMap(threadMap), rawThread(thread), rawChain(chainInterface),
      threadMap(threadMap), thread(thread), chainInterface(chainInterface) {}

std::string RpcInterface::getBlockHash(int32_t height, kj::WaitScope& waitScope) {
    std::lock_guard<std::mutex> lock(mutex);
    try {
        auto hasBlocksReq = chainInterface.getBlockHashRequest();
        hasBlocksReq.getContext().setThread(thread);
        hasBlocksReq.setHeight(height);
        auto response = hasBlocksReq.send().wait(waitScope);
        auto blockHashArray = response.getResult().asBytes();
        
        std::vector<uint8_t> blockHashVector(blockHashArray.begin(), blockHashArray.end());
        std::reverse(blockHashVector.begin(), blockHashVector.end());
        
        return util::toHex(blockHashVector);
    } catch (const kj::Exception& e) {
        std::cerr << "KJ Exception in getBlockHash: " << e.getDescription().cStr() << std::endl;
        throw;
    } catch (const std::exception& e) {
        std::cerr << "Error in getBlockHash: " << e.what() << std::endl;
        throw;
    }
}

bool RpcInterface::sendInitMessage(const std::string& message, kj::WaitScope& waitScope) {
    std::lock_guard<std::mutex> lock(mutex);
    try {
        auto messReq = chainInterface.initMessageRequest();
        messReq.getContext().setThread(thread);
        messReq.setMessage(message);
        auto messResponse = messReq.send().wait(waitScope);
        return true;
    } catch (const kj::Exception& e) {
        std::cerr << "KJ Exception in sendInitMessage: " << e.getDescription().cStr() << std::endl;
        return false;
    } catch (const std::exception& e) {
        std::cerr << "Error in sendInitMessage: " << e.what() << std::endl;
        return false;
    }
}