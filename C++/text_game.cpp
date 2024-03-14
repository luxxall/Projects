#include <iostream> //do obslugi strumienie wejscia i wyjscia
#include <thread>
#include <chrono>
#include <unistd.h>
#include <cstdio> //tez do obslugi getchar()
#include <cstdlib> //do funkcji exit(0) i clock_t
#include <time.h> //do obslugi time i clock_t
#include <ctime> //do obslugi sleep
//#include <stdio.h> //do getchar()
//#include <sys/types.h>
//#include <iomanip> //do setprecision()
#include <sys/uio.h>
//#include <curses.h>//do obslugi getch() - stara biblioteka
#include <ncurses.h>//do obslugi getch() - "nowa/stara" blibliteka
#include <fstream> //do pracy z zewnetrznymi plikami
#include <limits> //zdejmuje limit znakow cin.clear
#include <string> //do obslugi transform
#include <algorithm> //do obslugi funckji transform
using namespace std;

//deklaracje
unsigned int Wybierz;
string ImieGracza;
void GlowneMenu();
void Tworca();
bool Gra();
void Poczatek();
void G1_1();

int main()
{
    //petla wyboru menu
    while(Wybierz!=3)
    {
        GlowneMenu();
    
        cout << "\nWybierz: ";
        cin >> Wybierz;
        
        switch(Wybierz)
        {
            case 1:
            { Poczatek(); } break;
                
            case 2:
            { Tworca(); } break;
                
            case 3:
            {
                system("clear");
                cout << "\nA wiec to tak... " << endl;
                cout << "Zamykanie..." << endl;
                cout << endl;
                return 0;
            } break;
                
            default:
            {   //powrot do glownego menu jesli gracz wcisnie inny numer lub klawisz z litera
                if(cin.fail())
                {
                    cin.clear();
                    cin.ignore();
                    cout << "\nCos robisz zle wojowniku! Wybierz opcje z menu." << endl;
                    cout << endl;
                    cout << "\n------------------- Nacisnij Enter aby kontynuowac -------------------" << endl;
                    system("read");
                    GlowneMenu();
                } else
                {
                    cout << "\nCos robisz zle wojowniku! Wybierz opcje z menu." << endl;
                    cout << endl;
                    cout << "\n------------------- Nacisnij Enter aby kontynuowac -------------------" << endl;
                    system("read");
                    GlowneMenu();
                }
            } break;
        }
    }

    return 0;
}

//menu glowne
void GlowneMenu()
{
    system("clear");
    cout << "========== ADVENTURE GAME 3000 ==========" << endl;
    cout << endl;
    cout << " __________ GLOWNE MENU __________" << endl;
    cout << " >> 1. Zacznij gre!" << endl;
    cout << " >> 2. Tworca" << endl;
    cout << " >> 3. Nie graj i spierdzielaj!" << endl;
}

//menu tworcy
void Tworca()
{
    system("clear");
    cout << "======= TWORCA TEJ WIEKOPOMNEJ GRY =======" << endl;
    cout << "\nNo ja" << endl;
    cout << "\nPozdrawiam cieplutko" << endl;
    cout << "\n------------------- Nacisnij Enter aby kontynuowac -------------------" << endl;
    system("read");
    GlowneMenu();
}

//po rozpoczeciu gry imie gracza i przejscie dalej
void Poczatek()
{
    system("clear");
    cin.clear();
    cin.ignore();
    cout << "Wojowniku! Jak Ci na imie?" << endl;
    getline(cin,ImieGracza);
    system("clear");
    cout << "\nSzybciej, wynosmy sie stad " << ImieGracza << ". Orki wdarly sie juz do miasta!" << endl;
    cout << "\n------------------- Nacisnij Enter aby kontynuowac -------------------" << endl;
    system("read");
    Gra();
}

//zaczynamy nowa gre
bool Gra()
{
    system("clear");
    int wyborSciezka_Jeden;
    cout << "# Co zrobisz teraz?" << endl;
    cout << "\t >> Wybierz '1' aby podazyc za Kapitanem Strazy." << endl;
    cout << "\t >> Wybierz '2' aby znalezc wlasna droge ucieczki." << endl;
    
retry:
    cout << "\nTwoj wybor: ";
    cin >> wyborSciezka_Jeden;
    switch(wyborSciezka_Jeden)
        {
            case 1:
            {
                system("clear");
                cout << "\n!!!----------------------Rozdzial I: Ucieczka----------------------!!!" << endl;
                cout << endl;
                cout << ImieGracza << ": Dokad idziemy?" << endl;
                cout << "Kapitan Strazy: Pozniej Ci wszystko wyjasnie. Po prostu chodz za mna!" << endl;
                cout << "# Biegniesz za Kapitanem Strazy." << endl;
                cout << "\n------------------- Nacisnij Enter aby kontynuowac -------------------" << endl;
            system("read");
                
                system("clear");
                cout << "---------------- Miasto -----------------" << endl;
                cout << "\n# Biegniecie wzdluz muru otaczajacego miasto," << endl;
                cout << "# z daleka slychac krzyki ludzi, dostrzegasz czarne slupy dymu." << endl;
                cout << "# Kiedy dobiegacie do wejscia wiezy zaczyna ci brakowac tchu." << endl;
                cout << "# Kapitan pospiesznie otwiera drzwi i ruchem reki nakazuje Ci wejsc do srodka." << endl;
                cout << "# Wewnatrz dostrzegasz zarys kilku wielkich postaci trzymajacych cos w rekach..." << endl;
                cout << "\n------------------- Nacisnij Enter aby kontynuowac -------------------" << endl;
            system("read");
                
                int wyborSciezkaDwa;
                PowrotwyborSciezkiDwa:
                system("clear");
                cout << "---------------- Miasto -----------------" << endl;
                cout << "\nKapitan Strazy: Szybko, do srodka! To nasza jedyna droga ucieczki." << endl;
                cout << "\nCo zamierzasz zrobic?" << endl;
                cout << "\t >> '1' Kiwasz glowa i szybko wpadasz przez uchylone drzwi." << endl;
                cout << "\t >> '2' Nie masz zamiaru podazac dalej za straznikiem, \n \t\tdalej radzisz sobie sam" << endl;
                
        cin >> wyborSciezkaDwa;
        switch(wyborSciezkaDwa)
            {
                case 1:
                {
                system("clear");
                cout << "---------------- Mury -----------------" << endl;
                cout << "\n# Wbiegasz do ciemnego pomieszczenia, \n# chwile trwa zanim Twoj wzrok sie przywyczaja" << endl;
                cout << "# Orientujesz sie, ze dookola Ciebie stoi 3 opancerzonych ludzi." << endl;
                cout << "# Nie zwracajac na Ciebie uwagi wszyscy trzej odwracaja sie w strone Kapitana" << endl;
                cout << "\n------------------- Nacisnij Enter aby kontynuowac -------------------" << endl;
            system("read");
                }
                break;
                        
                case 2:
                {
                system("clear");
                cout << "---------------- Miasto -----------------" << endl;
                cout << endl;
                cout << ImieGracza << ": Nie mam zamiaru isc z Toba ani kroku dalej! \nTu nasze drogi sie rozchodza." << endl;
                cout << "\n# Odpychasz stojacego Kapitana i biegniesz dalej w strone dymiacego miasta." << endl;
                cout << "# Zaczynasz dostrzegac toczaca sie w oddali walke." << endl;
                cout << "# Jestes na srodku zrujnowanego placu, dostrzegasz, \n# ze z pewnoscia byl on miejscem walki." << endl;
                cout << "\n------------------- Nacisnij Enter aby kontynuowac -------------------" << endl;
            system("read");
                }
                break;
                    
                default:
                {
                cout << "\nCos robisz zle wojowniku! Wybierz '1' lub '2' nie ma dla Ciebie innej drogi!" << endl;
                cout << endl;
                cout << "\n------------------- Nacisnij Enter aby kontynuowac -------------------" << endl;
            system("read");
                    goto PowrotwyborSciezkiDwa;
                }
                    break;
                }
                break;
            }
                
    case 2:
    {
    system("clear");
    cout << "\n!!!----------------------Rozdzial I: Ucieczka----------------------!!!" << endl;
    cout << endl;
    cout << ImieGracza << ": Sam znajde droge ucieczki!" << endl;
    cout << "Kapitan Strazy: Jestes szalony. Zabija Cie tam!" << endl;
    cout << ImieGracza << ": Mam swoje tajemnice i potrafie o siebie zadbac." << endl;
    cout << "# Przeskakujesz przez polamane deski w ogrodzeniu" << endl;
    cout << "# i biegiem rzucasz sie w kierunku bram miasta." << endl;
    }
    break;
                
    default:
    {   //sprawdzanie zeby gracz nie kliknal innego numeru lub litery niz z wyboru menu
        if(cin.fail())
        {
            cin.clear();
            cin.ignore();
            cout << "Cos robisz zle wojowniku! Wybierz '1' lub '2' nie ma dla Ciebie innej drogi!\n" << endl;
            goto retry;
        } else
        {
            cout << "Cos robisz zle wojowniku! Wybierz '1' lub '2' nie ma dla Ciebie innej drogi!" << endl;
            goto retry;
        }
    }
    }
    return 0;
}

//rozdzial I
void G1_1()
{
    
}
