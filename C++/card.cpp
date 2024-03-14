	//
//  main.cpp
//  friends
//
//  Created by Łukasz Śliwiński on 15.11.22.
//

#include <iostream> //do obslugi strumienie wejscia i wyjscia
#include <cstdio> //tez do obslugi getchar()
#include <cstdlib> //do funkcji exit(0)
#include <ctime> //do obslugi sleep
#include <stdio.h> //do getchar()
#include <iomanip> //do setprecision()
#include <fstream> //do pracy z zewnetrznymi plikami
#include <limits> //zdejmuje limit znakow cin.clear
using namespace std; //zeby nie pisac za kazdym razem std

int main() {

    string linia; //zmienna w ktorej bedziem zapisany tekst pobrany z pliku zewnetrznego
    int nr_linii=1; //do zmiennej nr_lini ktora bedzie odpowiadala za numer lini pobranego tekstu przypisujemy wartosc 1 poniewaz linie pobrane z pliku zewnetrznego zaczynaja sie od 1 wiec numer pierwszej lini z ktorej pobierzemy teskt to 1
    string imie; //do tej zmiennej bedzie wpisany tekst z 1 lini tekstu zewnetrzengo poniewaz wiemy ze jest tam wpisane imie
    string nazwisko; //do tej zmiennej bedzie wpisany tekst z 2 lini tekstu zewnetrzengo poniewaz wiemy ze jest tam wpisane nazwisko
    int nr_tel; //do tej zmiennej bedzie wpisany tekst z 3 lini tekstu zewnetrzengo poniewaz wiemy ze jest tam wpisany nr telefonu
    
    fstream plik; //tworzymy zmienna do obslugi pliku zewnetrznego o nazwie plik. dzieki temu program wie jak nazywa sie nasz plik zewnetrzny
    
    plik.open("wizytowka.txt", ios::in); //otwieramy wejscie do pliku i odczytujemy z niego dane
    while(getline(plik, linia)) //poniewaz wiemy ze funkcja getline(pobiera dane ze zemiennej plik, i wpisuje pobrane dane do zmiennej o nazwie linia) zwraca wartosc true jesli udalo sie pobrac linie i false jesli nie udalo sie pobrac tesktu. mozna wpisac getline jako wartosc do petli while. petla bedzie sie wykonywala dopoki uda sie pobrac funkcji getline tekst ze zmiennej plik.
    {
        switch(nr_linii) //switch pozwala w zaleznosci od numeru lini ktora pobieramy z pliku zewnetrznego przypisac ta wartosc do odpowiedniej zmiennej. czyli wiemy ze zmienna nr_linii ma wartosc poczatkowa 1, wiec pierwsza opcja switcha czyli case 1 wykona sie na poczatku i przypisze tekst z pierwszej lini do zmiennej imie. kolejna petla bedzie miala wartosc 2 poniewaz program po pobraniu tekstu z pierwszej lini przejdzie do nastepnej. i potem kolejny raz program pobierze tekst z nastepnej lini czyli 3. nie ma wariantu 4 poniewaz wiemy ze w zapisanym tekscie sa tylko 3 linie
        {
            case 1: imie=linia; break; //pierwsza petla przypisuje dane ze zmiennej linia w ktorej jest pierwsza linia z tekstu zewnetrznego do zmiennej imie
            case 2: nazwisko=linia; break; //poniewaz dane z pierwszej lini tekstu z pliku zewnetrzenego sa juz zapisane w zmiennej imie, mozemy nadpisac dane w tej zmiennej i w drugiej petli po pobraniu tekstu z drugiej lini tekstu z pliku zewnetrznego program moze przypisac je do zmiennej nazwisko
            case 3: nr_tel=atoi(linia.c_str()); break; //ponownie nadpisujemy dane w zmiennej linia i przypisujemy dane z 3 lini tekstu z pliku zewnetrznego do zmiennej nr_tel. skoro wiemy ze jest tam numer telefonu a funkcja getline za kazdym razem zapisuje dane jak typ string to funkcja atoi pozwala na przekonwertowanie tej zmiennej na int.
        }
        nr_linii++; //zwiekszamy numer lini z ktorej pobieramy tekst z pliku zewnetrznego za kazdym razem jak tekst ten zostanie pobrany i przypisany do odpowiedniej zmiennej. czyli program pobiera teskt z pierwszej linii z tekstu zewnetrznego i przypisuje go do zmiennej imie, po czym zwieksza wartosc zmiennej nr_linii na 2 i pobiera dane z drugiej linii tekstu zewnetrznego i przypisuje je do zmiennej nazwisko. tak samo z nr telefonu.
    }
    plik.close(); //po wpisaniu danych do ploku zamykamy go aby zapobiec wycieku danych
    
    cout << imie << endl;
    cout << nazwisko << endl;
    cout << nr_tel << endl;
    
        return 0;
    }