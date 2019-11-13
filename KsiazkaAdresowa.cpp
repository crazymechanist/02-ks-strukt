#include "KsiazkaAdresowa.h"


void KsiazkaAdresowa::rejestracjaUzytkownika() {
    uzykownikMenager.rejestracjaUzytkownika();
}

void KsiazkaAdresowa::wypiszWszystkichUzytkownkow(){
    uzykownikMenager.wypiszWszystkichUzytkownkow();
}

void KsiazkaAdresowa::logowanieUzytkownika(){
    uzykownikMenager.logowanieUzytkownika();
    if (uzykownikMenager.zwrocIdZalogowanegoUzytkownika() != 0){
        adrestaciMenager = new AdrestaciMenager (NAZWA_PLIKU_Z_ADRESATAMI, uzykownikMenager.zwrocIdZalogowanegoUzytkownika());
        }
}

void KsiazkaAdresowa::wylogowanieUzytkownika(){
    uzykownikMenager.wylogowanieUzytkownika();
    delete adrestaciMenager;
    adrestaciMenager = NULL;
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika(){
    uzykownikMenager.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow() {
    adrestaciMenager->wyswietlWszystkichAdresatow();
}

void KsiazkaAdresowa::dodajAdresata() {
    if (uzykownikMenager.zwrocIdZalogowanegoUzytkownika()> 0) {
        adrestaciMenager->dodajAdresata(uzykownikMenager.zwrocIdZalogowanegoUzytkownika() );
    }
    else{
        cout << "Aby dodac adresata, nalezy sie najpierw zalogowac" << endl;
        system("Pause");
    }
}

void KsiazkaAdresowa::edytujAdresata() {
    if (uzykownikMenager.zwrocIdZalogowanegoUzytkownika()> 0) {
        adrestaciMenager->edytujAdresata();
    } else {
        cout << "Aby edytowac adresata, nalezy sie najpierw zalogowac" << endl;
        system("Pause");
    }
}

void KsiazkaAdresowa::usunAdresata() {
    if (uzykownikMenager.zwrocIdZalogowanegoUzytkownika()> 0) {
        adrestaciMenager->usunAdresata();
    } else {
        cout << "Aby usunac adresata, nalezy sie najpierw zalogowac" << endl;
        system("Pause");
    }
}

void KsiazkaAdresowa::wyswietlMenu() {
    if (uzykownikMenager.zwrocIdZalogowanegoUzytkownika() == 0) {
        char wybor = wybierzOpcjeZMenuGlownego();

        switch (wybor) {
        case '1':
            rejestracjaUzytkownika();
            break;
        case '2':
            logowanieUzytkownika();
            break;
        case '9':
            exit(0);
            break;
        default:
            cout << endl << "Nie ma takiej opcji w menu." << endl << endl;
            system("pause");
            break;
        }
    } else {

        char wybor = wybierzOpcjeZMenuUzytkownika();

        switch (wybor) {
        case '1':
            dodajAdresata();
            break;
//        case '2':
//            wyszukajAdresatowPoImieniu(adresaci);
//            break;
//        case '3':
//            wyszukajAdresatowPoNazwisku(adresaci);
//            break;
        case '4':
            wyswietlWszystkichAdresatow();
            break;
        case '5':
            usunAdresata();
            break;
        case '6':
            edytujAdresata();
            break;
        case '7':
            zmianaHaslaZalogowanegoUzytkownika();
            break;
        case '8':
            wylogowanieUzytkownika();
            break;
        }
    }
}

char KsiazkaAdresowa::wybierzOpcjeZMenuGlownego()
{
    char wybor;

    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocniczne::wczytajZnak();

    return wybor;
}

char KsiazkaAdresowa::wybierzOpcjeZMenuUzytkownika()
{
    char wybor;

    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
//    cout << "2. Wyszukaj po imieniu" << endl;
//    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocniczne::wczytajZnak();

    return wybor;
}
