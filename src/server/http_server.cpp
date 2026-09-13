#include "../../include/http_server.h"
#include "../../include/ipc_thread.h"
#include <event2/keyvalq_struct.h>
#include <event2/thread.h>
#include <iostream>
#include <stdexcept>
#include <string>

// Initialises the libevent base, connects the KJ/IPC thread, and binds the HTTP listener.
BitcoinHttpServer::BitcoinHttpServer(const std::string& bitcoinSocketPath,
                                     const std::string& bindAddress, int port) {
    evthread_use_pthreads(); // must precede event_base_new()
    base = event_base_new();
    if (!base) throw std::runtime_error("Failed to create event base");
    evthread_make_base_notifiable(base); // lets event_base_once wake us from the KJ thread

    // Blocks until the KJ thread has connected to bitcoin-node.
    ipcThread = std::make_unique<IpcThread>(bitcoinSocketPath);

    setupHttpServer(bindAddress, port);
}

// Joins the KJ thread before freeing the event base to avoid use-after-free.
BitcoinHttpServer::~BitcoinHttpServer() {
    ipcThread.reset(); // join KJ thread before freeing the event base
    if (http) evhttp_free(http);
    if (base) event_base_free(base);
}

// Creates the evhttp instance, registers the catch-all callback, and binds the socket.
void BitcoinHttpServer::setupHttpServer(const std::string& bindAddress, int port) {
    http = evhttp_new(base);
    if (!http) {
        event_base_free(base);
        throw std::runtime_error("Failed to create HTTP server");
    }
    evhttp_set_gencb(http, handleRequest, this);
    if (evhttp_bind_socket(http, bindAddress.c_str(), port) != 0) {
        evhttp_free(http);
        event_base_free(base);
        throw std::runtime_error("Failed to bind to " + bindAddress + ":" + std::to_string(port));
    }
}

// Validates the request, reads the body, and hands ownership to the KJ thread.
void BitcoinHttpServer::processRequest(struct evhttp_request* req) {
    if (evhttp_request_get_command(req) != EVHTTP_REQ_POST) {
        evhttp_send_error(req, HTTP_BADMETHOD, "Only POST accepted");
        return;
    }

    struct evbuffer* inputBuf = evhttp_request_get_input_buffer(req);
    size_t len = evbuffer_get_length(inputBuf);

    if (len == 0) {
        evhttp_send_error(req, HTTP_BADREQUEST, "Empty body");
        return;
    }
    if (len > kMaxBodyBytes) {
        evhttp_send_error(req, HTTP_BADREQUEST, "Request body too large");
        return;
    }

    std::string body(len, '\0');
    evbuffer_remove(inputBuf, body.data(), len);

    // Transfer ownership to us; the response will arrive asynchronously via
    // event_base_once() from the IPC thread.
    evhttp_request_own(req);
    ipcThread->submit({req, std::move(body), base});
}

// Static libevent callback; delegates to processRequest on the owning server instance.
void BitcoinHttpServer::handleRequest(struct evhttp_request* req, void* arg) {
    static_cast<BitcoinHttpServer*>(arg)->processRequest(req);
}

// Runs the libevent dispatch loop until event_base_loopbreak() is called.
void BitcoinHttpServer::run() {
    event_base_dispatch(base);
}
