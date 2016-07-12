//**********************************************************************
//Plik: bilet.cpp
//**********************************************************************
#include "bilet.h"
#include <iostream>
using namespace std;
#include <cstring>
 
//**********************************************************************
void bilet::zapamietaj( const char* sk, const char * dok, rodzaj_pociagu poc, int kl)
{
        strcpy( skad, (sk ? sk : "Brak danych"));
        strcpy( dokad, (dok ? dok : "Brak danych"));
        jaki_pociag = poc;
        klasa = kl;
}
//**********************************************************************
void bilet::wypisz()
{
        char kreska[] = "[---------------------------------------------]\n";
        char brzegi[] = "[                                             ]\r[";
 
        cout << kreska << brzegi << "Bilet: " << skad << " --> " << dokad
        << ", klasa " << klasa << "\n" << brzegi << "  na pociag " << opis_rodzaju()
        << "\n" << kreska;
}
//**********************************************************************
const char * bilet::opis_rodzaju()
{
        const char *nazwy[] = {
                "osobowy (lub regionalny)",
                "przyspieszony (lekko)",
                "pospieszny",
                "InterCity ekspres"
        };
        return nazwy[jaki_pociag]; //zmiana enum na int
}
