#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <winsock2.h>

// The IP address for the server to listen on
#define SERVERIP "127.0.0.1"

// The TCP port number for the server to listen on
#define SERVERPORT 5555

// The (fixed) size of message that we send between the two programs
#define MESSAGESIZE 40

#pragma comment(lib, "ws2_32.lib")

class Server
{
	public:
		Server();
		~Server();
		int talk_to_client();
		void die(const char *message);
		int ConnectToClient();

		SOCKET serverSocket;
		SOCKET clientSocket;
};

