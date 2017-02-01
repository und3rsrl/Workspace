#pragma once
#pragma comment(lib, "ws2_32.lib")
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#include <WinSock2.h>
#include <iostream>
#include <fstream>
#include <string>

class Multiplayer
{
private:

	// CONNECTION
	SOCKET Connection; // Connection to server for player
	SOCKADDR_IN addr; //Address to be binded for connection
	int sizeOfAddr = sizeof(addr);

	//Player Info
	std::string playerName;
	
	//Connection Functions
	bool Connect();
	bool Disconnect();

public:
	Multiplayer(std::string IP, int PORT);
	~Multiplayer();

	

	//Core
	void Play();
};

