#include "../../include/http_server.h"
#include <iostream>
#include <string>

int main(int argc, char** argv) {
    try {
        std::string bitcoin_socket_path = "/tmp/bitcoin-ipc.sock";
        std::string bind_address = "127.0.0.1";
        int port = 8332;
        
        // Parse command line arguments
        for (int i = 1; i < argc; i += 2) {
            if (i + 1 >= argc) {
                std::cerr << "Missing value for argument: " << argv[i] << std::endl;
                return 1;
            }
            
            std::string arg = argv[i];
            std::string value = argv[i + 1];
            
            if (arg == "--socket" || arg == "-s") {
                bitcoin_socket_path = value;
            } else if (arg == "--address" || arg == "-a") {
                bind_address = value;
            } else if (arg == "--port" || arg == "-p") {
                port = std::stoi(value);
            } else {
                std::cerr << "Unknown argument: " << arg << std::endl;
                return 1;
            }
        }
        
        std::cout << "Starting Bitcoin HTTP Server..." << std::endl;
        std::cout << "Bitcoin Socket: " << bitcoin_socket_path << std::endl;
        std::cout << "Binding to: " << bind_address << ":" << port << std::endl;
        
        BitcoinHttpServer server(bitcoin_socket_path, bind_address, port);
        server.run();
        
        return 0;
        
    } catch (const kj::Exception& e) {
        std::cerr << "KJ Exception: " << e.getDescription().cStr() << std::endl;
        return 1;
    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
}