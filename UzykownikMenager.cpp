#include "UzykownikMenager.h"

void UzykownikMenager::rejestracjaUzytkownika(){
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);

    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik UzykownikMenager::podajDaneNowegoUzytkownika(){
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    string login;
    do
    {
        cout << "Podaj login: ";
        cin >> login;
        uzytkownik.ustawLogin(login);
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);

    string haslo;
    cout << "Podaj haslo: ";
    cin >> haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}

int UzykownikMenager::pobierzIdNowegoUzytkownika(){
    if (uzytkownicy.empty() == true)
        return 1;
    else
        return uzytkownicy.back().pobierzId() + 1;
}

bool UzykownikMenager::czyIstniejeLogin(string login) {
    for (int i=0; i<uzytkownicy.size(); i++) {
        if(uzytkownicy[i].pobierzLogin() == login) {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UzykownikMenager::wypiszWszystkichUzytkownkow() {
    for (int i=0; i<uzytkownicy.size(); i++) {
        cout <<uzytkownicy[i].pobierzId() << endl;
        cout <<uzytkownicy[i].pobierzLogin() << endl;
        cout <<uzytkownicy[i].pobierzHaslo() << endl;
    }
}

void UzykownikMenager::logowanieUzytkownika() {
    string login = "", haslo = "";
    int iter=0;

    cout << endl << "Podaj login: ";
    login = MetodyPomocniczne::wczytajLinie();

    while (iter != uzytkownicy.size()) {
        if (uzytkownicy[iter].pobierzLogin() == login)        {
            for (int iloscProb = 3; iloscProb > 0; iloscProb--) {
                cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                haslo = MetodyPomocniczne::wczytajLinie();

                if (uzytkownicy[iter].pobierzHaslo() == haslo) {
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    idZalogowanegoUzytkownika = uzytkownicy[iter].pobierzId();
                    return;
                }
            }
            cout << "Wprowadzono 3 razy bledne haslo." << endl;
            system("pause");
        }
        iter++;
    }
    cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
    system("pause");
    return;
}


void UzykownikMenager::wylogowanieUzytkownika(){
idZalogowanegoUzytkownika =0;
}

void UzykownikMenager::zmianaHaslaZalogowanegoUzytkownika() {
    string noweHaslo = "";
    int iter=0;
    cout << "Podaj nowe haslo: ";
    noweHaslo = MetodyPomocniczne::wczytajLinie();

    while (iter != uzytkownicy.size()) {
        if (uzytkownicy[iter].pobierzId()== idZalogowanegoUzytkownika) {
            uzytkownicy[iter].ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
        iter++;
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);
}

int UzykownikMenager::zwrocIdZalogowanegoUzytkownika() {
    return idZalogowanegoUzytkownika;
}



