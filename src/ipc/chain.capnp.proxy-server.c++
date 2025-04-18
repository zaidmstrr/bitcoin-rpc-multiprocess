// Generated by mpgen from /home/zaidmstrr/bitcoin/src/ipc/capnp/chain.capnp

#include <chain.capnp.proxy-types.h>
#include <mp/proxy-types.h>

namespace mp {
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::destroy(DestroyContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(ServerDestroy()));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::getHeight(GetHeightContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT | FIELD_OPTIONAL>>(ServerCall())));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::getBlockHash(GetBlockHashContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Height, FIELD_IN>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT | FIELD_BOXED>>(ServerCall()))));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::haveBlockOnDisk(HaveBlockOnDiskContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Height, FIELD_IN>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT>>(ServerCall()))));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::getTipLocator(GetTipLocatorContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT | FIELD_BOXED>>(ServerCall())));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::getActiveChainLocator(GetActiveChainLocatorContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::BlockHash, FIELD_IN | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT | FIELD_BOXED>>(ServerCall()))));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::findLocatorFork(FindLocatorForkContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Locator, FIELD_IN | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT | FIELD_OPTIONAL>>(ServerCall()))));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::hasBlockFilterIndex(HasBlockFilterIndexContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::FilterType, FIELD_IN>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT>>(ServerCall()))));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::blockFilterMatchesAny(BlockFilterMatchesAnyContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::FilterType, FIELD_IN>>(MakeServerField<1, Accessor<chain_fields::BlockHash, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::FilterSet, FIELD_IN | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT | FIELD_OPTIONAL>>(ServerCall()))))));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::findBlock(FindBlockContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Hash, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Block, FIELD_IN | FIELD_OUT | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT>>(ServerCall())))));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::findFirstBlockWithTimeAndHeight(FindFirstBlockWithTimeAndHeightContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::MinTime, FIELD_IN>>(MakeServerField<1, Accessor<chain_fields::MinHeight, FIELD_IN>>(MakeServerField<1, Accessor<chain_fields::Block, FIELD_IN | FIELD_OUT | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT>>(ServerCall()))))));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::findAncestorByHeight(FindAncestorByHeightContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::BlockHash, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::AncestorHeight, FIELD_IN>>(MakeServerField<1, Accessor<chain_fields::Ancestor, FIELD_IN | FIELD_OUT | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT>>(ServerCall()))))));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::findAncestorByHash(FindAncestorByHashContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::BlockHash, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::AncestorHash, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Ancestor, FIELD_IN | FIELD_OUT | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT>>(ServerCall()))))));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::findCommonAncestor(FindCommonAncestorContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::BlockHash1, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::BlockHash2, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Ancestor, FIELD_IN | FIELD_OUT | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Block1, FIELD_IN | FIELD_OUT | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Block2, FIELD_IN | FIELD_OUT | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT>>(ServerCall()))))))));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::findCoins(FindCoinsContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Coins, FIELD_IN | FIELD_OUT | FIELD_BOXED>>(ServerCall())));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::guessVerificationProgress(GuessVerificationProgressContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::BlockHash, FIELD_IN | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT>>(ServerCall()))));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::hasBlocks(HasBlocksContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::BlockHash, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::MinHeight, FIELD_IN>>(MakeServerField<1, Accessor<chain_fields::MaxHeight, FIELD_IN | FIELD_OPTIONAL>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT>>(ServerCall()))))));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::isRBFOptIn(IsRBFOptInContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Tx, FIELD_IN | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT>>(ServerCall()))));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::isInMempool(IsInMempoolContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Txid, FIELD_IN | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT>>(ServerCall()))));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::hasDescendantsInMempool(HasDescendantsInMempoolContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Txid, FIELD_IN | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT>>(ServerCall()))));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::broadcastTransaction(BroadcastTransactionContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Tx, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::MaxTxFee, FIELD_IN>>(MakeServerField<1, Accessor<chain_fields::Relay, FIELD_IN>>(MakeServerField<1, Accessor<chain_fields::Error, FIELD_OUT | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT>>(ServerCall())))))));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::getTransactionAncestry(GetTransactionAncestryContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Txid, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Ancestors, FIELD_OUT>>(MakeServerField<1, Accessor<chain_fields::Descendants, FIELD_OUT>>(MakeServerField<1, Accessor<chain_fields::Ancestorsize, FIELD_OUT>>(MakeServerField<1, Accessor<chain_fields::Ancestorfees, FIELD_OUT>>(ServerCall())))))));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::calculateIndividualBumpFees(CalculateIndividualBumpFeesContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Outpoints, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::TargetFeerate, FIELD_IN | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT | FIELD_BOXED>>(ServerCall())))));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::calculateCombinedBumpFee(CalculateCombinedBumpFeeContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Outpoints, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::TargetFeerate, FIELD_IN | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT | FIELD_OPTIONAL>>(ServerCall())))));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::getPackageLimits(GetPackageLimitsContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Ancestors, FIELD_OUT>>(MakeServerField<1, Accessor<chain_fields::Descendants, FIELD_OUT>>(ServerCall()))));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::checkChainLimits(CheckChainLimitsContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Tx, FIELD_IN | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT | FIELD_BOXED>>(ServerCall()))));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::estimateSmartFee(EstimateSmartFeeContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::NumBlocks, FIELD_IN>>(MakeServerField<1, Accessor<chain_fields::Conservative, FIELD_IN>>(MakeServerField<1, Accessor<chain_fields::Calc, FIELD_OUT | FIELD_REQUESTED | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT | FIELD_BOXED>>(ServerCall()))))));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::estimateMaxBlocks(EstimateMaxBlocksContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT>>(ServerCall())));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::mempoolMinFee(MempoolMinFeeContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT | FIELD_BOXED>>(ServerCall())));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::relayMinFee(RelayMinFeeContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT | FIELD_BOXED>>(ServerCall())));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::relayIncrementalFee(RelayIncrementalFeeContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT | FIELD_BOXED>>(ServerCall())));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::relayDustFee(RelayDustFeeContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT | FIELD_BOXED>>(ServerCall())));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::havePruned(HavePrunedContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT>>(ServerCall())));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::getPruneHeight(GetPruneHeightContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT | FIELD_OPTIONAL>>(ServerCall())));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::isReadyToBroadcast(IsReadyToBroadcastContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT>>(ServerCall())));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::isInitialBlockDownload(IsInitialBlockDownloadContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT>>(ServerCall())));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::shutdownRequested(ShutdownRequestedContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT>>(ServerCall())));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::initMessage(InitMessageContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Message, FIELD_IN | FIELD_BOXED>>(ServerCall())));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::initWarning(InitWarningContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Message, FIELD_IN | FIELD_BOXED>>(ServerCall())));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::initError(InitErrorContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Message, FIELD_IN | FIELD_BOXED>>(ServerCall())));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::showProgress(ShowProgressContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Title, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Progress, FIELD_IN>>(MakeServerField<1, Accessor<chain_fields::ResumePossible, FIELD_IN>>(ServerCall())))));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::handleNotifications(HandleNotificationsContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Notifications, FIELD_IN | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT | FIELD_BOXED>>(ServerCall()))));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::waitForNotificationsIfTipChanged(WaitForNotificationsIfTipChangedContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::OldTip, FIELD_IN | FIELD_BOXED>>(ServerCall())));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::handleRpc(HandleRpcContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Command, FIELD_IN | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT | FIELD_BOXED>>(ServerCall()))));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::rpcEnableDeprecated(RpcEnableDeprecatedContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Method, FIELD_IN | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT>>(ServerCall()))));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::rpcRunLater(RpcRunLaterContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Name, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Fn, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Seconds, FIELD_IN>>(ServerCall())))));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::getSetting(GetSettingContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Name, FIELD_IN | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT | FIELD_BOXED>>(ServerCall()))));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::getSettingsList(GetSettingsListContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Name, FIELD_IN | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT | FIELD_BOXED>>(ServerCall()))));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::getRwSetting(GetRwSettingContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Name, FIELD_IN | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT | FIELD_BOXED>>(ServerCall()))));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::updateRwSetting(UpdateRwSettingContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Name, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Update, FIELD_IN | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT>>(ServerCall())))));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::overwriteRwSetting(OverwriteRwSettingContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Name, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Value, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Action, FIELD_IN>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT>>(ServerCall()))))));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::deleteRwSettings(DeleteRwSettingsContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Name, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Action, FIELD_IN>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT>>(ServerCall())))));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::requestMempoolTransactions(RequestMempoolTransactionsContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Notifications, FIELD_IN | FIELD_BOXED>>(ServerCall())));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Chain>::hasAssumedValidChain(HasAssumedValidChainContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT>>(ServerCall())));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::ChainNotifications>::destroy(DestroyContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(ServerDestroy()));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::ChainNotifications>::transactionAddedToMempool(TransactionAddedToMempoolContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Tx, FIELD_IN | FIELD_BOXED>>(ServerCall())));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::ChainNotifications>::transactionRemovedFromMempool(TransactionRemovedFromMempoolContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Tx, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Reason, FIELD_IN>>(ServerCall()))));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::ChainNotifications>::blockConnected(BlockConnectedContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Role, FIELD_IN>>(MakeServerField<1, Accessor<chain_fields::Block, FIELD_IN | FIELD_BOXED>>(ServerCall()))));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::ChainNotifications>::blockDisconnected(BlockDisconnectedContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Block, FIELD_IN | FIELD_BOXED>>(ServerCall())));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::ChainNotifications>::updatedBlockTip(UpdatedBlockTipContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(ServerCall()));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::ChainNotifications>::chainStateFlushed(ChainStateFlushedContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Role, FIELD_IN>>(MakeServerField<1, Accessor<chain_fields::Locator, FIELD_IN | FIELD_BOXED>>(ServerCall()))));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::ChainClient>::destroy(DestroyContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(ServerDestroy()));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::ChainClient>::registerRpcs(RegisterRpcsContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(ServerCall()));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::ChainClient>::verify(VerifyContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT>>(ServerCall())));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::ChainClient>::load(LoadContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT>>(ServerCall())));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::ChainClient>::start(StartContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Scheduler, FIELD_IN>>(ServerCall())));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::ChainClient>::flush(FlushContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(ServerCall()));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::ChainClient>::stop(StopContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(ServerCall()));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::ChainClient>::setMockTime(SetMockTimeContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Time, FIELD_IN>>(ServerCall())));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::ChainClient>::schedulerMockForward(SchedulerMockForwardContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Time, FIELD_IN>>(ServerCall())));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::ActorCallback>::call(CallContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Request, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Response, FIELD_IN | FIELD_OUT | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::LastCallback, FIELD_IN>>(Make<ServerExcept, std::exception, Accessor<chain_fields::Error, FIELD_OUT | FIELD_BOXED>>(Make<ServerExcept, UniValue, Accessor<chain_fields::RpcError, FIELD_OUT | FIELD_BOXED>>(Make<ServerExcept, UniValue::type_error, Accessor<chain_fields::TypeError, FIELD_OUT | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT>>(ServerCall())))))))));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::RunLaterCallback>::destroy(DestroyContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(ServerDestroy()));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::RunLaterCallback>::call(CallContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(ServerCall()));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::SettingsUpdateCallback>::destroy(DestroyContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(ServerDestroy()));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::SettingsUpdateCallback>::call(CallContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<chain_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<chain_fields::Value, FIELD_IN | FIELD_OUT | FIELD_BOXED>>(Make<ServerRet, Accessor<chain_fields::Result, FIELD_OUT | FIELD_OPTIONAL>>(ServerCall()))));
}
} // namespace mp
