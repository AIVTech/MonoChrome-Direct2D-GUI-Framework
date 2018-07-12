#ifndef SOCKET_H
#define SOCKET_H

#pragma once
#include <WinSock2.h>
#include <WS2tcpip.h>
#include <Windows.h>
#include <string>

#define BLOCKING 0
#define NON_BLOCKING 1

class Socket
{
public:
	Socket(SOCKET socket);

	void SetBlocking(bool state);
	void SetBufferSize(int size);

	std::string Recieve();
	int Send(char* data);
	int Send(std::string data);
	int Send(std::wstring data);

	bool IsConnected();

	void Close();
	~Socket();
private:
	SOCKET socket;
	int bufferSize = 512;
};

#endif // !SOCKET_H