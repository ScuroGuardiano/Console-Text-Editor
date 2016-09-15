#include <iostream>
#include <process.h>
#include <ctime>
#include <conio.h>
#include "include\Konsolka.h"
#include "include\EdytorTekstu.h"

using namespace std;

Konsolka Konsola;
CRITICAL_SECTION Sekcja_Kryt;

void _cdecl GornaLinia(void * args)
{
    time_t TimeMarchesTimeMarchesOnWithoutUsAllCauseTimeMarchesTimeMarchesOnAndOnAndOnFliesEternally;
    tm * czas;
    while(true)
    {
        time(& TimeMarchesTimeMarchesOnWithoutUsAllCauseTimeMarchesTimeMarchesOnAndOnAndOnFliesEternally);
        czas = localtime(& TimeMarchesTimeMarchesOnWithoutUsAllCauseTimeMarchesTimeMarchesOnAndOnAndOnFliesEternally);

        EnterCriticalSection(&Sekcja_Kryt);

        Konsola.UstawKursor(COORD{72,0});
        if(czas->tm_hour < 10) cout<<"0";
        cout<<czas->tm_hour<<":";
        if(czas->tm_min < 10) cout<<"0";
        cout<<czas->tm_min<<":";
        if(czas->tm_sec < 10) cout<<"0";
        cout<<czas->tm_sec;

        LeaveCriticalSection(&Sekcja_Kryt);

        Sleep(1000);
    }
_endthread();
}


int main()
{
    InitializeCriticalSection(&Sekcja_Kryt);
    system("chcp 1250");
    system("cls");

    _beginthread(GornaLinia, 0, NULL);

    char znak;

    EnterCriticalSection(&Sekcja_Kryt);
    EdytorTekstu Edytor(&Konsola);
    LeaveCriticalSection(&Sekcja_Kryt);

    while(true)
    {
        znak = getch();

        EnterCriticalSection(&Sekcja_Kryt);

        Edytor.UstawOstatniaPozycje();

        if(znak == 13)
        {
            Edytor.NowaLinia();
        }

        else if(znak == '\b')
        {
            Edytor.BackSpace();
        }

        else if(znak == 27) //ESC
        {
            break;
        }

        else if(znak == 0x13) //CTRL + S
        {
            Edytor.Zapisz();
        }

        else
        {
           Edytor.NapiszZnak(znak);
        }
        Edytor.WyswietlGornyInterfejs();

        LeaveCriticalSection(&Sekcja_Kryt);
    }
    return 0;
}
