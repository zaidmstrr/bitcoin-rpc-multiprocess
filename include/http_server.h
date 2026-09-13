#ifndef HTTP_SERVER_H
#define HTTP_SERVER_H

#include <event2/event.h>
#include <event2/http.h>
#include <event2/buffer.h>
#include <event2/util.h>
#include <memory>
#include <string>

class IpcThread;

class BitcoinHttpServer {
public:
    BitcoinHttpServer(const std::string& bitcoinSocketPath,
                      const std::string& bindAddress, int port);
    ~BitcoinHttpServer();

    void run();

private:
    struct event_base* base{nullptr};
    struct evhttp* http{nullptr};
    std::unique_ptr<IpcThread> ipcThread;

    // Max body size accepted before the request is rejected.
    static constexpr size_t kMaxBodyBytes = 4u * 1024u * 1024u;

    void setupHttpServer(const std::string& bindAddress, int port);

    static void handleRequest(struct evhttp_request* req, void* arg);
    void processRequest(struct evhttp_request* req);
};

#endif // HTTP_SERVER_H