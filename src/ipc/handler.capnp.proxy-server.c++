// Generated by mpgen from /home/zaidmstrr/bitcoin/src/ipc/capnp/handler.capnp

#include <src/ipc/capnp/handler.capnp.proxy-types.h>
#include <mp/proxy-types.h>

namespace mp {
kj::Promise<void> ProxyServer<ipc::capnp::messages::Handler>::destroy(DestroyContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<handler_fields::Context, FIELD_IN | FIELD_BOXED>>(ServerDestroy()));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Handler>::disconnect(DisconnectContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<handler_fields::Context, FIELD_IN | FIELD_BOXED>>(ServerCall()));
}
} // namespace mp
