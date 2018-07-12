#include "Socket.h"

Socket::Socket(SOCKET socket) : socket(socket)
{
	// Defaulting All Options
	SetBlocking(true);
}

Socket::~Socket()
{
	Close();
}

void Socket::Close()
{
	closesocket(socket);
}

void Socket::SetBlocking(bool state)
{
	unsigned long mode;
	if (state)
	{
		// if blocking is true
		mode = BLOCKING;
	}
	else
	{
		// non-blocking is true
		mode = NON_BLOCKING;
	}
	ioctlsocket(socket, FIONBIO, &mode);
}

void Socket::SetBufferSize(int size)
{
	this->bufferSize = size;
}

std::string Socket::Recieve()
{
	std::string output = "";
	char* buf = new char[bufferSize];
	int bytes_recv = recv(socket, buf, 4096, 0);
	if (bytes_recv > 0) {
		output = std::string(buf, 0, bytes_recv);
	}
	return output;
}

int Socket::Send(char* data)
{
	return send(socket, data, (int)strlen(data) + 1, 0);
}

int Socket::Send(std::string data)
{
	return send(socket, data.c_str(), (int)data.size() + 1, 0);
}

int Socket::Send(std::wstring data)
{
	std::string data_string = std::string(data.begin(), data.end());
	return send(socket, data_string.c_str(), (int)data_string.size() + 1, 0);
}

bool Socket::IsConnected()
{
	int nSendBytes = send(socket, "", 1, 0);
	if (nSendBytes == SOCKET_ERROR)
	{
		return false;
	}
	else
	{
		return true;
	}
}
