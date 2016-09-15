#include "EdytorTekstu.h"

using namespace std;

EdytorTekstu::EdytorTekstu(Konsolka * Kons)
{
    this->OstatniaPozycja.X = 4;
    this->OstatniaPozycja.Y = 2;
    int i = 0;

    while(i<32)
    {
        this->licznikLinii[i] = 0;
        i++;
    }

    this->licznik = 0;
    this->aktualnaLinia = 0;
    this->Konsola = Kons;

    this->Konsola->UstawKursor(COORD{0, 2});
    this->Konsola->UstawKolorek(FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout<<"01|";
    this->Konsola->UstawKolorek(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED);
}

void EdytorTekstu::UstawOstatniaPozycje()
{
    this->Konsola->UstawKursor(this->OstatniaPozycja);
}

void EdytorTekstu::NowaLinia()
{
    if(aktualnaLinia + 1 < 32)
    {
        cout<<'\n';
        this->tekst += '\n';

        this->OstatniaPozycja.X = 4;
        this->OstatniaPozycja.Y++;
        this->licznik++;
        this->aktualnaLinia++;

        this->Konsola->UstawKolorek(FOREGROUND_BLUE | FOREGROUND_RED | FOREGROUND_INTENSITY);
        if(this->aktualnaLinia + 1 < 10) cout<<"0"<<this->aktualnaLinia + 1<<"|";
        else cout<<this->aktualnaLinia + 1<<"|";
        this->Konsola->UstawKolorek(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED);
    }

}

void EdytorTekstu::BackSpace()
{
    if(this->licznikLinii[this->aktualnaLinia])
        {
            this->OstatniaPozycja.X--;
            this->Konsola->UstawKursor(this->OstatniaPozycja);

            cout<<'\0';
            this->tekst.pop_back();

            this->Konsola->UstawKursor(this->OstatniaPozycja);
            this->licznikLinii[this->aktualnaLinia]--;
            this->licznik--;
        }
        else if(this->aktualnaLinia)
        {
            this->Konsola->UstawKursor(COORD{0, this->OstatniaPozycja.Y});
            cout<<string(3, '\0');

            this->aktualnaLinia--;
            this->OstatniaPozycja.X = this->licznikLinii[this->aktualnaLinia] + 4; //Bo od 4 linijki zaczyna siê pisanie
            this->OstatniaPozycja.Y--;
            this->Konsola->UstawKursor(this->OstatniaPozycja);

            cout<<'\0';
            this->tekst.pop_back();

            this->Konsola->UstawKursor(this->OstatniaPozycja);
            this->licznik--;
        }
}

void EdytorTekstu::NapiszZnak(char Znak)
{
    if(!(this->aktualnaLinia == 31 && this->licznikLinii[this->aktualnaLinia] == 64))
    {
        if(this->licznikLinii[this->aktualnaLinia] % 64 == 0 && this->licznikLinii[this->aktualnaLinia])
        {
            cout<<'\n';
            this->tekst += '\n';

            this->OstatniaPozycja.X = 4;
            this->OstatniaPozycja.Y++;
            this->licznik++;
            this->aktualnaLinia++;

            this->Konsola->UstawKolorek(FOREGROUND_GREEN | FOREGROUND_INTENSITY);
            if(this->aktualnaLinia + 1 < 10) cout<<"0"<<this->aktualnaLinia + 1<<"|";
            else cout<<this->aktualnaLinia + 1<<"|";
            this->Konsola->UstawKolorek(FOREGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_INTENSITY | FOREGROUND_RED);

            this->Konsola->UstawKursor(this->OstatniaPozycja);
        }
        this->OstatniaPozycja.X++;

        cout<<Znak;
        this->tekst += Znak;

        this->licznik++;
        this->licznikLinii[this->aktualnaLinia]++;
    }
}

void EdytorTekstu::WyswietlGornyInterfejs()
{
    this->Konsola->UstawKursor(COORD{3, 0});
    cout<<string(40, '\0');
    this->Konsola->UstawKursor(COORD{3, 0});
    cout<<this->licznik<<" znakow";
    cout<<"\t Linia: "<<this->aktualnaLinia + 1<<"/32";
    cout<<"\t Col: "<<this->licznikLinii[this->aktualnaLinia];
}

void EdytorTekstu::Zapisz()
{
    ofstream plik("Tekst.txt");
    plik<<this->tekst;
}
