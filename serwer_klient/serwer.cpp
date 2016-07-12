#include <winsock2.h>
#include <iostream>
#include <fstream> //czytanie i pisanie z pliku
#include <string>

using namespace std;

int StartServerListening(unsigned short port);
void EndServer(int socket);
ofstream drugtxt;    //pisanie do pliku
int main()
{

    int serverSocket;

    serverSocket = StartServerListening(7700); // Calls our function StartServerListen(); and passes the port 7700
    if (serverSocket == -1)
    {
        cout << "Server: AHHH EVERYTHING WENT WRONG!!!\nServer: **** THIS! IM DONE!\n";
        return 1;
    }

    int clientSocket;
    clientSocket = accept(serverSocket, 0, 0); // Accept The Client

    if (clientSocket == SOCKET_ERROR)
    {
        cout << "Server: Mah, I hate that bitch anyways...\n";
    } else {
    	cout <<"Server: Polaczenie zostalo nawiazane\n";
    }

    int nBytes;
    #define MESSAGE_SIZE 250 // This lets us know how much data we will be sending and recieving

    char inMessage[MESSAGE_SIZE]; // The actual buffer
    drugtxt.open("pisanie.txt");
    
    for(int i = 0; i<20; i++){
    
    	nBytes = recv(clientSocket, inMessage, sizeof(inMessage), 0);
    	string napisa(inMessage);
    	drugtxt<<napisa<<endl;
    	napisa.erase();	 
	}
    
     drugtxt.close();
    
    


    closesocket(clientSocket);

    EndServer(serverSocket); // Shut down the network

    cout << "Server: Press any key to shut down the Server...\n";
    getchar();
    
    return 0;
}

// [======================================]
// Functions
// [======================================]

// StartServerListen() - a function to startup winsock, and then open a socket for listening

int StartServerListening(unsigned short port)
{
    WSAData wsaData;

    if (WSAStartup(MAKEWORD(2, 2), &wsaData) == SOCKET_ERROR)
    {
        cout << "Server: Could Not Start Up Winsock!\n";
        return -1;
    }

    int mySocket = socket(AF_INET, SOCK_STREAM, 0);

    if (mySocket == SOCKET_ERROR)
    {
        cout << "Server: Socket is stuck again, wont open...\n";
        return -1;
    }

    struct sockaddr_in server;

    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;

    if (bind(mySocket, (sockaddr*)&server, sizeof(server)) == SOCKET_ERROR)
    {
        cout << "Server: Cant Bind the Socket, thats bad btw...\n";
        closesocket(mySocket);
        return -1;
    }

    if (listen(mySocket, 5) == SOCKET_ERROR)
    {
        cout << "ServeR: Im deaf! No listening socket open!\n";
        closesocket(mySocket);
        return -1;
    }

    cout << "Server: Up and Running Partner!\n";

    return mySocket;
}


// EndServer() - a function to shutdown a socket and clean up winsock

void EndServer(int socket)
{
    // Close our socket
    closesocket(socket);

    // Shut down winsock
    WSACleanup();

    cout << "Server: Server Shutting down\n";
}
