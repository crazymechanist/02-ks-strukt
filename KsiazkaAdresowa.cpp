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
    adrestaciMenager.wyczyscKsiazkeAdresowa();
}

void KsiazkaAdresowa::zmianaHaslaZalogowanegoUzytkownika(){
    uzykownikMenager.zmianaHaslaZalogowanegoUzytkownika();
}

void KsiazkaAdresowa::wczytajAdresatowZalogowanegoUzytkownikaZPliku() {
    adrestaciMenager.wczytajAdresatowZalogowanegoUzytkownikaZPliku(uzykownikMenager.zwrocIdZalogowanegoUzytkownika());
}

void KsiazkaAdresowa::wyswietlWszystkichAdresatow() {
    adrestaciMenager.wyswietlWszystkichAdresatow();
}

void KsiazkaAdresowa::dodajAdresata(){
    adrestaciMenager.dodajAdresata(uzykownikMenager.zwrocIdZalogowanegoUzytkownika() );
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

        if (adrestaciMenager.czyKsiazkaAdresatowJestPusta() )
            wczytajAdresatowZalogowanegoUzytkownikaZPliku();

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
//        case '5':
//            idUsunietegoAdresata = usunAdresata(adresaci);
//            idOstatniegoAdresata = podajIdOstatniegoAdresataPoUsunieciuWybranegoAdresata(idUsunietegoAdresata, idOstatniegoAdresata);
//            break;
//        case '6':
//            edytujAdresata(adresaci);
//            break;
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
//    cout << "5. Usun adresata" << endl;
//    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
    wybor = MetodyPomocniczne::wczytajZnak();

    return wybor;
}
