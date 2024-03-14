//
//  main.cpp
//  friends
//
//  Created by Łukasz Śliwiński on 15.11.22.
//

#include <iostream> //do obslugi strumienie wejscia i wyjscia
#include <cstdio> //tez do obslugi getchar()
#include <cstdlib> //do funkcji exit(0)
#include <curses.h>//do obslugi getchar()
#include <ncurses.h>//do obslugi getchar()
#include <limits> //zdejmuje limit znakow cin.clear
using namespace std; //zeby nie pisac za kazdym razem std

int main(int argc, const char * argv[]) {
    
    int a, b;
    system("clear");
    cout << "Podaj liczby A i B a program wykona dzialania matematyczne: " << endl;
    cout << "Liczba A: " << endl;
    cin >> a;
    cout << "Liczba B: " << endl;
    cin >> b;
    system("clear");
    
    int wybor;
    do
    {
        system("clear");
        cout << "Wpisane liczby: " << a << " oraz " << b << endl;
        cout << "Wybierz opcje: " << endl;
        cout << "W jakiej kolejnosci liczy maja byc wykonywane?" << endl;
        cout << "1. A <> B " << endl;
        cout << "2. B <> A " << endl;
        cout << "3. Wyjście z programu " << endl;
        cin >> wybor;
        
        switch (wybor)
        {
            case 1:
                if (wybor == 1)
                {
                    cout << "Opcja pierwsza: " << a << " <> " << b << endl;
                    cout << "Mnozenie: " << a*b << endl;
                    cout << "Dzielenie: " << a/b << endl;
                    cout << "Dodawanie: " << a+b << endl;
                    cout << "Odejmowanie: " << a-b << endl;
                    cout << "Wcisnij przycisk aby kontynuowac..." << endl;
                    system("read -n1 -p ' ' key");
                    cout << endl;
                }
                break;
                
            case 2:
                if (wybor == 2)
                {
                    cout << "Opcja druga: " << b << " <> " << a << endl;
                    cout << "Mnozenie: " << b*a << endl;
                    cout << "Dzielenie: " << b/a << endl;
                    cout << "Dodawanie: " << b+a << endl;
                    cout << "Odejmowanie: " << b-a << endl;
                    cout << "Wcisnij przycisk aby kontynuowac..." << endl;
                    system("read -n1 -p ' ' key");
                    cout << endl;
                }
            break;
                
            case 3:
                system("clear");
                cout << "Program zamkniety. " << endl;
                return 0;
                break;
                
            default:
                cout << "Bledny wybor, sprobuj ponownie..." << endl;
                cout << "Wcisnij przycisk aby kontynuowac..." << endl;
                system("read -n1 -p ' ' key");
        }
    } while (wybor != 3);
        
        return 0;
    }