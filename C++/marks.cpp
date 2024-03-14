#include <iostream> //do obslugi strumienie wejscia i wyjscia
#include <cstdlib> //do funkcji exit(÷≥0)
#include <ncurses.h>//do obslugi getchar()
using namespace std; //zeby nie pisac za kazdym razem std

int main()
{
    system("clear");
    
    int ile_ocen;
    float oceny[ile_ocen]; //robimy tablice z ocenami ile wpiszemy
    float suma, srednia;
    
    cout << "Ile ocen chcesz wpisac do programu? " << endl;
    cin >> ile_ocen;
    cout << "Podaj oceny a program wyliczy ich srednia!" << endl;
    
    for (int i=0; i<ile_ocen; i++) //petla dzieki ktorej mozemy wpisywac oceny do tablic, poniewaz mamy 5 szufladek w talibcy to petla wykona sie do i<5
    {
        
            cout << "Podaj " << i+1 << " ocene: " << endl; //za kazdym obrotem petli zwieksza sie "i" wiec widzimy ktora ocene aktualnie wpisujemy, +1 poniewaz liczymy od 0 a chcemy liczyc od 1
            cin >> oceny[i]; //wpisujemy oceny to talic. kazdy obrot petli powoduje zwiekszenie sie i o 1 czyli tak jak numer szufladki w petli. Dzieki temu za kazdem wpisaniem oceny jesdt ona wpisywana do szufladki o 1 wiekszej od poprzedniej
        if((oceny[i]>6)||(oceny[i]<1)) //if ktory sprawdza czy ocena nie jest wieksza niz 6 i mniejsza niz 1
        {
            cout << "Podales bledna ocene, podaj poprawna: " << endl;
            i--;
        }
        else
            suma += oceny[i]; //zapis =+ znaczy do tego co juz jest dodaj... ten sam zapis to: suma = suma + oceny[i]. W tej linijce
    }
    
    cout << "Srednia ocen to: " << suma/ile_ocen << endl; //wyliczenie sredniej
    system( "read -n 1 -s -p \"Nacisnij dowolny klawisz aby kontynuowac...\"" );
    
    //suma = oceny[1] + oceny[2] + oceny[3] + oceny[4] + oceny[5]; - mozna w taki sposob policzyc sume ale duzo szybszy i lepszy sposob jest za pomoca petli
    
    return 0;
    
}