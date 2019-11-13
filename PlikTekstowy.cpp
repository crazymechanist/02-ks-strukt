#include "PlikTekstowy.h"



bool PlikTekstowy::czyPlikJestPusty() {
    bool pusty = true;
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_TEKSTOWEGO.c_str(), ios::app);

    if (plikTekstowy.good() == true) {
        plikTekstowy.seekg(0, ios::end);
        if (plikTekstowy.tellg() != 0)
            pusty = false;
    }

    plikTekstowy.close();
    return pusty;
}

int PlikTekstowy::ileLiniWPliku() {

    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_TEKSTOWEGO.c_str(), ios::in);
    string linia;
    int liczbaLini=0;
    if (plikTekstowy.good() == true) {
        while(getline(plikTekstowy,linia)) {
            liczbaLini++;
        }
    } else {
        return 0;
    }

    plikTekstowy.close();
    return liczbaLini;
}




