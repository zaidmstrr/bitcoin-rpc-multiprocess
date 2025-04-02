// Generated by mpgen from /home/zaidmstrr/bitcoin/src/ipc/capnp/echo.capnp

#include <src/ipc/capnp/echo.capnp.proxy-types.h>
#include <mp/proxy-types.h>

namespace mp {
kj::Promise<void> ProxyServer<ipc::capnp::messages::Echo>::destroy(DestroyContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<echo_fields::Context, FIELD_IN | FIELD_BOXED>>(ServerDestroy()));
}
kj::Promise<void> ProxyServer<ipc::capnp::messages::Echo>::echo(EchoContext call_context) {
    return serverInvoke(*this, call_context, MakeServerField<0, Accessor<echo_fields::Context, FIELD_IN | FIELD_BOXED>>(MakeServerField<1, Accessor<echo_fields::Echo, FIELD_IN | FIELD_BOXED>>(Make<ServerRet, Accessor<echo_fields::Result, FIELD_OUT | FIELD_BOXED>>(ServerCall()))));
}
} // namespace mp
