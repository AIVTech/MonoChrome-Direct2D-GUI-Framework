#include "TcpServer.h"

TcpServer::TcpServer()
{
}

TcpServer::~TcpServer()
{
}

Socket& TcpServer::Listen(int port)
{
	Socket* resultingSocket(NULL);
	WSADATA wsaData;
	int iResult;

	SOCKET ListenSocket = INVALID_SOCKET;
	SOCKET ClientSocket = INVALID_SOCKET;

	struct addrinfo *result = NULL;
	struct addrinfo hints;

	// Initialize Winsock
	iResult = WSAStartup(MAKEWORD(2, 2), &wsaData);
	if (iResult != 0) {
		return *resultingSocket;
	}

	ZeroMemory(&hints, sizeof(hints));
	hints.ai_family = AF_INET;
	hints.ai_socktype = SOCK_STREAM;		// SOCK_DGRAM for UDP and SOCK_STREAM for TCP
	hints.ai_protocol = IPPROTO_TCP;		// tcp socket
	hints.ai_flags = AI_PASSIVE;

	// Resolve the server address and port
	iResult = getaddrinfo(NULL, std::to_string(port).c_str(), &hints, &result);		// setting the port
	if (iResult != 0) {
		WSACleanup();
		//return NULL;
		return *resultingSocket;
	}

	// Create a SOCKET for connecting to server
	ListenSocket = socket(result->ai_family, result->ai_socktype, result->ai_protocol);
	if (ListenSocket == INVALID_SOCKET) {
		freeaddrinfo(result);
		WSACleanup();
		//return NULL;
		return *resultingSocket;
	}

	// Setup the TCP listening socket
	iResult = bind(ListenSocket, result->ai_addr, (int)result->ai_addrlen);
	if (iResult == SOCKET_ERROR) {
		freeaddrinfo(result);
		closesocket(ListenSocket);
		WSACleanup();
		//return NULL;
		return *resultingSocket;
	}

	freeaddrinfo(result);

	iResult = listen(ListenSocket, SOMAXCONN);
	if (iResult == SOCKET_ERROR) {
		closesocket(ListenSocket);
		WSACleanup();
		//return NULL;
		return *resultingSocket;
	}

	// Accept a client socket
	ClientSocket = accept(ListenSocket, NULL, NULL);
	if (ClientSocket == INVALID_SOCKET) {
		closesocket(ListenSocket);
		WSACleanup();
		//return NULL;
		return *resultingSocket;
	}

	resultingSocket = new Socket(ClientSocket);
	return *resultingSocket;
}
