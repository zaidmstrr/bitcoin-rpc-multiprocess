// Generated by mpgen from /home/zaidmstrr/bitcoin/src/ipc/capnp/common.capnp

#ifndef CAPNP_COMMON_CAPNP_PROXY_H
#define CAPNP_COMMON_CAPNP_PROXY_H

#include <common.capnp.h>
#include <mp/proxy.h>

#if defined(__GNUC__)
#pragma GCC diagnostic push
#if !defined(__has_warning)
#pragma GCC diagnostic ignored "-Wsuggest-override"
#elif __has_warning("-Wsuggest-override")
#pragma GCC diagnostic ignored "-Wsuggest-override"
#endif
#endif
namespace mp {
namespace common_fields {
struct Hash
{
    template<typename S> static auto get(S&& s) -> decltype(s.getHash()) { return s.getHash(); }
    template<typename S> static bool has(S&& s) { return s.hasHash(); }
    template<typename S, typename A> static void set(S&& s, A&& a) { s.setHash(std::forward<A>(a)); }
    template<typename S, typename... A> static decltype(auto) init(S&& s, A&&... a) { return s.initHash(std::forward<A>(a)...); }
    template<typename S> static bool getWant(S&& s) { return s.getWantHash(); }
    template<typename S> static void setWant(S&& s) { s.setWantHash(true); }
    template<typename S> static bool getHas(S&& s) { return s.getHasHash(); }
    template<typename S> static void setHas(S&& s) { s.setHasHash(true); }
};
struct Height
{
    template<typename S> static auto get(S&& s) -> decltype(s.getHeight()) { return s.getHeight(); }
    template<typename S> static bool has(S&& s) { return s.hasHeight(); }
    template<typename S, typename A> static void set(S&& s, A&& a) { s.setHeight(std::forward<A>(a)); }
    template<typename S, typename... A> static decltype(auto) init(S&& s, A&&... a) { return s.initHeight(std::forward<A>(a)...); }
    template<typename S> static bool getWant(S&& s) { return s.getWantHeight(); }
    template<typename S> static void setWant(S&& s) { s.setWantHeight(true); }
    template<typename S> static bool getHas(S&& s) { return s.getHasHeight(); }
    template<typename S> static void setHas(S&& s) { s.setHasHeight(true); }
};
struct Original
{
    template<typename S> static auto get(S&& s) -> decltype(s.getOriginal()) { return s.getOriginal(); }
    template<typename S> static bool has(S&& s) { return s.hasOriginal(); }
    template<typename S, typename A> static void set(S&& s, A&& a) { s.setOriginal(std::forward<A>(a)); }
    template<typename S, typename... A> static decltype(auto) init(S&& s, A&&... a) { return s.initOriginal(std::forward<A>(a)...); }
    template<typename S> static bool getWant(S&& s) { return s.getWantOriginal(); }
    template<typename S> static void setWant(S&& s) { s.setWantOriginal(true); }
    template<typename S> static bool getHas(S&& s) { return s.getHasOriginal(); }
    template<typename S> static void setHas(S&& s) { s.setHasOriginal(true); }
};
struct Translated
{
    template<typename S> static auto get(S&& s) -> decltype(s.getTranslated()) { return s.getTranslated(); }
    template<typename S> static bool has(S&& s) { return s.hasTranslated(); }
    template<typename S, typename A> static void set(S&& s, A&& a) { s.setTranslated(std::forward<A>(a)); }
    template<typename S, typename... A> static decltype(auto) init(S&& s, A&&... a) { return s.initTranslated(std::forward<A>(a)...); }
    template<typename S> static bool getWant(S&& s) { return s.getWantTranslated(); }
    template<typename S> static void setWant(S&& s) { s.setWantTranslated(true); }
    template<typename S> static bool getHas(S&& s) { return s.getHasTranslated(); }
    template<typename S> static void setHas(S&& s) { s.setHasTranslated(true); }
};
struct Value
{
    template<typename S> static auto get(S&& s) -> decltype(s.getValue()) { return s.getValue(); }
    template<typename S> static bool has(S&& s) { return s.hasValue(); }
    template<typename S, typename A> static void set(S&& s, A&& a) { s.setValue(std::forward<A>(a)); }
    template<typename S, typename... A> static decltype(auto) init(S&& s, A&&... a) { return s.initValue(std::forward<A>(a)...); }
    template<typename S> static bool getWant(S&& s) { return s.getWantValue(); }
    template<typename S> static void setWant(S&& s) { s.setWantValue(true); }
    template<typename S> static bool getHas(S&& s) { return s.getHasValue(); }
    template<typename S> static void setHas(S&& s) { s.setHasValue(true); }
};
struct Error
{
    template<typename S> static auto get(S&& s) -> decltype(s.getError()) { return s.getError(); }
    template<typename S> static bool has(S&& s) { return s.hasError(); }
    template<typename S, typename A> static void set(S&& s, A&& a) { s.setError(std::forward<A>(a)); }
    template<typename S, typename... A> static decltype(auto) init(S&& s, A&&... a) { return s.initError(std::forward<A>(a)...); }
    template<typename S> static bool getWant(S&& s) { return s.getWantError(); }
    template<typename S> static void setWant(S&& s) { s.setWantError(true); }
    template<typename S> static bool getHas(S&& s) { return s.getHasError(); }
    template<typename S> static void setHas(S&& s) { s.setHasError(true); }
};
struct Key
{
    template<typename S> static auto get(S&& s) -> decltype(s.getKey()) { return s.getKey(); }
    template<typename S> static bool has(S&& s) { return s.hasKey(); }
    template<typename S, typename A> static void set(S&& s, A&& a) { s.setKey(std::forward<A>(a)); }
    template<typename S, typename... A> static decltype(auto) init(S&& s, A&&... a) { return s.initKey(std::forward<A>(a)...); }
    template<typename S> static bool getWant(S&& s) { return s.getWantKey(); }
    template<typename S> static void setWant(S&& s) { s.setWantKey(true); }
    template<typename S> static bool getHas(S&& s) { return s.getHasKey(); }
    template<typename S> static void setHas(S&& s) { s.setHasKey(true); }
};
} // namespace common_fields
template<>
struct ProxyStruct<ipc::capnp::messages::BlockRef>
{
    using Struct = ipc::capnp::messages::BlockRef;
    using HashAccessor = Accessor<common_fields::Hash, FIELD_IN | FIELD_OUT | FIELD_BOXED>;
    using HeightAccessor = Accessor<common_fields::Height, FIELD_IN | FIELD_OUT>;
    using Accessors = std::tuple<HashAccessor, HeightAccessor>;
    static constexpr size_t fields = 2;
};
template<>
struct ProxyStruct<ipc::capnp::messages::BilingualStr>
{
    using Struct = ipc::capnp::messages::BilingualStr;
    using OriginalAccessor = Accessor<common_fields::Original, FIELD_IN | FIELD_OUT | FIELD_BOXED>;
    using TranslatedAccessor = Accessor<common_fields::Translated, FIELD_IN | FIELD_OUT | FIELD_BOXED>;
    using Accessors = std::tuple<OriginalAccessor, TranslatedAccessor>;
    static constexpr size_t fields = 2;
};
template<typename Value>
struct ProxyStruct<ipc::capnp::messages::Result<Value>>
{
    using Struct = ipc::capnp::messages::Result<Value>;
    using ValueAccessor = Accessor<common_fields::Value, FIELD_IN | FIELD_OUT | FIELD_BOXED>;
    using ErrorAccessor = Accessor<common_fields::Error, FIELD_IN | FIELD_OUT | FIELD_BOXED>;
    using Accessors = std::tuple<ValueAccessor, ErrorAccessor>;
    static constexpr size_t fields = 2;
};
template<typename Value>
struct ProxyStruct<ipc::capnp::messages::ResultVoid<Value>>
{
    using Struct = ipc::capnp::messages::ResultVoid<Value>;
    using ErrorAccessor = Accessor<common_fields::Error, FIELD_IN | FIELD_OUT | FIELD_BOXED>;
    using Accessors = std::tuple<ErrorAccessor>;
    static constexpr size_t fields = 1;
};
template<typename Key, typename Value>
struct ProxyStruct<ipc::capnp::messages::Pair<Key, Value>>
{
    using Struct = ipc::capnp::messages::Pair<Key, Value>;
    using KeyAccessor = Accessor<common_fields::Key, FIELD_IN | FIELD_OUT | FIELD_BOXED>;
    using ValueAccessor = Accessor<common_fields::Value, FIELD_IN | FIELD_OUT | FIELD_BOXED>;
    using Accessors = std::tuple<KeyAccessor, ValueAccessor>;
    static constexpr size_t fields = 2;
};
template<typename Key>
struct ProxyStruct<ipc::capnp::messages::PairInt64<Key>>
{
    using Struct = ipc::capnp::messages::PairInt64<Key>;
    using KeyAccessor = Accessor<common_fields::Key, FIELD_IN | FIELD_OUT | FIELD_BOXED>;
    using ValueAccessor = Accessor<common_fields::Value, FIELD_IN | FIELD_OUT>;
    using Accessors = std::tuple<KeyAccessor, ValueAccessor>;
    static constexpr size_t fields = 2;
};
} // namespace mp
#if defined(__GNUC__)
#pragma GCC diagnostic pop
#endif
#endif
