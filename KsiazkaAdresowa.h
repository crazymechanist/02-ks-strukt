#ifndef KSIAZKAADESOWA_H
#define KSIAZKAADESOWA_H

#include <iostream>

#include "UzykownikMenager.h"

using namespace std;

class KsiazkaAdresowa
{

    UzykownikMenager uzykownikMenager;

public:
    KsiazkaAdresowa();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownkow();

};

#endif
