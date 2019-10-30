#ifndef KSIAZKAADESOWA_H
#define KSIAZKAADESOWA_H

#include <iostream>

#include "UzykownikMenager.h"
#include "AdrestaciMenager.h"

using namespace std;

class KsiazkaAdresowa
{

    UzykownikMenager uzykownikMenager;
    AdrestaciMenager adrestaciMenager;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami,string nazwaPlikuZAdresatami):uzykownikMenager(nazwaPlikuZUzytkownikami), adrestaciMenager(nazwaPlikuZAdresatami){
    uzykownikMenager.wczytajUzytkownikowZPliku();
    }
    void logowanieUzytkownika();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownkow();
    void wylogowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku();
    void wyswietlWszystkichAdresatow();
    void dodajAdresata();


};

#endif
