#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("uzytkownicy.txt");
    ksiazkaAdresowa.wypiszWszystkichUzytkownkow();
    ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.zmianaHaslaZalogowanegoUzytkownika();
    ksiazkaAdresowa.wylogowanieUzytkownika();



    return 0;
}
