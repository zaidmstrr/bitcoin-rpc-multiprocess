// Generated by mpgen from /home/zaidmstrr/bitcoin/src/ipc/capnp/chain.capnp

#include <src/ipc/capnp/chain.capnp.proxy-types.h>
#include <mp/proxy-types.h>

namespace mp {
ProxyClient<ipc::capnp::messages::Chain>::~ProxyClient() { clientDestroy(*this);  }
ProxyServer<ipc::capnp::messages::Chain>::~ProxyServer() { serverDestroy(*this); }
ProxyClient<ipc::capnp::messages::ChainNotifications>::~ProxyClient() { clientDestroy(*this);  }
ProxyServer<ipc::capnp::messages::ChainNotifications>::~ProxyServer() { serverDestroy(*this); }
ProxyClient<ipc::capnp::messages::ChainClient>::~ProxyClient() { clientDestroy(*this);  }
ProxyServer<ipc::capnp::messages::ChainClient>::~ProxyServer() { serverDestroy(*this); }
ProxyClient<ipc::capnp::messages::ActorCallback>::~ProxyClient() { clientDestroy(*this);  }
ProxyServer<ipc::capnp::messages::ActorCallback>::~ProxyServer() { serverDestroy(*this); }
ProxyClient<ipc::capnp::messages::RunLaterCallback>::~ProxyClient() { clientDestroy(*this);  }
ProxyServer<ipc::capnp::messages::RunLaterCallback>::~ProxyServer() { serverDestroy(*this); }
ProxyClient<ipc::capnp::messages::SettingsUpdateCallback>::~ProxyClient() { clientDestroy(*this);  }
ProxyServer<ipc::capnp::messages::SettingsUpdateCallback>::~ProxyServer() { serverDestroy(*this); }
} // namespace mp
