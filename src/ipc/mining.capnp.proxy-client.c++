// Generated by mpgen from /home/zaidmstrr/bitcoin/src/ipc/capnp/mining.capnp

#include <src/ipc/capnp/mining.capnp.proxy-types.h>
#include <mp/proxy-types.h>

namespace mp {
ProxyClient<ipc::capnp::messages::Mining>::M0::Result ProxyClient<ipc::capnp::messages::Mining>::isTestChain() {
    typename M0::Result result;
    clientInvoke(*this, &ipc::capnp::messages::Mining::Client::isTestChainRequest, MakeClientParam<Accessor<mining_fields::Context, FIELD_IN | FIELD_BOXED>>(), MakeClientParam<Accessor<mining_fields::Result, FIELD_OUT>>(result));
    return result;
}
ProxyClient<ipc::capnp::messages::Mining>::M1::Result ProxyClient<ipc::capnp::messages::Mining>::isInitialBlockDownload() {
    typename M1::Result result;
    clientInvoke(*this, &ipc::capnp::messages::Mining::Client::isInitialBlockDownloadRequest, MakeClientParam<Accessor<mining_fields::Context, FIELD_IN | FIELD_BOXED>>(), MakeClientParam<Accessor<mining_fields::Result, FIELD_OUT>>(result));
    return result;
}
ProxyClient<ipc::capnp::messages::Mining>::M2::Result ProxyClient<ipc::capnp::messages::Mining>::getTip() {
    typename M2::Result result;
    clientInvoke(*this, &ipc::capnp::messages::Mining::Client::getTipRequest, MakeClientParam<Accessor<mining_fields::Context, FIELD_IN | FIELD_BOXED>>(), MakeClientParam<Accessor<mining_fields::Result, FIELD_OUT | FIELD_OPTIONAL | FIELD_BOXED>>(result));
    return result;
}
ProxyClient<ipc::capnp::messages::Mining>::M3::Result ProxyClient<ipc::capnp::messages::Mining>::waitTipChanged(M3::Param<0> currentTip,M3::Param<1> timeout) {
    typename M3::Result result;
    clientInvoke(*this, &ipc::capnp::messages::Mining::Client::waitTipChangedRequest, MakeClientParam<Accessor<mining_fields::Context, FIELD_IN | FIELD_BOXED>>(), MakeClientParam<Accessor<mining_fields::CurrentTip, FIELD_IN | FIELD_BOXED>>(currentTip), MakeClientParam<Accessor<mining_fields::Timeout, FIELD_IN>>(timeout), MakeClientParam<Accessor<mining_fields::Result, FIELD_OUT | FIELD_BOXED>>(result));
    return result;
}
ProxyClient<ipc::capnp::messages::Mining>::M4::Result ProxyClient<ipc::capnp::messages::Mining>::createNewBlock(M4::Param<0> options) {
    typename M4::Result result;
    clientInvoke(*this, &ipc::capnp::messages::Mining::Client::createNewBlockRequest, MakeClientParam<Accessor<mining_fields::Options, FIELD_IN | FIELD_BOXED>>(options), MakeClientParam<Accessor<mining_fields::Result, FIELD_OUT | FIELD_BOXED>>(result));
    return result;
}
ProxyClient<ipc::capnp::messages::BlockTemplate>::M0::Result ProxyClient<ipc::capnp::messages::BlockTemplate>::destroy(Super& super) {
    clientInvoke(super, &ipc::capnp::messages::BlockTemplate::Client::destroyRequest, MakeClientParam<Accessor<mining_fields::Context, FIELD_IN | FIELD_BOXED>>());
}
ProxyClient<ipc::capnp::messages::BlockTemplate>::M1::Result ProxyClient<ipc::capnp::messages::BlockTemplate>::getBlockHeader() {
    typename M1::Result result;
    clientInvoke(*this, &ipc::capnp::messages::BlockTemplate::Client::getBlockHeaderRequest, MakeClientParam<Accessor<mining_fields::Context, FIELD_IN | FIELD_BOXED>>(), MakeClientParam<Accessor<mining_fields::Result, FIELD_OUT | FIELD_BOXED>>(result));
    return result;
}
ProxyClient<ipc::capnp::messages::BlockTemplate>::M2::Result ProxyClient<ipc::capnp::messages::BlockTemplate>::getBlock() {
    typename M2::Result result;
    clientInvoke(*this, &ipc::capnp::messages::BlockTemplate::Client::getBlockRequest, MakeClientParam<Accessor<mining_fields::Context, FIELD_IN | FIELD_BOXED>>(), MakeClientParam<Accessor<mining_fields::Result, FIELD_OUT | FIELD_BOXED>>(result));
    return result;
}
ProxyClient<ipc::capnp::messages::BlockTemplate>::M3::Result ProxyClient<ipc::capnp::messages::BlockTemplate>::getTxFees() {
    typename M3::Result result;
    clientInvoke(*this, &ipc::capnp::messages::BlockTemplate::Client::getTxFeesRequest, MakeClientParam<Accessor<mining_fields::Context, FIELD_IN | FIELD_BOXED>>(), MakeClientParam<Accessor<mining_fields::Result, FIELD_OUT | FIELD_BOXED>>(result));
    return result;
}
ProxyClient<ipc::capnp::messages::BlockTemplate>::M4::Result ProxyClient<ipc::capnp::messages::BlockTemplate>::getTxSigops() {
    typename M4::Result result;
    clientInvoke(*this, &ipc::capnp::messages::BlockTemplate::Client::getTxSigopsRequest, MakeClientParam<Accessor<mining_fields::Context, FIELD_IN | FIELD_BOXED>>(), MakeClientParam<Accessor<mining_fields::Result, FIELD_OUT | FIELD_BOXED>>(result));
    return result;
}
ProxyClient<ipc::capnp::messages::BlockTemplate>::M5::Result ProxyClient<ipc::capnp::messages::BlockTemplate>::getCoinbaseTx() {
    typename M5::Result result;
    clientInvoke(*this, &ipc::capnp::messages::BlockTemplate::Client::getCoinbaseTxRequest, MakeClientParam<Accessor<mining_fields::Context, FIELD_IN | FIELD_BOXED>>(), MakeClientParam<Accessor<mining_fields::Result, FIELD_OUT | FIELD_BOXED>>(result));
    return result;
}
ProxyClient<ipc::capnp::messages::BlockTemplate>::M6::Result ProxyClient<ipc::capnp::messages::BlockTemplate>::getCoinbaseCommitment() {
    typename M6::Result result;
    clientInvoke(*this, &ipc::capnp::messages::BlockTemplate::Client::getCoinbaseCommitmentRequest, MakeClientParam<Accessor<mining_fields::Context, FIELD_IN | FIELD_BOXED>>(), MakeClientParam<Accessor<mining_fields::Result, FIELD_OUT | FIELD_BOXED>>(result));
    return result;
}
ProxyClient<ipc::capnp::messages::BlockTemplate>::M7::Result ProxyClient<ipc::capnp::messages::BlockTemplate>::getWitnessCommitmentIndex() {
    typename M7::Result result;
    clientInvoke(*this, &ipc::capnp::messages::BlockTemplate::Client::getWitnessCommitmentIndexRequest, MakeClientParam<Accessor<mining_fields::Context, FIELD_IN | FIELD_BOXED>>(), MakeClientParam<Accessor<mining_fields::Result, FIELD_OUT>>(result));
    return result;
}
ProxyClient<ipc::capnp::messages::BlockTemplate>::M8::Result ProxyClient<ipc::capnp::messages::BlockTemplate>::getCoinbaseMerklePath() {
    typename M8::Result result;
    clientInvoke(*this, &ipc::capnp::messages::BlockTemplate::Client::getCoinbaseMerklePathRequest, MakeClientParam<Accessor<mining_fields::Context, FIELD_IN | FIELD_BOXED>>(), MakeClientParam<Accessor<mining_fields::Result, FIELD_OUT | FIELD_BOXED>>(result));
    return result;
}
ProxyClient<ipc::capnp::messages::BlockTemplate>::M9::Result ProxyClient<ipc::capnp::messages::BlockTemplate>::submitSolution(M9::Param<0> version,M9::Param<1> timestamp,M9::Param<2> nonce,M9::Param<3> coinbase) {
    typename M9::Result result;
    clientInvoke(*this, &ipc::capnp::messages::BlockTemplate::Client::submitSolutionRequest, MakeClientParam<Accessor<mining_fields::Context, FIELD_IN | FIELD_BOXED>>(), MakeClientParam<Accessor<mining_fields::Version, FIELD_IN>>(version), MakeClientParam<Accessor<mining_fields::Timestamp, FIELD_IN>>(timestamp), MakeClientParam<Accessor<mining_fields::Nonce, FIELD_IN>>(nonce), MakeClientParam<Accessor<mining_fields::Coinbase, FIELD_IN | FIELD_BOXED>>(coinbase), MakeClientParam<Accessor<mining_fields::Result, FIELD_OUT>>(result));
    return result;
}
namespace {
ProxyTypeRegister t17998218332041048990{TypeList<interfaces::Mining>{}};
ProxyTypeRegister t17971362354162759202{TypeList<interfaces::BlockTemplate>{}};
} // namespace
} // namespace mp
