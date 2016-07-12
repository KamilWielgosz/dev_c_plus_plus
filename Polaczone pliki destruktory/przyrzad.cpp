#include "przyrzad.h" 
#include <sstream> 
//definicja globalnego obiektu ekranu 
ekran_alfanumeryczny ekran ('.'); 

//deklaracja funkcji pomocniczej 
string liczba_na_napis(int wartosc); 
//definicje konstruktorow 
//**************************************************************  ****** 
przyrzad::przyrzad(int xx, int yy, string nnn, string jedn, int w) 
{ 
     nazwa = nnn; 
     jednostki = jedn; 
     pokazuje = w; 
     x = xx; 
     y = yy; 
     narysuj(); 
} 
//**************************************************************  ***** 
przyrzad::przyrzad(void) 
{ 
     ++ile_nieznanych; 
     jednostki = " "; 
      
     //wypelnienie tablicy tekstem - wskaznik nr n 
     nazwa = "Wskaznik nr"; 
     nazwa += liczba_na_napis(ile_nieznanych); 
      
     //wyswietlenie dla przyrzadu jego pozycji na ekranie 
     x = 33; 
     y = 1 +(ile_nieznanych - 1)*4; 
      
     pokazuje = 0; 
     narysuj(); 
} 
//************dalsze funkcje skladowe ***************************************** 
//**************************************************************  *********** 
void przyrzad::zmien_wskazanie(int w) 
{ 
     pokazuje = w; 
     narysuj(); 
} 
//**************************************************************  ******** 
void przyrzad::narysuj() 
{ 
     //Funkcja odpowiadajaca za narysowanie na ekranie ramki z 
     // "wyswietlaczem cyfrowyn" 
      
     ekran.napisz(x, y, "___________________________"); 
     ekran.napisz(x, y+1, "|             |"); 
     ekran.napisz(x, y+2, "|             |"); 
     ekran.napisz(x, y+3, "___________________________"); 
     ekran.napisz(x+4, y+1, nazwa); 
     ekran.napisz(x+7, y+2, liczba_na_napis(pokazuje)); 
     ekran.napisz(x+14, y+2, jednostki); 
     ekran.wyswietl(); 
} 
//===================================================== 
int przyrzad::ile_nieznanych; 
//************************************** 

string liczba_na_napis(int wartosc) 
{ 
#define JESTEM_WTAJEMNICZONY 1 // 0 - nie, 1 - tak 

#if JESTEM_WTAJEMNICZONY == 0 
// WERJA DLA WTEJEMNICZONYCH 

if(wartosc == 0) return "0"; 

string rezultat; 
if(wartosc < 0) 
{ 
   rezultat += '-'; 
     wartosc = -wartosc;             
}       
int reszta = wartosc; 
int pulap_dolny = (int) pow(10.0, (int) log10((double) wartosc)); 




for(; pulap_dolny > 0; pulap_dolny /=10) 
{ 
     int cyfra = reszta / pulap_dolny; 
     reszta = reszta % pulap_dolny; 
     rezultat += char('0' + cyfra); 
} 
return rezultat; 

#else 

//WERSJA DLA WTAJEMNICZOCNYH 

ostringstream strum; 
   strum << wartosc; 
   return strum.str(); 
    
#endif 
} 
