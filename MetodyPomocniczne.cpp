#include "MetodyPomocniczne.h"

string MetodyPomocniczne::konwersjaIntNaString(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

string MetodyPomocniczne::wczytajLinie(){
    string wejscie = "";
    getline(cin, wejscie);
    return wejscie;
}
