#ifndef KSIAZKAADESOWA_H
#define KSIAZKAADESOWA_H

#include <iostream>

#include "UzykownikMenager.h"

using namespace std;

class KsiazkaAdresowa
{

    UzykownikMenager uzykownikMenager;

public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami):uzykownikMenager(nazwaPlikuZUzytkownikami) {
    uzykownikMenager.wczytajUzytkownikowZPliku();
    }
    void logowanieUzytkownika();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownkow();
    void wylogowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();


};

#endif
