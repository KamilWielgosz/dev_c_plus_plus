#ifndef BILET_H_
#define BILET_H_
//**********************************************************************
//Plik : bilet.h
//**********************************************************************
 
class bilet
{
        public: 
                enum rodzaj_pociagu { osobowy, przyspieszony, pospieszny, ekspres };
 
                void zapamietaj( const char* sk, const char * dok, rodzaj_pociagu poc, int kl = 2);
                void zmien_rodzaj_pociagu(rodzaj_pociagu poc);
                void wypisz();
 
                private:
                        char skad[80];
                        char dokad[80];
                        int klasa;
                        rodzaj_pociagu jaki_pociag;
                        const char * opis_rodzaju();
                };
////////////////////////////////////////////////////////////////////////
 
 
//**********************************************************************
inline void bilet::zmien_rodzaj_pociagu(rodzaj_pociagu poc)
{
        jaki_pociag = poc;
}
#endif
