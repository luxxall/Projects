#include <iostream> //do obslugi strumienie wejscia i wyjscia
#include <cstdlib> //do funkcji exit(0)
#include <ctime> //do obslugi sleep
#include <stdio.h>
#include <ncurses.h>//do obslugi getchar()
using namespace std; //zeby nie pisac za kazdym razem std

int main()
{
    system("clear");
    
    int liczba;
    int powtorzenia=0;
    int strzal;
    
    srand(time(NULL));
    liczba = rand()%100+1;
    
    cout << "Wybralem liczbe miedzy 1 a 100, zgadnij jaka to liczba... " << endl;
    while (strzal!=liczba)
    {
        cout << "To twoja: " << powtorzenia+1 << " proba " << endl;
        cin >> strzal;
        powtorzenia++;
        
        if(strzal<liczba)
            cout << "Wylosowana liczba jest wieksza " << endl;
        else if(strzal>liczba)
            cout << "Wylosowana liczba jest mniejsza " << endl;
        else if(strzal==liczba)
        {
            cout << "Brawo trafiles wylosowana liczbe! " << endl;
            cout << "\a" << endl;
            cout << "Zgadles za " << powtorzenia << " razem! " << endl;
            system( "read -n 1 -s -p \"Nacisnij dowolny klawisz aby kontynuowac...\"" );
        }
    }
    
    return 0;
    
}