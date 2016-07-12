#ifndef OSOBA_H
#define OSOBA_H
//*****************************
//Plik osoba.h
//*****************************
#include <iostream>
using namespace std;
/////////////////////definicja klasy////////////////////////////////////
class osoba
{
        char nazwisko[80];
        int wiek;
        public:
        void zapamietaj(const char * napis, int lata);
        //----------------
        void wypisz()
        {
                cout << "\t" << nazwisko << ", lat: " << wiek << endl;
        }
};
///////////////////koniec definicji klasy///////////////////////////////
#endif
