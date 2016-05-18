#include "Server.h"

Server::Server()
{
	WSADATA w;
	int error = WSAStartup(0x0202, &w);
	if (error != 0)
	{
		die("WSAStartup failed");
	}
	if (w.wVersion != 0x0202)
	{
		die("Wrong WinSock version");
	}

	// Create a TCP socket that we'll use to listen for connections.
	serverSocket = socket(AF_INET, SOCK_STREAM, 0);

	if (serverSocket == INVALID_SOCKET)
	{
		die("socket failed");
	}

	// Fill out a sockaddr_in structure to describe the address we'll listen on.
	sockaddr_in serverAddr;
	serverAddr.sin_family = AF_INET;
	serverAddr.sin_addr.s_addr = inet_addr(SERVERIP);
	// htons converts the port number to network byte order (big-endian).
	serverAddr.sin_port = htons(SERVERPORT);

	// Bind the server socket to that address.
	if (bind(serverSocket, (const sockaddr *)&serverAddr, sizeof(serverAddr)) != 0)
	{
		die("bind failed");
	}

	// ntohs does the opposite of htons.
	printf("Server socket bound to address %s, port %d\n", inet_ntoa(serverAddr.sin_addr), ntohs(serverAddr.sin_port));

	// Make the socket listen for connections.
	if (listen(serverSocket, 1) != 0)
	{
		die("listen failed");
	}

	printf("Server socket listening\n");
}


Server::~Server()
{
}

int Server::ConnectToClient()
{
	printf("Waiting for a connection...\n");

	sockaddr_in clientAddr;
	int addrSize = sizeof(clientAddr);
	clientSocket = accept(serverSocket, (sockaddr *)&clientAddr, &addrSize);
	if (clientSocket == INVALID_SOCKET)
	{
		// accept failed -- just try again.
		//continue;
	}

	printf("Client has connected from IP address %s, port %d!\n", inet_ntoa(clientAddr.sin_addr), ntohs(clientAddr.sin_port));

	return talk_to_client();

	printf("Client disconnected\n");

	// Close the connection.
	closesocket(clientSocket);

	//// We won't actually get here, but if we did then we'd want to clean up...
	printf("Quitting\n");
	closesocket(serverSocket);
	WSACleanup();
	return 0;
}

// Communicate with a client.
// The socket will be closed when this function returns.
int Server::talk_to_client()
{
	char buffer[MESSAGESIZE];

	while (true)
	{
		// Receive as much data from the client as will fit in the buffer.
		int count = recv(clientSocket, buffer, MESSAGESIZE, 0);
		if (memcmp(buffer, "hi", 2) == 0)
		{
			return 1;
		}
		if (count <= 0)
		{
			printf("Client closed connection\n");
			//return;
		}
		if (count != MESSAGESIZE)
		{
			printf("Got strange-sized message from client\n");
			//return;
		}
		if (memcmp(buffer, "quit", 4) == 0)
		{
			printf("Client asked to quit\n");
			//return;
		}

		// (Note that recv will not write a \0 at the end of the message it's
		// received -- so we can't just use it as a C-style string directly
		// without writing the \0 ourself.)

		printf("Received %d bytes from the client: '", count);
		fwrite(buffer, 1, count, stdout);
		printf("'\n");

		// Send the same data back to the client.
		if (send(clientSocket, buffer, MESSAGESIZE, 0) != MESSAGESIZE)
		{
			printf("send failed\n");
			//return;
		}
	}
	return 0;
}

// Print an error message and exit.
void Server::die(const char *message)
{
	fprintf(stderr, "Error: %s (WSAGetLastError() = %d)\n", message, WSAGetLastError());

#ifdef _DEBUG
	// Debug build -- drop the program into the debugger.
	abort();
#else
	exit(1);
#endif
}