	//
//  main.cpp
//  friends
//
//  Created by Łukasz Śliwiński on 15.11.22.
//

#include <iostream> //do obslugi strumienie wejscia i wyjscia
#include <cstdlib> //do funkcji exit(0)
#include <string> //do obslugi transform
#include <algorithm> //do obslugi funckji transform
using namespace std; //zeby nie pisac za kazdym razem std

int main()
{
    system("clear");
    
    string Imie;
    string Nazwisko;
    
    cout << "Podaj swoje imie i nazwisko: " << endl;
    cout << "Imie: ";
    cin >> Imie;
    cout << "Nazwisko: ";
    cin >> Nazwisko;
    
    int DlugoscImienia=Imie.length(); //sprawdza jaka dlugosc ma wpisane imie
    int DlugoscNazwiska=Nazwisko.length(); //sprawdza dlugosc nazwiska
    cout << "Twoje inicjaly to: " << Imie[0] << ". " << Nazwisko[0] << ". " << endl; //inicjaly czyli pierwsze szufladki z tablicy jaka jest string imie i nazwisko
    
    transform(Imie.begin(), Imie.end(), Imie.begin(), :: toupper);
    cout << "Od tylu nazywasz sie: " << endl;
    for(int i=DlugoscImienia-1; i>=0; i--)
    {
        cout << Imie[i];
    }
    cout << " ";
    
    transform(Nazwisko.begin(), Nazwisko.end(), Nazwisko.begin(), :: toupper);
    for(int i=DlugoscNazwiska-1; i>=0; i--)
    {
        cout << Nazwisko[i];
    }
    cout << endl;
    
    
        return 0;
}