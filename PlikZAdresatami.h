#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>


#include "PlikTekstowy.h"
#include "Adresat.h"
#include "MetodyPomocniczne.h"


using namespace std;

class PlikZAdresatami : public PlikTekstowy{

    const string NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI;
    int idOstatniegoAdresata;
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int zwrocNumerLiniiSzukanegoAdresata(int idAdresata);
    void usunWybranaLinieWPliku(int numerUsuwanejLinii);


public:
    PlikZAdresatami(string nazwaPlikuZAdresatami):PlikTekstowy(nazwaPlikuZAdresatami),NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI("temp_KsiazkaAdresowa.txt") {
        idOstatniegoAdresata=0;
    }

    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    bool dopiszAdresataDoPliku(Adresat adresat);
    int pobierzIdOstatniegoAdresata();
    void usunAdresataZPliku(int idAdresata);
};

#endif
