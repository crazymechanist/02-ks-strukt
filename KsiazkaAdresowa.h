#ifndef KSIAZKAADESOWA_H
#define KSIAZKAADESOWA_H

#include <iostream>

#include "UzykownikMenager.h"
#include "AdrestaciMenager.h"

using namespace std;

class KsiazkaAdresowa
{

    UzykownikMenager uzykownikMenager;
    AdrestaciMenager *adrestaciMenager;
    char wybierzOpcjeZMenuUzytkownika();
    char wybierzOpcjeZMenuGlownego();
    const string NAZWA_PLIKU_Z_ADRESATAMI;

    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownkow();
    void logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogowanieUzytkownika();
    void dodajAdresata();
    void wyswietlWszystkichAdresatow();
    void usunAdresata();
    void edytujAdresata();


public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami,string nazwaPlikuZAdresatami)
    :uzykownikMenager(nazwaPlikuZUzytkownikami), NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {
        adrestaciMenager = NULL;
    }
    ~KsiazkaAdresowa() {
        delete adrestaciMenager;
        adrestaciMenager = NULL;
    }
    void wyswietlMenu();
};

#endif
