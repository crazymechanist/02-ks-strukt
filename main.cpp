#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main()
{
    KsiazkaAdresowa ksiazkaAdresowa("uzytkownicy.txt");
    //ksiazkaAdresowa.rejestracjaUzytkownika();
    //ksiazkaAdresowa.rejestracjaUzytkownika();
    ksiazkaAdresowa.wypiszWszystkichUzytkownkow();

    ksiazkaAdresowa.logowanieUzytkownika();
    ksiazkaAdresowa.wylogowanieUzytkownika();



    return 0;
}
