#ifndef ADRESACIMENAGER_H
#define ADRESACIMENAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>


#include "Adresat.h"
#include "PlikZAdresatami.h"

using namespace std;

class AdrestaciMenager
{
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;
    vector <Adresat> adresaci;
    public:
    PlikZAdresatami plikZAdresatami;
    private:
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika);
    void wyswietlDaneAdresata(Adresat adresat);
    int podajIdWybranegoAdresata();
    bool usunAdresataZWektora(int idAdresata);
    char wybierzOpcjeZMenuEdycja();
    Adresat edytujAdresataWWektorze(int idAdresata);
    void edytujDanaAdresata(Adresat &adresat);


public:
    AdrestaciMenager(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika)
        : plikZAdresatami(nazwaPlikuZAdresatami),ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika) {
        adresaci=plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    }
    void dodajAdresata(int idZalogowanegoUzytkownika);
    void wyswietlWszystkichAdresatow();
    void usunAdresata();
    void edytujAdresata();
    bool czyKsiazkaAdresatowJestPusta();

};

#endif
