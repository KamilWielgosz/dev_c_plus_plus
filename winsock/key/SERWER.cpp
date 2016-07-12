#include <winsock2.h>
#include <cstring>
#include <iostream>
#include <stdio.h>
#include <stdlib.h> 
// libwsock32.a to linkowac do winsocka2
                
using namespace std;

int main(int argc, char* argv[])
{   
	system("title KB88SP2x_Win_SP3_Clients_Instaler_Updates ");
	WSADATA		wsaData;
	SOCKADDR_IN saddr;
	SOCKET		sock;
	
    const char Kb[] = "ERROR";
	WSAStartup( MAKEWORD(2,2), &wsaData );

	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	memset( (void*)&saddr, 0, sizeof(saddr) );
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(3333);
	saddr.sin_addr.s_addr = htonl(INADDR_ANY);

	if ( bind(sock, (sockaddr*)&saddr, sizeof(saddr)) != SOCKET_ERROR )
	{
		if ( listen(sock, 1) != SOCKET_ERROR )
		{
			for (int i = 0; i < 5; i ++ ) {
				SOCKET client = accept(sock,NULL,NULL);
                
                FILE  * Plik ; 
                
                Plik = fopen("KB88SP2x.sys" , "r" ); // przygotowanie do rozpoczêcia operacji na pliku
                if (Plik == NULL)
                {
                  send(client, Kb, strlen(Kb), 0);
                } 
                char Bufor[1000];
                const int n = 1000 ;
                //fread(Tablica, 1, sizeof(Tablica), Plik); 
                fgets(Bufor, n, Plik);// wczytywanie z pliku danych do bufora
                send(client, Bufor, strlen(Bufor), 0);
                
               
                
                
               // libwsock32.a to linkowac do winsocka2
                
                
                
                fclose (Plik);
			 	
				
			 //	recv(sock,haslo,1024*20,0);// zpais hasla do zmiennej haslo
				
			//	closesocket(client);
			}
		}
	}
      
	closesocket(sock);
	WSACleanup();
	system("pause");
	return 0;
}
