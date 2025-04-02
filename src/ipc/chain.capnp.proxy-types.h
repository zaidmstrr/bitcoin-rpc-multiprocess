// Generated by mpgen from /home/zaidmstrr/bitcoin/src/ipc/capnp/chain.capnp

#ifndef CAPNP_CHAIN_CAPNP_PROXY_TYPES_H
#define CAPNP_CHAIN_CAPNP_PROXY_TYPES_H

#include <chain.capnp.proxy.h>
#include <../capnp/chain-types.h>
namespace mp {
template<>
struct ProxyType<FeeCalculation>
{
public:
    using Struct = ipc::capnp::messages::FeeCalculation;
    static decltype(auto) get(std::integral_constant<size_t, 0>) { return &FeeCalculation::est; }
    static decltype(auto) get(std::integral_constant<size_t, 1>) { return &FeeCalculation::reason; }
    static decltype(auto) get(std::integral_constant<size_t, 2>) { return &FeeCalculation::desiredTarget; }
    static decltype(auto) get(std::integral_constant<size_t, 3>) { return &FeeCalculation::returnedTarget; }
    static constexpr size_t fields = 4;
};
template<>
struct ProxyType<EstimationResult>
{
public:
    using Struct = ipc::capnp::messages::EstimationResult;
    static decltype(auto) get(std::integral_constant<size_t, 0>) { return &EstimationResult::pass; }
    static decltype(auto) get(std::integral_constant<size_t, 1>) { return &EstimationResult::fail; }
    static decltype(auto) get(std::integral_constant<size_t, 2>) { return &EstimationResult::decay; }
    static decltype(auto) get(std::integral_constant<size_t, 3>) { return &EstimationResult::scale; }
    static constexpr size_t fields = 4;
};
template<>
struct ProxyType<EstimatorBucket>
{
public:
    using Struct = ipc::capnp::messages::EstimatorBucket;
    static decltype(auto) get(std::integral_constant<size_t, 0>) { return &EstimatorBucket::start; }
    static decltype(auto) get(std::integral_constant<size_t, 1>) { return &EstimatorBucket::end; }
    static decltype(auto) get(std::integral_constant<size_t, 2>) { return &EstimatorBucket::withinTarget; }
    static decltype(auto) get(std::integral_constant<size_t, 3>) { return &EstimatorBucket::totalConfirmed; }
    static decltype(auto) get(std::integral_constant<size_t, 4>) { return &EstimatorBucket::inMempool; }
    static decltype(auto) get(std::integral_constant<size_t, 5>) { return &EstimatorBucket::leftMempool; }
    static constexpr size_t fields = 6;
};
template<>
struct ProxyType<CRPCCommand>
{
public:
    using Struct = ipc::capnp::messages::RPCCommand;
    static decltype(auto) get(std::integral_constant<size_t, 0>) { return &CRPCCommand::category; }
    static decltype(auto) get(std::integral_constant<size_t, 1>) { return &CRPCCommand::name; }
    static decltype(auto) get(std::integral_constant<size_t, 2>) { return &CRPCCommand::actor; }
    static decltype(auto) get(std::integral_constant<size_t, 3>) { return &CRPCCommand::argNames; }
    static decltype(auto) get(std::integral_constant<size_t, 4>) { return &CRPCCommand::unique_id; }
    static constexpr size_t fields = 5;
};
template<>
struct ProxyType<JSONRPCRequest>
{
public:
    using Struct = ipc::capnp::messages::JSONRPCRequest;
    static decltype(auto) get(std::integral_constant<size_t, 0>) { return &JSONRPCRequest::id; }
    static decltype(auto) get(std::integral_constant<size_t, 1>) { return &JSONRPCRequest::strMethod; }
    static decltype(auto) get(std::integral_constant<size_t, 2>) { return &JSONRPCRequest::params; }
    static decltype(auto) get(std::integral_constant<size_t, 3>) { return &JSONRPCRequest::mode; }
    static decltype(auto) get(std::integral_constant<size_t, 4>) { return &JSONRPCRequest::URI; }
    static decltype(auto) get(std::integral_constant<size_t, 5>) { return &JSONRPCRequest::authUser; }
    static decltype(auto) get(std::integral_constant<size_t, 6>) { return &JSONRPCRequest::peerAddr; }
    static decltype(auto) get(std::integral_constant<size_t, 7>) { return &JSONRPCRequest::m_json_version; }
    static constexpr size_t fields = 8;
};
template<>
struct ProxyType<interfaces::BlockInfo>
{
public:
    using Struct = ipc::capnp::messages::BlockInfo;
    static decltype(auto) get(std::integral_constant<size_t, 0>) { return &interfaces::BlockInfo::height; }
    static decltype(auto) get(std::integral_constant<size_t, 1>) { return &interfaces::BlockInfo::file_number; }
    static decltype(auto) get(std::integral_constant<size_t, 2>) { return &interfaces::BlockInfo::data_pos; }
    static decltype(auto) get(std::integral_constant<size_t, 3>) { return &interfaces::BlockInfo::chain_time_max; }
    static constexpr size_t fields = 4;
};
} // namespace mp
#endif
