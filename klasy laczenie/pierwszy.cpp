 ////////////////////////////////////////////////////////////////////////
//plik pierwszy.cpp
////////////////////////////////////////////////////////////////////////
#include<iostream>
#include <windows.h>
using namespace std;
 
#include "osoba.h"
#include "bilet.h"
 
void prezentacja (osoba);
void funkcja_w_innym_pliku();
 
//**********************************************************************
int main()
{
        osoba kompozytor, autor;
        kompozytor.zapamietaj("Fryderyk Chopin", 36);
        autor.zapamietaj("Marcel Proust", 34);
 
        //wywo³ujemy funkcje, wysylajac obiekty
        prezentacja(kompozytor);
        prezentacja(autor);
 
        cout << "\nU¿ywamy w tym pliku te¿ klasy 'bilet'\n";
 
        bilet zolty, niebieski;
        zolty.zapamietaj("Frankfurt", "Paris", bilet::ekspres, 1);
        zolty.wypisz();
 
        niebieski.zapamietaj("Zurich", "Genewa", bilet::przyspieszony);
        niebieski.wypisz();
 
        niebieski.zmien_rodzaj_pociagu(bilet::pospieszny);
        cout << "\nPo zmianie tego biletu...\n";
        niebieski.wypisz();
 
        funkcja_w_innym_pliku();
        Sleep(10000);
}
 
//**********************************************************************
 
void prezentacja(osoba ktos)
{
        cout << "Mam zaszczyt przedstawiæ pañstwu, \nOto we w³asnej osobie:";
        ktos.wypisz();
}
