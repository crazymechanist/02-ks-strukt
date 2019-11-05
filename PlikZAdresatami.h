#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>


#include "Adresat.h"
#include "MetodyPomocniczne.h"


using namespace std;

class PlikZAdresatami{

    const string NAZWA_PLIKU_Z_ADRESATAMI;
    int idOstatniegoAdresata;

    bool czyPlikJestPusty();
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);




public:
    PlikZAdresatami(string nazwaPlikuZAdresatami)
        :NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {
        idOstatniegoAdresata=0;
    }

    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    bool dopiszAdresataDoPliku(Adresat adresat);
    int pobierzIdOstatniegoAdresata();
};

#endif
