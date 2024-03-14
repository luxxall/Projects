	//
//  main.cpp
//  friends
//
//  Created by Łukasz Śliwiński on 15.11.22.
//

#include <iostream> //do obslugi strumienie wejscia i wyjscia
#include <cstdio> //tez do obslugi getchar()
#include <cstdlib> //do funkcji exit(0)
#include <stdio.h> //do getchar()
#include <limits> //zdejmuje limit znakow cin.clear
using namespace std; //zeby nie pisac za kazdym razem std

int a,b;
char wybor;

int main() {
    for(;;)
{
    system("clear");
    cout << "Podaj 2 liczby a nastepnie wybierz rodzaj dzialania: \n";
    cout << "Wpisz pierwsza liczbe: ";
    cin >> a;
    while(cin.fail()) //jesli w miejsce cin >> a zostanie wpisany inny znak niz libcza to petla pokazue ze jest blad, czysci bufory cin i znowu daje do wpisania poprawna liczbe
    {
        cout << "To nie jest poprawna liczba!" << endl;
        cin.clear(); //czysci bufor bledu w cin
        cin.ignore(); //czysci bufor cin
        cout << "Wprowadz poprawne dane: ";
        cin >> a;
    }
    cout << "Podaj druga liczbe: ";
    cin >> b;
    while(cin.fail()) ////jesli w miejsce cin >> b zostanie wpisany inny znak niz libcza to petla pokazue ze jest blad, czysci bufory cin i znowu daje do wpisania poprawna liczbe
    {
        cout << "To nie jest poprawna liczba!" << endl;
        cin.clear(); //czysci bufor bledu w cin
        cin.ignore(); //czysci bufor cin
        cout << "Wprowadz poprawne dane: ";
        cin >> b;
    }
    cout << endl;
    cout << "Wybierz rodzaj dzialania: \n";
    cout << endl;
    cout << "1. Mnozenie..." << endl;
    cout << "2. Dzielenie..." << endl;
    cout << "3. Dodawanie..." << endl;
    cout << "4. Odejmowanie..." << endl;
    cout << "5. Wyjscie z programu..." << endl;
    cin.ignore(); //sluzy to czyszczenia danych z cin
    wybor=getchar(); //przypisuje do zmiennej wybor znak z klawiatury przez getchar()
    
    switch(wybor) //wybor opcji zalezy od zmiennej wybor ktora jest znakiem z klawiatury
    {
        case '1': //poniewaz wybor opcji jest zalezny od znaku z klawiatury to nr opcji trzeba zapisac w ' . pojedyncze znaki w c++ zapisujemy w pojedynczych ' '
        {
            cout << "Wynik mnozenia " << a << "*" << b << " to: " << a*b << endl;
            system( "read -n 1 -s -p \"Nacisnij dowolny klawisz aby kontynuowac...\" " );
            break;
        }
        case '2':
        {
            if((a!=0)&&(b!=0))
            {
                cout << "Wynik dzielenia " << a << "/" << b << " to: " << a/b << endl;
                system( "read -n 1 -s -p \"Nacisnij dowolny klawisz aby kontynuowac...\" " );
            }
            else
            {
                cout << "Nie dzielimy przez 0!\n";
                system( "read -n 1 -s -p \"Nacisnij dowolny klawisz aby kontynuowac...\" " );
            }
            break;
        }
        case '3':
        {
            cout << "Wynik dodawania " << a << "+" << b << " to: " << a+b << endl;
            system( "read -n 1 -s -p \"Nacisnij dowolny klawisz aby kontynuowac...\" " );
            break;
        }
        case '4':
        {
            cout << "Wynik odejmowania " << a << "-" << b << " to: " << a-b << endl;
            system( "read -n 1 -s -p \"Nacisnij dowolny klawisz aby kontynuowac...\" " );
            break;
        }
        case '5':
        {
            cout << "Wychodze z programu! \n";
            exit(0);
        }
        default:
        {
            cout << "Takiej opcji nie ma w menu. Sprobuj ponownie!" << endl;
            system( "read -n 1 -s -p \"Nacisnij dowolny klawisz aby kontynuowac...\" " );
        }
            
    }
    

}
        return 0;
    }