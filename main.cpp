#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main() {
    KsiazkaAdresowa ksiazkaAdresowa("uzytkownicy.txt","KsiazkaAdresowa.txt");
    while(1) {
        ksiazkaAdresowa.wyswietlMenu();
    }

    return 0;
}

//test usuwania i edytowania
int main1() {
    AdrestaciMenager adresatMenadzer("KsiazkaAdresowa.txt",1);
    //cout<<adresatMenadzer.plikZAdresatami.pobierzIloscLini();
    adresatMenadzer.usunAdresata();
    //adresatMenadzer.edytujAdresata();

    return 0;
}
