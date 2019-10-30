#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>

#include "Adresat.h"
#include "MetodyPomocniczne.h"


using namespace std;

class PlikZAdresatami{

    const string nazwaPlikuZAdresatami;

public:
    PlikZAdresatami(string NAZWAPLIKUZADRESATAMI)
    :nazwaPlikuZAdresatami(NAZWAPLIKUZADRESATAMI) {}
    vector <Adresat> wczytajAdresatowZalogowanegoUzytkownikaZPliku();
};

#endif
