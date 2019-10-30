#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>
#include <tuple>

#include "Adresat.h"
#include "MetodyPomocniczne.h"


using namespace std;

class PlikZAdresatami{

    const string nazwaPlikuZAdresatami;
    int pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    int zwrocIdOstatniegoAdresataZPliku(string daneOstaniegoAdresataWPliku);
    bool czyPlikJestPusty();
    string zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat);

public:
    PlikZAdresatami(string NAZWAPLIKUZADRESATAMI)
    :nazwaPlikuZAdresatami(NAZWAPLIKUZADRESATAMI) {}
    Adresat pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami);
    tuple<vector <Adresat>,int > wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika);
    void dopiszAdresataDoPliku(Adresat adresat);
};

#endif
