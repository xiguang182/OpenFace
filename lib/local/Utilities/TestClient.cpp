#include <iostream>
#include <WinSock2.h>
#include <ws2tcpip.h>


#pragma comment(lib, "ws2_32.lib")

#include <nlohmann\json.hpp>

using json = nlohmann::json;

void test11() {
	json data;
	// create an empty structure (null)
	json j;

	// add a number that is stored as double (note the implicit conversion of j to an object)
	j["pi"] = 3.141;

	// add a Boolean that is stored as bool
	j["happy"] = true;

	// add a string that is stored as std::string
	j["name"] = "Niels";

	// add another null object by passing nullptr
	j["nothing"] = nullptr;

	// add an object inside the object
	j["answer"]["everything"] = 42;

	// add an array that is stored as std::vector (using an initializer list)
	j["list"] = { 1, 0, 2 };

	// add another object (using an initializer list of pairs)
	j["object"] = { {"currency", "USD"}, {"value", 42.99} };

	// instead, you could also write (which looks very similar to the JSON above)
	json j2 = {
	  {"pi", 3.141},
	  {"happy", true},
	  {"name", "Niels"},
	  {"nothing", nullptr},
	  {"answer", {
		{"everything", 42}
	  }},
	  {"list", {1, 0, 2}},
	  {"object", {
		{"currency", "USD"},
		{"value", 42.99}
	  }}
	};
	return;
}

/*std::stringstream tmp;
tmp << "[" << this->pdm_params_global[0];
for (int i = 1; i < 6; ++i)
{
	tmp << "," << this->pdm_params_global[i];
}
tmp << "]";
j2["pdm_params_global"] = tmp.str();*/

//int test() {
//    // Initialize Winsock
//    WSADATA wsaData;
//    if (WSAStartup(MAKEWORD(2, 2), &wsaData) != 0) {
//        std::cerr << "Failed to initialize Winsock" << std::endl;
//        return -1;
//    }
//
//    // Create a socket
//    SOCKET clientSocket = socket(AF_INET, SOCK_STREAM, 0);
//    if (clientSocket == INVALID_SOCKET) {
//        std::cerr << "Error creating socket" << std::endl;
//        WSACleanup();
//        return -1;
//    }
//
//    // Server address and port
//    sockaddr_in serverAddress;
//    serverAddress.sin_family = AF_INET;
//    serverAddress.sin_port = htons(8080);  // Change this to your server port
//    inet_pton(AF_INET, "127.0.0.1", &serverAddress.sin_addr);  // Change this to your server IP address
//
//    // Connect to the server
//    if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) == SOCKET_ERROR) {
//        std::cerr << "Error connecting to server" << std::endl;
//        closesocket(clientSocket);
//        WSACleanup();
//        return -1;
//    }
//
//    // Send data to the server
//    const char* message = "Hello, server!";
//    if (send(clientSocket, message, strlen(message), 0) == SOCKET_ERROR) {
//        std::cerr << "Error sending data" << std::endl;
//        closesocket(clientSocket);
//        WSACleanup();
//        return -1;
//    }
//
//    // Close the socket
//    closesocket(clientSocket);
//    WSACleanup();
//
//    return 0;
//}

// Define a wrapper function for cross-platform compatibility
//int _inet_pton(int af, const char* src, void* dst) {
//    if (af == AF_INET) {
//        // For IPv4
//        sockaddr_in sa;
//        int result = inet_pton(af, src, &(sa.sin_addr));
//        if (result == 1) {
//            // Copy the binary address to the destination
//            std::memcpy(dst, &(sa.sin_addr), sizeof(sa.sin_addr));
//        }
//        return result;
//    }
//    else if (af == AF_INET6) {
//        // For IPv6
//        sockaddr_in6 sa;
//        int result = inet_pton(af, src, &(sa.sin6_addr));
//        if (result == 1) {
//            // Copy the binary address to the destination
//            std::memcpy(dst, &(sa.sin6_addr), sizeof(sa.sin6_addr));
//        }
//        return result;
//    }
//    else {
//        // Unsupported address family
//        return -1;
//    }
//}
