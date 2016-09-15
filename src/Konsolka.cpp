#include "Konsolka.h"

Konsolka::Konsolka()
{
    this->Uchwyt = GetStdHandle(STD_OUTPUT_HANDLE);
}

COORD Konsolka::DawajXY()
{
    PCONSOLE_SCREEN_BUFFER_INFO info;
    GetConsoleScreenBufferInfo(this->Uchwyt, info);
    this->Pozycja = info->dwCursorPosition;
    return this->Pozycja;
}

void Konsolka::UstawKursor(COORD Kordy)
{
    SetConsoleCursorPosition(this->Uchwyt, Kordy);
}

void Konsolka::UstawKolorek(WORD Kolorek)
{
    SetConsoleTextAttribute(this->Uchwyt, Kolorek);
}
