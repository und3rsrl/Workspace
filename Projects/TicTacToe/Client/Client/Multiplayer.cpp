#include "Multiplayer.h"



Multiplayer::Multiplayer(std::string IP, int PORT)
{
	WSAData wsaData;
	WORD DllVersion = MAKEWORD(2, 1);
	if (WSAStartup(DllVersion, &wsaData) != 0) // If WSAStartup returns anything other than 0, then that means an error has occured in Winsock Startup
	{
		MessageBoxA(NULL, "Failed to initialize node !", "Error", MB_OK | MB_ICONERROR);
		exit(1);
	}


	addr.sin_addr.s_addr = inet_addr(IP.c_str()); // Address = localhost
	addr.sin_port = htons(PORT); // Port = 1111
	addr.sin_family = AF_INET; // IPv4 Socket

	std::ifstream name ("name.txt");

	if (!name.is_open()) {
		name.close();
		std::ofstream name("name.txt");

		std::cout << "Enter your player name:  ";
		std::cin >> playerName;

		name << playerName;
		std::cout << "Hello back " + playerName + '\n';
	}
	else {
		getline(name, playerName);
		std::cout << "Hello back " + playerName + '\n';
	}
}


Multiplayer::~Multiplayer()
{
}

bool Multiplayer::Connect()
{
	Connection = socket(AF_INET, SOCK_STREAM, NULL); //Set Connection socket
	if (connect(Connection, (SOCKADDR*)&addr, sizeOfAddr) != 0) // If we are unable to connect...
	{
		MessageBoxA(NULL, "Failed to connect to the server", "Error", MB_OK | MB_ICONERROR);
		return false;
	}

	std::cout << "Connected!" << std::endl;
	//CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)ClientThread, NULL, NULL, NULL); // Creat the client thread
	return true;
}

bool Multiplayer::Disconnect()
{
	if (closesocket(Connection) == SOCKET_ERROR)
	{
		if (WSAGetLastError() == WSAENOTSOCK) // If socket error is that operation is not performed on a socket (This happens when the)
			return true; // return true since connection has already been closed

		std::string ErrorMessage = "Failed to disconnect. Error: " + std::to_string(WSAGetLastError()) + ".";
		MessageBoxA(NULL, ErrorMessage.c_str(), "Error", MB_OK | MB_ICONERROR);
		return false;
	}
}

void Multiplayer::Play()
{
	Connect();



	Disconnect();
}
