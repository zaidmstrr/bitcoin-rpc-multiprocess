#include "../../include/http_server.h"
#include "../../include/rpc_interface.h"
#include <iostream>
#include <stdexcept>
#include <capnp/rpc-twoparty.h>
#include "../ipc/init.capnp.h"

BitcoinHttpServer::BitcoinHttpServer(const std::string& bitcoin_socket_path, 
                     const std::string& bind_address, int port) 
    : ioContext(kj::setupAsyncIo()) {
    
    base = event_base_new();
    if (!base) {
        throw std::runtime_error("Failed to create event base");
    }
    
    setupCapnpClient(bitcoin_socket_path);
    setupHttpServer(bind_address, port);
    
    std::cout << "Bitcoin HTTP Server listening on " << bind_address << ":" << port << std::endl;
}

BitcoinHttpServer::~BitcoinHttpServer() {
    if (http) evhttp_free(http);
    if (base) event_base_free(base);
}

UniValue BitcoinHttpServer::processMethod(const std::string& method, const UniValue& params) {
    UniValue response(UniValue::VOBJ);
    
    try {
        if (method == "getblockhash") {
            // Check if height parameter exists
            if (params.size() < 1 || !params[0].isNum()) {
                UniValue error(UniValue::VOBJ);
                error.pushKV("code", -32602);
                error.pushKV("message", "Invalid params: height must be an integer");
                response.pushKV("error", error);
                return response;
            }
            
            int32_t height = params[0].get_int();
            std::string blockHash = rpcInterface->getBlockHash(height, ioContext.waitScope);
            
            response.pushKV("result", blockHash);
            
        } else if (method == "initmessage") {
            // Check if message parameter exists
            if (params.size() < 1 || !params[0].isStr()) {
                UniValue error(UniValue::VOBJ);
                error.pushKV("code", -32602);
                error.pushKV("message", "Invalid params: message must be a string");
                response.pushKV("error", error);
                return response;
            }
            
            std::string message = params[0].get_str();
            bool success = rpcInterface->sendInitMessage(message, ioContext.waitScope);
            
            if (success) {
                response.pushKV("result", "Message sent successfully");
            } else {
                UniValue error(UniValue::VOBJ);
                error.pushKV("code", -32000);
                error.pushKV("message", "Failed to send init message");
                response.pushKV("error", error);
            }
            
        } else {
            UniValue error(UniValue::VOBJ);
            error.pushKV("code", -32601);
            error.pushKV("message", "Method not found: " + method);
            response.pushKV("error", error);
        }
    } catch (const kj::Exception& e) {
        UniValue error(UniValue::VOBJ);
        error.pushKV("code", -32603);
        error.pushKV("message", std::string("Internal error: ") + e.getDescription().cStr());
        response.pushKV("error", error);
    } catch (const std::exception& e) {
        UniValue error(UniValue::VOBJ);
        error.pushKV("code", -32603);
        error.pushKV("message", std::string("Internal error: ") + e.what());
        response.pushKV("error", error);
    }
    
    return response;
}

void BitcoinHttpServer::setupCapnpClient(const std::string& bitcoin_socket_path) {
    auto& waitScope = ioContext.waitScope;
    std::string socketPath = bitcoin_socket_path;
    
    if (socketPath.substr(0, 5) != "unix:" && socketPath.find('/') != std::string::npos) {
        socketPath = "unix:" + socketPath;
    }
    
    std::cout << "Connecting to socket: " << socketPath << std::endl;
    auto networkAddress = ioContext.provider->getNetwork().parseAddress(socketPath.c_str()).wait(waitScope);
    socket = networkAddress->connect().wait(waitScope);
    
    client = kj::heap<capnp::TwoPartyClient>(*socket);
    auto initClient = client->bootstrap().castAs<ipc::capnp::messages::Init>();
    
    // Get ThreadMap capability
    auto constructReq = initClient.constructRequest();
    auto constructResponse = constructReq.send().wait(waitScope);
    if (!constructResponse.hasThreadMap()) {
        throw std::runtime_error("No ThreadMap capability received.");
    }
    auto threadMap = constructResponse.getThreadMap();
    
    // Create ThreadClient
    auto makeThreadReq = threadMap.makeThreadRequest();
    auto makeThreadResponse = makeThreadReq.send().wait(waitScope);
    if (!makeThreadResponse.hasResult()) {
        throw std::runtime_error("No Thread capability received.");
    }
    auto thread = makeThreadResponse.getResult();
    
    // Create ChainClient
    auto makeChainReq = initClient.makeChainRequest();
    makeChainReq.getContext().setThread(thread);
    auto makeChainResponse = makeChainReq.send().wait(waitScope);
    if (!makeChainResponse.hasResult()) {
        throw std::runtime_error("No Chain capability received.");
    }
    auto chainInterface = makeChainResponse.getResult();
    
    rpcInterface = std::make_unique<RpcInterface>(threadMap, thread, chainInterface);
}

void BitcoinHttpServer::setupHttpServer(const std::string& bind_address, int port) {
    http = evhttp_new(base);
    if (!http) {
        event_base_free(base);
        throw std::runtime_error("Failed to create HTTP server");
    }
    
    evhttp_set_gencb(http, handleRequest, this);
    
    if (evhttp_bind_socket(http, bind_address.c_str(), port) != 0) {
        evhttp_free(http);
        event_base_free(base);
        throw std::runtime_error("Failed to bind to socket");
    }
}

void BitcoinHttpServer::respondWithJson(struct evhttp_request* req, const UniValue& response) {
    std::string response_str = response.write();
    
    struct evbuffer* buffer = evbuffer_new();
    if (!buffer) {
        evhttp_send_error(req, HTTP_INTERNAL, "Internal Server Error");
        return;
    }
    
    evbuffer_add(buffer, response_str.c_str(), response_str.size());
    evhttp_send_reply(req, HTTP_OK, "OK", buffer);
    evbuffer_free(buffer);
}

void BitcoinHttpServer::processRequest(struct evhttp_request* req) {
    // Set response headers
    struct evkeyvalq* headers = evhttp_request_get_output_headers(req);
    evhttp_add_header(headers, "Content-Type", "application/json");
    evhttp_add_header(headers, "Access-Control-Allow-Origin", "*");
    
    // Handle OPTIONS for CORS
    if (evhttp_request_get_command(req) == EVHTTP_REQ_OPTIONS) {
        evhttp_add_header(headers, "Access-Control-Allow-Methods", "POST, OPTIONS");
        evhttp_add_header(headers, "Access-Control-Allow-Headers", "Content-Type");
        evhttp_send_reply(req, 200, "OK", nullptr);
        return;
    }
    
    // Only accept POST requests
    if (evhttp_request_get_command(req) != EVHTTP_REQ_POST) {
        UniValue error(UniValue::VOBJ);
        error.pushKV("code", -32600);
        error.pushKV("message", "Only POST requests are accepted");
        
        UniValue response(UniValue::VOBJ);
        response.pushKV("error", error);
        response.pushKV("result", UniValue(UniValue::VNULL));
        response.pushKV("id", UniValue(UniValue::VNULL));
        
        respondWithJson(req, response);
        return;
    }
    
    // Get request body
    struct evbuffer* input_buffer = evhttp_request_get_input_buffer(req);
    size_t len = evbuffer_get_length(input_buffer);
    
    if (len == 0) {
        UniValue error(UniValue::VOBJ);
        error.pushKV("code", -32700);
        error.pushKV("message", "Parse error: empty request");
        
        UniValue response(UniValue::VOBJ);
        response.pushKV("error", error);
        response.pushKV("result", UniValue(UniValue::VNULL));
        response.pushKV("id", UniValue(UniValue::VNULL));
        
        respondWithJson(req, response);
        return;
    }
    
    // Read the request body
    std::unique_ptr<char[]> request_data(new char[len + 1]);
    evbuffer_remove(input_buffer, request_data.get(), len);
    request_data[len] = '\0';
    
    // Parse the JSON request
    UniValue request;
    try {
        if (!request.read(request_data.get()) || !request.isObject()) {
            UniValue error(UniValue::VOBJ);
            error.pushKV("code", -32700);
            error.pushKV("message", "Parse error: invalid JSON");
            
            UniValue response(UniValue::VOBJ);
            response.pushKV("error", error);
            response.pushKV("result", UniValue(UniValue::VNULL));
            response.pushKV("id", UniValue(UniValue::VNULL));
            
            respondWithJson(req, response);
            return;
        }
    } catch (const std::exception& e) {
        UniValue error(UniValue::VOBJ);
        error.pushKV("code", -32700);
        error.pushKV("message", std::string("Parse error: ") + e.what());
        
        UniValue response(UniValue::VOBJ);
        response.pushKV("error", error);
        response.pushKV("result", UniValue(UniValue::VNULL));
        response.pushKV("id", UniValue(UniValue::VNULL));
        
        respondWithJson(req, response);
        return;
    }
    
    // Verify the JSON-RPC request
    if (!request.exists("method") || !request["method"].isStr()) {
        UniValue error(UniValue::VOBJ);
        error.pushKV("code", -32600);
        error.pushKV("message", "Invalid Request: missing or invalid method");
        
        UniValue response(UniValue::VOBJ);
        response.pushKV("error", error);
        response.pushKV("result", UniValue(UniValue::VNULL));
        response.pushKV("id", request.exists("id") ? request["id"] : UniValue(UniValue::VNULL));
        
        respondWithJson(req, response);
        return;
    }
    
    std::string method = request["method"].get_str();
    UniValue params = request.exists("params") ? request["params"] : UniValue(UniValue::VARR);
    UniValue id = request.exists("id") ? request["id"] : UniValue(UniValue::VNULL);
    
    // Process the request based on the method
    UniValue response(UniValue::VOBJ);
    try {
        response = processMethod(method, params);
        response.pushKV("id", id);
    } catch (const std::exception& e) {
        UniValue error(UniValue::VOBJ);
        error.pushKV("code", -32603);
        error.pushKV("message", std::string("Internal error: ") + e.what());
        
        response.pushKV("error", error);
        response.pushKV("result", UniValue(UniValue::VNULL));
        response.pushKV("id", id);
    }
    
    // Send the response
    respondWithJson(req, response);
}

void BitcoinHttpServer::handleRequest(struct evhttp_request* req, void* arg) {
    BitcoinHttpServer* server = static_cast<BitcoinHttpServer*>(arg);
    server->processRequest(req);
}

// Run the event loop in the current thread
void BitcoinHttpServer::run() {
    event_base_dispatch(base);
}
