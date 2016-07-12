#include <iostream>
#include <winsock2.h>
#include <windows.h>
#include <fstream>
using namespace std;

int erorr ;
int opcja ;
int opcja_2;
int haslo; // stare haslo
int haslo_2; // nowe haslo
int haslo_3; //aktualne haslo

u_long resolveHost( const string &host )
{
	LPHOSTENT hostEntry = gethostbyname(host.c_str());

	if ( !hostEntry )
	{
		unsigned int addr = inet_addr( host.c_str() );
		hostEntry = gethostbyaddr((char *)&addr, 4, AF_INET);

		if ( !hostEntry )
		{
			return 0;
		}
	}

	return *((int*)*hostEntry->h_addr_list);
}
int main(int argc, char* argv[])
{   
	if(opcja_2 == 1)
	{
	int haslo_3 = 0000; // aktualne haslo
    }
	cout << "\n\n\n";
	cout << "                         Podaj haslo   // domyslnie '0000'\n\n\n";
	cin >> haslo_3 ;
	
	if(haslo_3 == 0000 || haslo_3 == haslo_2)
	{
		
    }	
    do
	{
	///// Menu pseudo-graficzne ;) /////
	system("cls");
	system("title Client   v1.3.");
    cout << "\n\n\n\n\n\n\n";
	cout << "                         ////////////////////////\n";
	cout << "                         //1. Polacz z serwerem//\n";
	cout << "                         ////////////////////////\n";
	cout << "                         //2. Ustaw haslo ...  //\n";
	cout << "                         ////////////////////////\n";
	cout << "                         //3. Wyjdz do Windows //\n";
	cout << "                         ////////////////////////\n\n\n";
	cout << "                         Wybor: ";
    cin >> opcja ;

    ////////////////////////////////////

    if(opcja == 1)
{
	opcja = 0 ;
	system("cls");
	char szAddress[64];// zmienna z adresem ip
	int port; // zmienna z portem
	
	
	cout << "IP OR NAME DNS\n";
	cin >> szAddress;
	cout <<"PORT\n";
	cin>> port;

	char komunikat[80];
	WSADATA		wsaData;
	SOCKADDR_IN saddr;
	SOCKET		sock;
	char		*haslo = komunikat;
	char		index[1024*20] = { 0 };
	char		index2[1024*20] = { 0 };
// wyzej inicjacje i deklaracje potrzebnych zmiennych
	WSAStartup( MAKEWORD(2,2), &wsaData );

	sock = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	saddr.sin_addr.S_un.S_addr = resolveHost (szAddress); // w nawiasy ip lub zmienna odpowiadajaca za ip
	saddr.sin_family = AF_INET;
	saddr.sin_port = htons(port); // w nawiasy port lub zmienna odpowiadajaca za port

	if ( connect(sock, (sockaddr*)&saddr, sizeof(sockaddr)) == SOCKET_ERROR )
	{
		cout << "Fatal Erorr - Przedefiniuj IP lub PORT \n\n";
		sock = 0;
		cout << "1. RESTART \n2. EXIT\n";
		cin >> erorr ;
		cout << "\n \n POTWIERDZ ";
		if (erorr == 2)
		{
			return 1 ;
			
			}
	}
   
	recv(sock,index,1024*20,0); // odbieranie danych od serwera
	cout << index << endl;
	cin >> komunikat ; 
    send(sock,haslo,strlen(haslo),0);// wysylanie do serwera  zapytania ze zmiennej haslo
	recv(sock,index,1024*20,0); // odbieranie danych od serwera
	
	
	closesocket(sock);
	WSACleanup();
}
	if(opcja == 2)
  {
	system("cls");	
	cout << "Tutaj ustawiasz haslo do ... . \n\n\n" ;
	cout << "1. Programu 'Client' .\n";
	cout << "2. Serwera .\n\n\n";
	cout << "3. Wroc do menu\n\n\n";
	cin >> opcja_2 ;
	
	if(opcja_2 == 1)
	{
	system("cls");
	cout << "Wypelnij pola ponizej: \n\n\n";
	cout << "Stare haslo " << " //domyslnie '0000' \n";
	cin >> haslo ;
	if(haslo == haslo_3)
	{
	cout << "Podaj nowe haslo";
	cin >> haslo_2 ;
    }
    }
  }
    
    if(opcja == 3)
    {
	system("cls");
	return 0;
    }
    }while(erorr == 1);
    return 0 ;
}
