// Winsock for our network communication
#include <winsock2.h>
#include <iostream>

using namespace std;

int StartServerListening(unsigned short port);

void EndServer(int socket);

HANDLE Hthread; // Used to handle our threads
HANDLE Hmutex; // A mutex is bascially a memory spot we can lock so nothing writes to it as we read form it.. That could cause issues

FD_SET masterSet; // This basically is our list of sockets that we will lock and unlock with out mutexHandle

// A FD_SET has a few data members:
// - fd_count - the number of file descriptors in the set
// - fd_array - the array of file descriptors

// We can use these little macros to help edit the FD_SET
// - FD_SET(a socket, FD_SET to manipulate) - add a scoket to the set
// - FD_ZERO(FD_SET to manipulate) - zero a set
// - FD_CLR(a socket, FD_SET to manipulate) - remove a socket from the set
// - FD_ISSET(a socket, FD_SET to manipulate) - checks if the socket is already in the set


bool gQuitFlag = false;// A flag ill use to terminate the program if it goes terribly wrong

// AcceptThread() - a This function will accept ALL incomming connections Then add to the FD_SET list
void AcceptThread(int* serverSocket)
{
    int mySocket = *serverSocket;    // Copy my socket over to a local variable

    
    for (;;)// Run forever, why stop? O_o
    {
    
        unsigned int clientSocket = accept(mySocket, 0, 0);    // Do a normal accept

        if (clientSocket == SOCKET_ERROR)
        {
            cout << "Server: I shall not accept them!\n";
            gQuitFlag = true; // Quit this thread
            return;
        }
        else
        {
            WaitForSingleObject(Hmutex, INFINITE);// Lock the mutex and wait for it
            FD_SET(clientSocket, &masterSet);// Add this socket to the master set using FD_SET()
            ReleaseMutex(Hmutex);// Unlock the mutex

            
            cout << "client on " << clientSocket <<" connected.\n" << endl;// Let everyone know someone just joined
        }
    }
}

int main()
{
    cout << "Server: Part 5! Last One Kiddies!\n";
    cout << "Server: Celestialkey's Tutorial\n\n";

    int serverSocket;
    serverSocket = StartServerListening(7700);

    if (serverSocket == -1)
    {
        cout << "Server: I failed you master! Im so ashamed!\n";
        return 1;
    }

    
    Hmutex = CreateMutex(NULL, false, NULL);// Create the mutex

    if (Hmutex == NULL)
    {
        cout << "Server: Sorry Sir! Could not make our Mutex! FORGIVE ME!\n";
        EndServer(serverSocket);
        return 1;
    }

    
    int thread;// Create the thread
    Hthread = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)AcceptThread, &serverSocket, 0, (LPDWORD)&thread);
    
    if (Hthread == NULL)
    {
        cout << "Server: SORRY SIR! Could not beging Accepting!\n";
        EndServer(serverSocket);
        return 1;
    }
    Sleep(100);// Let the AcceptThread start up, cheap method, but oh well -.-;

    FD_ZERO(&masterSet); // Always zero your sets before you use them, you know.. just incase...

    for (;;) // Forever!!!!
    {
        if (gQuitFlag)
        {
            break;
        }


        WaitForSingleObject(Hmutex, INFINITE);        // Lock the mutex

        FD_SET TempSet = masterSet; // Make a temp location so we can unlock our mutex and let our accept thread run ASAP
        ReleaseMutex(Hmutex);        // Unlock the mutex

        if (TempSet.fd_count == 0) // If a set is empty and we call form it, it returns a error, thats too much coding for me
        {                              // So we will simply check if there is anything in it, if so we will do something, else screw it -.-;
            continue;
        }

        // select() has 5 member datas of use to us they are
        // - the number of file descriptors
        // - a FD_SET  checks readability
        // - a FD_SET  checks for writeability
        // - a FD_SET  checks for errors
        // - a wait time
        timeval waitTime; // Set up our interval
        waitTime.tv_sec = 0; // Set it to 0
        waitTime.tv_usec = 0; // Set it to 0

        int result = select(TempSet.fd_count, &TempSet, NULL, NULL, &waitTime); // Select a socket in out TempSet


        if (result == 0) // Check for 0's agian
        {
            continue; // = Empty
        }

        if (result == SOCKET_ERROR)
        {
            cout << "Server: Sorry Sir! there was a error in the Select() macro!\n";
            continue;
        }

        for (unsigned int i = 0; i < TempSet.fd_count; i++)
        {
            unsigned int clientSocket = TempSet.fd_array[i];

            int nBytes;
            #define MAX_MESSAGE_SIZE 4096
            char buffer[MAX_MESSAGE_SIZE];

            unsigned long messageSize;
            nBytes = recv(clientSocket, (char*)&messageSize, sizeof(messageSize), 0);

            if (nBytes == SOCKET_ERROR)
            {
                int error = WSAGetLastError();// Main error you will get here is if the other client suddenly disconnects or loses power or something similar
                if (error == WSAECONNRESET)
                {
                    WaitForSingleObject(Hmutex, INFINITE);    // Lock our mutex
                    FD_CLR(clientSocket, &masterSet);            // Remove the socket from our master set
                    ReleaseMutex(Hmutex);                    // Unlock our mutex
                    closesocket(clientSocket);                    // Close the socket on our side so our computer cleans up properly
                    cout << "Server: Client on "<< clientSocket << " has Disconnected." << endl; // Tell everyone the person left
                    continue;
                }
                else
                {
                    cout << "Server: Sorry Sir... Its a fatel wound.. Oh god it hurts... *Breaths slowly* *Stops breathing*\n";// Error we wernt expecting, terminate the server in this case
                    gQuitFlag = true;
                    break;
                }
            }
            if (nBytes == 0) // Called if the user exits and calls closesocket() on THEIR side. They stops ending data, thus 0 bytes, ets jsut remove them from the set
            {
                WaitForSingleObject(Hmutex, INFINITE);    // Lock our mutex
                FD_CLR(clientSocket, &masterSet);        // Remove the socket from our master set
                ReleaseMutex(Hmutex);                // Unlock our mutex
                closesocket(clientSocket);                // Close the socket on our side, so our computer cleans up properly
                cout << "Server: Client on " << clientSocket << " has disconnected" << "\n";// Quick Message to the rest in the room
                continue;// On to the next one!
            }
            messageSize = ntohl(messageSize);
            nBytes = recv(clientSocket, buffer, messageSize, 0);
            if (nBytes == SOCKET_ERROR)
            {
                cout << "Server: I failed the message sir!\n";
                gQuitFlag = true;
                break;
            }
            buffer[messageSize];
            cout << "Server: Client [" <<  clientSocket << "]: " << buffer << "\n";
        }
    }

    EndServer(serverSocket);
    cout << "Server: Press any key to shut me down....\n";
    getchar();
    return 0;
}


int StartServerListening(unsigned short port)
{
    int error;
    WSAData wsaData;
    if ((error = WSAStartup(MAKEWORD(2, 2), &wsaData)) == SOCKET_ERROR)
    {
        cout << "Server: Winsock is being a bitch Sir!\n";
        return -1;
    }
    int mySocket = socket(AF_INET, SOCK_STREAM, 0);
    if (mySocket == SOCKET_ERROR)
    {
        cout << "Server: ****ing Socket is stuck closed!\n";
        return -1;
    }
    struct sockaddr_in server;
    server.sin_family = AF_INET;
    server.sin_port = htons(port);
    server.sin_addr.s_addr = INADDR_ANY;
    if (bind(mySocket, (sockaddr*)&server, sizeof(server)) == SOCKET_ERROR)
    {
        cout << "Server: Sorry Sir! My Bind Failed!\n";
        closesocket(mySocket);
        return -1;
    }
    if (listen(mySocket, 5) == SOCKET_ERROR)
    {
        cout << "Server: I failed to listen -.-;\n";
        closesocket(mySocket);
        return -1;
    }
    cout << "Server: Starting Up.. READY!\n";
    return mySocket;
}
void EndServer(int socket)
{
    WaitForSingleObject(Hthread, INFINITE);// Kill thread and handle
    CloseHandle(Hthread);
    CloseHandle(Hmutex);
    closesocket(socket);
    WSACleanup();
    cout << "Server: Shuting down master.\n";
}
