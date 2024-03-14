	//
//  main.cpp
//  friends
//
//  Created by Łukasz Śliwiński on 15.11.22.
//

#include <iostream> //do obslugi strumienie wejscia i wyjscia
#include <cstdlib> //do funkcji exit(0)
#include <fstream> //do pracy z zewnetrznymi plikami
#include <string> //do obslugi transform
#include <algorithm> //do obslugi funckji transform
using namespace std; //zeby nie pisac za kazdym razem std

float Euro; //zmienna do wpisania wartosci poczatkowej euro
//zmiana kursu euro na pln
float Zloty(float PLN) //funkcja Zloty ktora w pozniejszym main pobiera wpisana liczbe i mnozy ja razy kurs euro po czym zwraca wartosc przeliczona. w () jest argument funkcji. argument jest dla funkcji zmienna do ktorej bedzie on pobieral podana pozniej liczbe i na niej wykonywal operacje. Czyli w tym wypadku do zmiennej PLN wpisze wartosc wpisana od uzytkownika i w nowej zmiennej Przeliczenie pomnozy dane z PLN przez 4.7. Na koncu zwroci wartosc Przeliczenie
{
    float Przeliczenie = PLN * 4.7;
    return Przeliczenie;
}
//zmiana kursu euro na dolary
float Dolar(float USD)
{
    return USD * 1.04; //to samo co wyzej ale bez uzywania pomocniczej zmiennej. po prostu przy zwracaniu wyniku program mnozy argument przez podana liczbe
}
//zmiana kursu euro na funty
void Funt(float GBP) //to jest funkcja ktora nie zwraca wyniku. to znaczy ze przeprowadza jakies dzialanie ale nie musi zwrocic zadnego wyniku. w tym przykladzie aby uzyc voida i moc zwrocic wartosc po przeliczeniu trzeba bylo uzyc cout zeby wyswietlic wynik na ekranie
{
    cout << "W przeliczeniu na funty: " << GBP * 0.87 << endl;
}
int main()
{
    for(;;) //nieskonczona petla aby program ciagle sie powtarzal
    {
        system("clear"); //czyszcze ekran
        cout << "Podaj ile chcesz przeliczyc Euro: ";
        cin >> Euro; //wpisujemy wartosc zmiennej euro
        
        cout << "W przeliczeniu na zlotowki: " << Zloty(Euro) << endl; //wywolujemy funkcje i w nawiasach () wpisujemy wartosc ktora ma byc uzyta do przeliczenia dla funkcji
        cout << "W przelcizeniu na dolary: " << Dolar(Euro) << endl; //to samo co wyzej ale dla innej funkcji
        Funt(Euro); //poniewaz w kodzie funkcji jesdt juz cout ktory wyswietla napis i wynik, nie trzeba go znowu wpisywac. w takim przypadku funkcje wywoluje po prostu po jej nazwie
        
        system( "read -n 1 -s -p \"Nacisnij dowolny klawisz aby kontynuowac...\" " ); //aby petla sie skocnzyla trzeba nacisnac przycisk
    }
        return 0;
}