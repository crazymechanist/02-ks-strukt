#include "PlikZAdresatami.h"


//vector <Adresat> PlikZAdresatami::wczytajAdresatowZalogowanegoUzytkownikaZPliku() {
//
//    Adresat adresat;
//    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
//    string daneOstaniegoAdresataWPliku = "";
//    fstream plikTekstowy;
//    plikTekstowy.open(nazwaPlikuZAdresatami.c_str(), ios::in);
//
//    if (plikTekstowy.good() == true) {
//        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami)) {
//            if(idZalogowanegoUzytkownika == pobierzIdUzytkownikaZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami)) {
//                adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
//                adresaci.push_back(adresat);
//            }
//        }
//        daneOstaniegoAdresataWPliku = daneJednegoAdresataOddzielonePionowymiKreskami;
//    } else
//        cout << "Nie udalo sie otworzyc pliku i wczytac danych." << endl;
//
//    plikTekstowy.close();
//
//    if (daneOstaniegoAdresataWPliku != "") {
//        idOstatniegoAdresata = pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneOstaniegoAdresataWPliku);
//        return idOstatniegoAdresata;
//    } else
//        return 0;
//}
