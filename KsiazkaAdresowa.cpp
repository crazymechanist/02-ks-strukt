#include "KsiazkaAdresowa.h"


void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzykownikMenager.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownkow(){
    uzykownikMenager.wypiszWszystkichUzytkownkow();
}

void KsiazkaAdresowa::logowanieUzytkownika(){
    uzykownikMenager.logowanieUzytkownika();
}

void KsiazkaAdresowa::wylogowanieUzytkownika(){
    uzykownikMenager.wylogowanieUzytkownika();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika(){
    uzykownikMenager.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wczytajAdresatowZalogowanegoUzytkownikaZPliku() {
    adrestaciMenager.wczytajAdresatowZalogowanegoUzytkownikaZPliku(uzykownikMenager.zwrocIdZalogowanegoUzytkownika() );
}

