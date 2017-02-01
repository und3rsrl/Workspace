#pragma once
#pragma comment(lib, "ws2_32.lib")
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#include <string> //For std::string
#include <iostream>



class Multiplayer
{
public:
	//Init
	Multiplayer(std::string IP, int PORT);
	~Multiplayer();

	//Core
	void play();

	//Connection functions
	bool Connect();
	bool Disconnect();
private:
	SOCKET Connection;
	SOCKADDR_IN addr;
	int sizeOfAddr = sizeof(addr);
};

static Multiplayer * instancePtr;