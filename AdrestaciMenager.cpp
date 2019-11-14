#include "AdrestaciMenager.h"

void AdrestaciMenager::wyswietlWszystkichAdresatow()
{
    system("cls");
    if (!adresaci.empty())
    {
        cout << "             >>> ADRESACI <<<" << endl;
        cout << "-----------------------------------------------" << endl;
        for (vector <Adresat> :: iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            wyswietlDaneAdresata(*itr);
        }
        cout << endl;
    }
    else
    {
        cout << endl << "Ksiazka adresowa jest pusta." << endl << endl;
    }
    system("pause");
}

void AdrestaciMenager::wyswietlDaneAdresata(Adresat adresat)
{
    cout << endl << "Id:                 " << adresat.pobierzId() << endl;
    cout << "Imie:               " << adresat.pobierzImie() << endl;
    cout << "Nazwisko:           " << adresat.pobierzNazwisko() << endl;
    cout << "Numer telefonu:     " << adresat.pobierzNumerTelefonu() << endl;
    cout << "Email:              " << adresat.pobierzEmail() << endl;
    cout << "Adres:              " << adresat.pobierzAdres() << endl;
}

void AdrestaciMenager::dodajAdresata(int idZalogowanegoUzytkownika)
{
    Adresat adresat;
    system("cls");
    cout << " >>> DODAWANIE NOWEGO ADRESATA <<<" << endl << endl;
    adresat = podajDaneNowegoAdresata(idZalogowanegoUzytkownika);

    adresaci.push_back(adresat);
    if(plikZAdresatami.dopiszAdresataDoPliku(adresat)){
        cout<<"Nowy adresat zostal dodany"<<endl;
    }
    else{
        cout <<"Blad. Nie udalo sie dodac nowego adresata do pliku. " << endl;
        system("pause");
    }

}

Adresat AdrestaciMenager::podajDaneNowegoAdresata(int idZalogowanegoUzytkownika)
{
    Adresat adresat;

    adresat.ustawId(plikZAdresatami.pobierzIdOstatniegoAdresata()+1);
    adresat.ustawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);

    cout << "Podaj imie: ";
    adresat.ustawImie(MetodyPomocniczne::wczytajLinie() );

    cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(MetodyPomocniczne::wczytajLinie());

    cout << "Podaj numer telefonu: ";
    adresat.ustawNumerTelefonu(MetodyPomocniczne::wczytajLinie());

    cout << "Podaj email: ";
    adresat.ustawEmail(MetodyPomocniczne::wczytajLinie());

    cout << "Podaj adres: ";
    adresat.ustawAdres(MetodyPomocniczne::wczytajLinie());

    return adresat;
}

bool AdrestaciMenager::czyKsiazkaAdresatowJestPusta(){
    return adresaci.empty();
}

int AdrestaciMenager::podajIdWybranegoAdresata()
{
    int idWybranegoAdresata = 0;
    cout << "Podaj numer ID Adresata: ";
    idWybranegoAdresata  = MetodyPomocniczne::wczytajLiczbeCalkowita();
    return idWybranegoAdresata;
}

void AdrestaciMenager::usunAdresata() {
    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    int idUsuwanegoAdresata = podajIdWybranegoAdresata();
    if (usunAdresataZWektora(idUsuwanegoAdresata)) {
        plikZAdresatami.usunAdresataZPliku(idUsuwanegoAdresata);
    }
    else{
        cout << "Nie usunieto adresata." << endl;
        system("Pause");
    }
}

bool AdrestaciMenager::usunAdresataZWektora(int idAdresata) {
    vector <Adresat>::iterator itr = adresaci.begin();
    while (itr != adresaci.end() ) {
        if (itr -> pobierzId() == idAdresata ) {
            adresaci.erase(itr);
            return true;
        }
        itr++;
    }
    return false;
}

void AdrestaciMenager::edytujAdresata() {
    system("cls");
    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    int idEdytowanegoAdresata = podajIdWybranegoAdresata();
    Adresat edytowanyAdresat = edytujAdresataWWektorze(idEdytowanegoAdresata);
    if (edytowanyAdresat.pobierzId()!=0) {
        plikZAdresatami.edytujLinieWPliku(edytowanyAdresat);
    } else {
        cout << "Nie edytowano adresata." << endl;
        system("Pause");
    }
}

Adresat AdrestaciMenager::edytujAdresataWWektorze(int idAdresata) {
    vector <Adresat>::iterator itr = adresaci.begin();
    while (itr != adresaci.end() ) {
        if (itr -> pobierzId() == idAdresata ) {
            edytujDanaAdresata(*itr);
            return *itr;
        }
        itr++;
    }
    Adresat pustyAdresat(0,0);
    return pustyAdresat;
}

void AdrestaciMenager::edytujDanaAdresata(Adresat &adresat) {
    char wybor = wybierzOpcjeZMenuEdycja();

    switch (wybor) {
    case '1':
        cout << "Podaj nowe imie: ";
        adresat.ustawImie(MetodyPomocniczne::wczytajLinie());
        break;
    case '2':
        cout << "Podaj nowe nazwisko: ";
        adresat.ustawNazwisko(MetodyPomocniczne::wczytajLinie());
        break;
    case '3':
        cout << "Podaj nowy numer telefonu: ";
        adresat.ustawNumerTelefonu(MetodyPomocniczne::wczytajLinie());
        break;
    case '4':
        cout << "Podaj nowy email: ";
        adresat.ustawEmail(MetodyPomocniczne::wczytajLinie());
        break;
    case '5':
        cout << "Podaj nowy adres zamieszkania: ";
        adresat.ustawAdres(MetodyPomocniczne::wczytajLinie());
        break;
    case '6':
        cout << endl << "Powrot do menu uzytkownika" << endl << endl;
        break;
    default:
        cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
        break;
    }
}


char AdrestaciMenager::wybierzOpcjeZMenuEdycja()
{
    char wybor;

    cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";
    wybor = MetodyPomocniczne::wczytajZnak();

    return wybor;
}

