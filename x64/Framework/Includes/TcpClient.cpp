#include "TcpClient.h"

TcpClient::TcpClient()
{
}

TcpClient::~TcpClient()
{
}

Socket TcpClient::Connect(const char* ip, int port)
{
	// initialize winsock
	WSAData data;
	WORD ver = MAKEWORD(2, 2);
	int wsResult = WSAStartup(ver, &data);
	if (wsResult != 0) {
		return NULL;
	}

	// create socket
	SOCKET sock = socket(AF_INET, SOCK_STREAM, 0); // SOCK_STREAM is for TCP, SOCK_DGRAM is for UDP
	if (sock == INVALID_SOCKET) {
		WSACleanup();
		return NULL;
	}

	// Fill in a hint structure
	sockaddr_in hint;
	hint.sin_family = AF_INET;
	hint.sin_port = htons(port);
	inet_pton(AF_INET, ip, &hint.sin_addr);

	// connect to the server
	int connResult;
	connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));
	while (connResult == SOCKET_ERROR) {
		connResult = connect(sock, (sockaddr*)&hint, sizeof(hint));
	}
	
	return Socket(sock);
}
