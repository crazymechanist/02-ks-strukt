#include "AdrestaciMenager.h"

void AdrestaciMenager::wczytajAdresatowZalogowanegoUzytkownikaZPliku(int idZalogowanegoUzytkownika) {
    tie(adresaci,idOstatniegoAdresata)=plikZAdresatami.wczytajAdresatowZalogowanegoUzytkownikaZPliku(idZalogowanegoUzytkownika);
}
