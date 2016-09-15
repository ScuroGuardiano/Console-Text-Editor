#ifndef KONSOLKA_H
#define KONSOLKA_H

#include <windows.h>


class Konsolka
{
public:
    Konsolka();
    COORD DawajXY();
    void UstawKursor(COORD kordy);
    void UstawKolorek(WORD kolorek);

protected:

private:
    HANDLE Uchwyt;
    COORD Pozycja;

};

#endif // KONSOLKA_H
