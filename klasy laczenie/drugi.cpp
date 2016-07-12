////////////////////////////////////////////////////////////////////////
//plik drugi.cpp
////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "bilet.h"   // bo w bie¿¹cym pliku u¿ywamy klasy bilet
using namespace std;
//**********************************************************************
void funkcja_w_innym_pliku()
{
        cout << "\nJesteœmy w innym pliku programu, \ntu te¿ u¿ywamy biletów\n";
        bilet bialy;
        bialy.zapamietaj ("Krakow", "Tarnow", bilet::osobowy);
        bialy.wypisz();
 
        cout << "Spieszy sie nam, zmieniamy bilet na taki:" << endl;
        bialy.zmien_rodzaj_pociagu(bilet::pospieszny);
        bialy.wypisz();
}
