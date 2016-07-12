//**********************************************************************
// Plik : osoba.cpp
//**********************************************************************
 
#include "osoba.h"
#include <cstring>
//**********************************************************************
 
void osoba::zapamietaj(const char * napis, int lata)
{
        strcpy(nazwisko, (napis ? napis : "Anonim"));
        wiek = lata;
}
