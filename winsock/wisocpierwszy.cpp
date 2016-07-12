#define _CRT_SECURE_NO_DEPR]ECATE
int StartClient(unsigned short port, const char* serverName);
void EndClient(int clientSocket);



#include <winsock2.h>
#include <iostream>
using namespace std;



int main()
{
    cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
         << "Client: And we Are done!\n"
         << "Client: Celestialkey's Tutorial\n\n"
         << "Client: Thanks for following the tutorial to the end\n"
          << "Client: if you want more good tutorials such as this, join me on\n"
         << "Client: http://Celestial.muux.org\n\n\n\n\n\n";

    // This simply changes the colors to make it look cooler
    HANDLE hConsole;
    hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hConsole, 2);
    // -----------------------------------------------------
    int mySocket;
    mySocket = StartClient(7700, "localhost");

    if (mySocket == -1)
    {
        EndClient(mySocket);
        return 1;
    }
    int nBytes;
    #define MAX_MESSAGE_SIZE 4096
    char buffer[MAX_MESSAGE_SIZE];
    cout << "Client: Type what you want to send, if you want to exit, type 'exit'\nClient: LETS DO IT!\nClient: > ";
    for (;;)
    {
        gets(buffer);
        if (strcmp(buffer, "exit") == 0)
        {
            break;
        }
        unsigned long messageSize = strlen(buffer);
        messageSize = htonl(messageSize);
        if ((nBytes = send(mySocket, (char*)&messageSize, sizeof(messageSize), 0)) == SOCKET_ERROR)
        {
            cout << "Client: Send Failed Sir!\n";
        }
        messageSize = ntohl(messageSize);
        if ((nBytes = send(mySocket, buffer, messageSize, 0)) == SOCKET_ERROR)
        {
            cout << "Client: It wont go through sir!!\n";
        }
        cout << "\n>";
    }
    EndClient(mySocket);
    return 0;
}

int StartClient(unsigned short port, const char* serverName)
{
    int error;
    WSAData wsaData;
    if ((error = WSAStartup(MAKEWORD(2, 2), &wsaData)) == SOCKET_ERROR)
    {
        cout << "Client: Winsock is being a bitch!\n";
        return -1;
    }
    int mySocket = socket(AF_INET, SOCK_STREAM, 0);
    if (mySocket == SOCKET_ERROR)
    {
        cout << "Client: The Socket is stuck sir! It wont open!\n";
        return -1;
    }
    struct hostent *host_entry;
    if ((host_entry = gethostbyname(serverName)) == NULL)
    {
        cout << "Client: I'm lost =.=; Wheres the host?\n";
    }
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = *(unsigned long*) host_entry->h_addr;
    if (connect(mySocket, (sockaddr*)&server, sizeof(server)) == SOCKET_ERROR)
    {
        cout << "Client: ****ing server wont let me connect dude.\n";
    }
    cout << "Client: I-AM-RUNNING!\n";

    return mySocket;
}


void EndClient(int clientSocket)
{
    closesocket(clientSocket);
    WSACleanup();
    cout << "Client: Dont rush me damnit, im shutting down at my own damn pace. -.-;\n";
}
