////////////////////////////////////////////////////////////////////////
//plik drugi.cpp
////////////////////////////////////////////////////////////////////////
#include <iostream>
#include "bilet.h"   // bo w bie��cym pliku u�ywamy klasy bilet
using namespace std;
//**********************************************************************
void funkcja_w_innym_pliku()
{
        cout << "\nJeste�my w innym pliku programu, \ntu te� u�ywamy bilet�w\n";
        bilet bialy;
        bialy.zapamietaj ("Krakow", "Tarnow", bilet::osobowy);
        bialy.wypisz();
 
        cout << "Spieszy sie nam, zmieniamy bilet na taki:" << endl;
        bialy.zmien_rodzaj_pociagu(bilet::pospieszny);
        bialy.wypisz();
}
