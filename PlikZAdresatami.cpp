#include "PlikZAdresatami.h"


vector <Adresat> PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika) {
    vector <Adresat> adresaci;
    Adresat adresat;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    string daneOstaniegoAdresataWPliku = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_TEKSTOWEGO.c_str(), ios::in);

    if (plikTekstowy.good() == true) {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {
            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami)) {
                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
                adresaci.push_back(adresat);
            }
        }
    daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
    plikTekstowy.close();
    }

   if(daneOstaniegoAdresataWPliku != ""){
    idOstatniegoAdresata=pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
   }
    return adresaci;
}

int PlikZAdresatami::pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami) {
    int pozycjaRozpoczeciaIdUzytkownika = daneJednegoAdresataOddzielonePionowymiKreskami.find_first_of('|') + 1;
    int idUzytkownika = MetodyPomocniczne::konwersjaStringNaInt(MetodyPomocniczne::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdUzytkownika));

    return idUzytkownika;
}

Adresat PlikZAdresatami::pobierzDaneAdresata(string daneAdresataOddzielonePionowymiKreskami) {
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (int pozycjaZnaku = 0; pozycjaZnaku < daneAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++) {
        if (daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|') {
            pojedynczaDanaAdresata += daneAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        } else {
            switch(numerPojedynczejDanejAdresata) {
            case 1:
                adresat.ustawId( atoi(pojedynczaDanaAdresata.c_str() ) );
                break;
            case 2:
                adresat.ustawIdUzytkownika (atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.ustawImie (pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.ustawNazwisko (pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.ustawNumerTelefonu (pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.ustawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.ustawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}

int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami) {
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocniczne::konwersjaStringNaInt(MetodyPomocniczne::pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}

bool PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat) {
    string liniaZDanymiAdresata = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_TEKSTOWEGO.c_str(), ios::out | ios::app);

    if (plikTekstowy.good() == true) {
        liniaZDanymiAdresata = zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(adresat);

        if (czyPlikJestPusty() == true) {
            plikTekstowy << liniaZDanymiAdresata;
        } else {
            plikTekstowy << endl << liniaZDanymiAdresata ;
        }
        idOstatniegoAdresata++;
        plikTekstowy.close();
        return true;
    }
    return false;
}

string PlikZAdresatami::zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(Adresat adresat) {
    string liniaZDanymiAdresata = "";

    liniaZDanymiAdresata += MetodyPomocniczne::konwersjaIntNaString(adresat.pobierzId()) + '|';
    liniaZDanymiAdresata += MetodyPomocniczne::konwersjaIntNaString(adresat.pobierzIdUzytkownika()) + '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}

int PlikZAdresatami::pobierzIdOstatniegoAdresata() {
    return idOstatniegoAdresata;
}

int PlikZAdresatami::zwrocNumerLiniiSzukanegoAdresata(int idAdresata)
{
    bool czyIstniejeAdresat = false;
    int numerLiniiWPlikuTekstowym = 1;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_TEKSTOWEGO.c_str(), ios::in);

    if (plikTekstowy.good() == true && idAdresata != 0)
    {
        while(getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(idAdresata == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                czyIstniejeAdresat = true;
                plikTekstowy.close();
                return numerLiniiWPlikuTekstowym;
            }
            else
                numerLiniiWPlikuTekstowym++;
        }
        if (czyIstniejeAdresat = false)
        {
            plikTekstowy.close();
            return 0;
        }
    }
    return 0;
}

void PlikZAdresatami::usunWybranaLinieWPliku(int numerUsuwanejLinii) {
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia = "";
    int numerWczytanejLinii = 1;
    int ileLini=ileLiniWPliku();

    odczytywanyPlikTekstowy.open(NAZWA_PLIKU_TEKSTOWEGO.c_str(), ios::in);
    tymczasowyPlikTekstowy.open(NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI.c_str(), ios::out | ios::app);
    if (odczytywanyPlikTekstowy.good() == true && numerUsuwanejLinii != 0) {
        while (getline(odczytywanyPlikTekstowy,wczytanaLinia)) {
            if (numerWczytanejLinii == numerUsuwanejLinii) {
                //nie zapisuj lini
            } else  {
                if(numerUsuwanejLinii!=ileLini) {
                    if(numerWczytanejLinii != ileLini) {
                        tymczasowyPlikTekstowy<<wczytanaLinia<<endl;
                    } else {
                        tymczasowyPlikTekstowy<<wczytanaLinia;
                    }
                } else {
                    if(numerWczytanejLinii != ileLini-1) {
                        tymczasowyPlikTekstowy<<wczytanaLinia<<endl;
                    } else {
                        tymczasowyPlikTekstowy<<wczytanaLinia;
                        idOstatniegoAdresata=pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(wczytanaLinia);
                    }
                }
            }
            numerWczytanejLinii++;
        }
        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        MetodyPomocniczne::usunPlik(NAZWA_PLIKU_TEKSTOWEGO);
        MetodyPomocniczne::zmienNazwePliku(NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI, NAZWA_PLIKU_TEKSTOWEGO);
        return;
    }
    odczytywanyPlikTekstowy.close();
    tymczasowyPlikTekstowy.close();
    MetodyPomocniczne::usunPlik(NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI);
}

void PlikZAdresatami::usunAdresataZPliku(int idAdresata)
{
    int numerLini=zwrocNumerLiniiSzukanegoAdresata(idAdresata);
    usunWybranaLinieWPliku(numerLini);
}

void PlikZAdresatami::edytujLinieWPliku(Adresat edytowanyAdresat) {
    int numerEdytowanejLinii=zwrocNumerLiniiSzukanegoAdresata(edytowanyAdresat.pobierzId());
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    string wczytanaLinia = "";
    int numerWczytanejLinii = 1;
    int ileLini=ileLiniWPliku();

    odczytywanyPlikTekstowy.open(NAZWA_PLIKU_TEKSTOWEGO.c_str(), ios::in);
    tymczasowyPlikTekstowy.open(NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI.c_str(), ios::out | ios::app);

    if (odczytywanyPlikTekstowy.good() == true && numerEdytowanejLinii != 0) {
        while (getline(odczytywanyPlikTekstowy,wczytanaLinia)) {

            if (numerWczytanejLinii == numerEdytowanejLinii) {
                if(numerWczytanejLinii != ileLini) {
                    tymczasowyPlikTekstowy<<zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(edytowanyAdresat)<<endl;
                } else {
                    tymczasowyPlikTekstowy<<zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(edytowanyAdresat);
                }
            } else  {
                if(numerWczytanejLinii != ileLini) {
                    tymczasowyPlikTekstowy<<wczytanaLinia<<endl;
                } else {
                    tymczasowyPlikTekstowy<<wczytanaLinia;
                }
            }
            numerWczytanejLinii++;
        }

        odczytywanyPlikTekstowy.close();
        tymczasowyPlikTekstowy.close();

        MetodyPomocniczne::usunPlik(NAZWA_PLIKU_TEKSTOWEGO);
        MetodyPomocniczne::zmienNazwePliku(NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI, NAZWA_PLIKU_TEKSTOWEGO);
        return;
    }
    odczytywanyPlikTekstowy.close();
    tymczasowyPlikTekstowy.close();
    MetodyPomocniczne::usunPlik(NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI);
}


//void PlikZAdresatami::edytujAdresataWPliku(Adresat edytowanyAdresat)
//{
//    int numerEdytowanejLinii=zwrocNumerLiniiSzukanegoAdresata(edytowanyAdresat.pobierzId());
//    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
//    string wczytanaLinia = "";
//    int numerWczytanejLinii = 1;
//
//    odczytywanyPlikTekstowy.open(NAZWA_PLIKU_TEKSTOWEGO.c_str(), ios::in);
//    tymczasowyPlikTekstowy.open(NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI.c_str(), ios::out | ios::app);
//
//    if (odczytywanyPlikTekstowy.good() == true && numerEdytowanejLinii != 0)
//    {
//        while (getline(odczytywanyPlikTekstowy, wczytanaLinia))
//        {
//            // Tych przypadkow jest tyle, gdyz chcemy osiagnac taki efekt,
//            // aby na koncu pliku nie bylo pustej linii
//            if (numerWczytanejLinii == numerEdytowanejLinii) {
//                tymczasowyPlikTekstowy<<zamienDaneAdresataNaLinieZDanymiOddzielonymiPionowymiKreskami(edytowanyAdresat);
//            }
//            else  (numerWczytanejLinii == 1 && numerWczytanejLinii != numerEdytowanejLinii)
//                tymczasowyPlikTekstowy << wczytanaLinia;
//            else if (numerWczytanejLinii == 2 && numerEdytowanejLinii == 1)
//                tymczasowyPlikTekstowy << wczytanaLinia;
//            else if (numerWczytanejLinii > 2 && numerEdytowanejLinii == 1)
//                tymczasowyPlikTekstowy << endl << wczytanaLinia;
//            else if (numerWczytanejLinii > 1 && numerEdytowanejLinii != 1)
//                tymczasowyPlikTekstowy << endl << wczytanaLinia;
//            numerWczytanejLinii++;
//        }
//        odczytywanyPlikTekstowy.close();
//        tymczasowyPlikTekstowy.close();
//
//        MetodyPomocniczne::usunPlik(NAZWA_PLIKU_TEKSTOWEGO);
//        MetodyPomocniczne::zmienNazwePliku(NAZWA_TYMCZASOWEGO_PLIKU_Z_ADRESATAMI, NAZWA_PLIKU_TEKSTOWEGO);
//    }
//}


