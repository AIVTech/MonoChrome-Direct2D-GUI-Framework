#pragma once

#include <WinSock2.h>
#include <WS2tcpip.h>
#include <Windows.h>
#include <string>
#include "Socket.h"

class TcpClient
{
public:
	TcpClient();
	
	Socket& Connect(const char* ip, int port);

	~TcpClient();
};

