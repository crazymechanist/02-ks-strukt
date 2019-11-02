#include <iostream>

#include "KsiazkaAdresowa.h"

using namespace std;

int main() {
    KsiazkaAdresowa ksiazkaAdresowa("uzytkownicy.txt","KsiazkaAdresowa.txt");
    while(1) {
        ksiazkaAdresowa.wyswietlMenu();
    }

    return 0;
}
