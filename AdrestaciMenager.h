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
    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;
    int idOstatniegoAdresata;
    void wyswietlDaneAdresata(Adresat adresat);
    Adresat podajDaneNowegoAdresata(int idZalogowanegoUzytkownika);
    void dopiszAdresataDoPliku(Adresat adresat);

    public:
    AdrestaciMenager(string nazwaPlikuZAdresatami)
    : plikZAdresatami(nazwaPlikuZAdresatami) {
        idOstatniegoAdresata=0;
    }
    int pobierzIdOstatniegoAdresata();
    void wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    void wyswietlWszystkichAdresatow();
    void dodajAdresata(int idZalogowanegoUzytkownika);
    bool czyKsiazkaAdresatowJestPusta();
    void wyczyscKsiazkeAdresowa();
};

#endif
