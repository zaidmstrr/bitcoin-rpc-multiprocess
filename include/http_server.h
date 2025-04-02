#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H

#include <event2/event.h>
#include <event2/http.h>
#include <event2/buffer.h>
#include <event2/util.h>
#include <event2/keyvalq_struct.h>
#include <univalue.h>
#include <memory>
#include <kj/async-io.h>
#include <capnp/rpc-twoparty.h>

class RpcInterface;

class BitcoinHttpServer {
private:
    struct event_base* base;
    struct evhttp* http;
    std::unique_ptr<RpcInterface> rpcInterface;
    kj::AsyncIoContext ioContext;
    kj::Own<kj::AsyncIoStream> socket;
    kj::Own<capnp::TwoPartyClient> client;
    
    void setupCapnpClient(const std::string& bitcoin_socket_path);
    void setupHttpServer(const std::string& bind_address, int port);
    void respondWithJson(struct evhttp_request* req, const UniValue& response);
    UniValue processMethod(const std::string& method, const UniValue& params);
    
public:
    BitcoinHttpServer(const std::string& bitcoin_socket_path, 
                     const std::string& bind_address, int port);
    ~BitcoinHttpServer();
    
    void start();
    void run();
    
    // Make sure these are properly declared
    static void handleRequest(struct evhttp_request* req, void* arg);
    void processRequest(struct evhttp_request* req);
};

#endif // HTTP_SERVER_H