#ifndef EDYTORTEKSTU_H
#define EDYTORTEKSTU_H

#include "Konsolka.h"
#include <windows.h>
#include <iostream>
#include <string>
#include <fstream>

class EdytorTekstu
{
public:
    EdytorTekstu(Konsolka * Kons);
    void UstawOstatniaPozycje();
    void NowaLinia();
    void BackSpace();
    void NapiszZnak(char znak);
    void WyswietlGornyInterfejs();
    void Zapisz();

protected:

private:
    COORD OstatniaPozycja;
    int licznik;
    int aktualnaLinia;
    int licznikLinii[32];
    Konsolka * Konsola;
    std::string tekst;

};

#endif // EDYTORTEKSTU_H
