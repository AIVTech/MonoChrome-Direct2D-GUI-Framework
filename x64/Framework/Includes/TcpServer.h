#ifndef TCPSERVER_H
#define TCPSERVER_H

#pragma once
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <Windows.h>
#include <string>
#include "Socket.h"

class TcpServer
{
public:
	TcpServer();

	Socket& Listen(int port);

	~TcpServer();
};

#endif // !TCPSERVER_H