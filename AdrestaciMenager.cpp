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
    adresat.ustawImie(MetodyPomocniczne::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzImie() ) );

    cout << "Podaj nazwisko: ";
    adresat.ustawNazwisko(MetodyPomocniczne::wczytajLinie());
    adresat.ustawNazwisko(MetodyPomocniczne::zamienPierwszaLitereNaDuzaAPozostaleNaMale(adresat.pobierzNazwisko() ) );

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

