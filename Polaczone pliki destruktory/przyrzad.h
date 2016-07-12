#include <iostream> 
using namespace std; 
#include <string> 
#include <cmath> 
#include <ctime> 
//************************************************************* 
/////////////////////////////////////////////////////////////// 
class ekran_alfanumeryczny 
{ 
     string tresc; 
     char znak_tla; 
      
 public: 
           enum {szerokosc_ekranu = 63, wysokosc_ekranu = 24}; 

//kostruktor 
     ekran_alfanumeryczny(char znak=' ') 
       { 
           znak_tla = znak; 
           wyczysc();       
       }             
//------------- 
 void wyczysc() 
{ 
     //wypelnienie calego ekranu samymi znakami tla 
     int ile_znakow = wysokosc_ekranu * szerokosc_ekranu; 
     tresc.assign(ile_znakow, znak_tla); 
      
     //wstawienie znakow przejscia do nowej linii ekranowej po kazdej szerokosci ekranu 
      
     for(int i = 0; i < wysokosc_ekranu; i++) 
     { 
           tresc[(i+1)* szerokosc_ekranu - 1] = '\n';       
     } 
} 
//----------- 
void wyswietl() 
{ 
     cout<< tresc << flush; 
} 
//------------ 
//Funkcja skladowa wpisujaca w wybranym miejscu zadany tekst do tresci ekranu 
void napisz(int kolumna, int rzad, string tekst) 
{ 
     tresc.replace(  (szerokosc_ekranu * rzad) + kolumna, tekst.length(), tekst); 
} 
}; 
////////////////////////////////////////////////////////////////  ////////////////////// 
class przyrzad 
{ 
     string nazwa; 
     string jednostki; 
     int pokazuje; 
     int x, y; 
     static int ile_nieznanych; 
      
public: 
     // konstrukotyr 
     przyrzad(int, int, string, string, int = 0); 
     przyrzad(void); 
      
     //zwykle funkcje skalowe 
     void zmien_wskazanie(int w); 
     void narysuj(void); 
}; 
////////////////////////////////////////////////////////////////  ////////////////////// 
