#include "KsiazkaAdresowa.h"

KsiazkaAdresowa::KsiazkaAdresowa(){
uzykownikMenager.wczytajUzytkownikowZPliku();
}

void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzykownikMenager.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownkow(){
    uzykownikMenager.wypiszWszystkichUzytkownkow();
}

