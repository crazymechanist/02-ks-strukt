#ifndef UZYKOWNIKMENAGER_H
#define UZYKOWNIKMENAGER_H

#include <iostream>
#include <vector>
#include <windows.h>
#include <fstream>
#include <sstream>

#include "Uzytkownik.h"
#include "PlikZUzytkownikami.h"

using namespace std;

class UzykownikMenager
{
    int idZalogowanegoUzytkownika;
    vector <Uzytkownik> uzytkownicy;
    PlikZUzytkownikami plikZUzytkownikami;

    Uzytkownik podajDaneNowegoUzytkownika();
    int pobierzIdNowegoUzytkownika();
    bool czyIstniejeLogin(string login);

    public:
    UzykownikMenager(string nazwaPlikuZUzytkownikami): plikZUzytkownikami(nazwaPlikuZUzytkownikami) {
    uzytkownicy=plikZUzytkownikami.wczytajUzytkownikowZPliku();
    idZalogowanegoUzytkownika=0;
    }

    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownkow();
    void logowanieUzytkownika();
    void zmianaHaslaZalogowanegoUzytkownika();
    void wylogowanieUzytkownika();
    int zwrocIdZalogowanegoUzytkownika();
};

#endif
