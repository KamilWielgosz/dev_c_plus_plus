#include "przyrzad.h" 
extern ekran_alfanumeryczny ekran; 

void zwloka(int sekund); // deklaracja funkcji pomocniczej 
int main() 
{ 
     ekran.wyczysc(); 
      
     przyrzad Pred(2, 1, "Predkosc", "wezlow", 110); 
     przyrzad Vari(2, 7, "Wznoszenie", "stopy/sec"); 
     przyrzad A; 
     przyrzad B; 
     volatile przyrzad C; 
      
     const przyrzad   Udzw(2, 11, "Udzwig maksymalny", "ton", 15000); 
      
      
     //symulacja normalnego ciaglego wyswietlania 
     for(int i = 0; i<30; i++) 
     { 
        Vari.zmien_wskazanie(i); 
        Pred.zmien_wskazanie(110+i); 
        A.zmien_wskazanie(-i); 
        B.zmien_wskazanie(i % 4); 
        // C.zmien_wskazanie(i % 3); // obiekt volatile 
        
        zwloka(1);       
     }       
} 
//**************************************************************  ******* 
//funkcja zwloka 

void zwloka(int sekund) 
{ 
     time_t poczatkowy_czas = time(NULL); 
     while(time(NULL) - poczatkowy_czas < sekund);       
} 
