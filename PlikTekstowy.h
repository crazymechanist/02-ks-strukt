#ifndef PLIKTEKSTOWY_H
#define PLIKTEKSTOWY_H

#include <iostream>
#include <vector>
#include <fstream>
#include <cstdlib>

#include "MetodyPomocniczne.h"

using namespace std;

class PlikTekstowy{


protected:
    const string NAZWA_PLIKU_TEKSTOWEGO;
    int ileLiniWPliku();
    bool czyPlikJestPusty();

public:
    PlikTekstowy(string nazwaPlikuTekstowego)
    :NAZWA_PLIKU_TEKSTOWEGO(nazwaPlikuTekstowego) {
    //puste cialo konstruktora
    }
};

#endif
