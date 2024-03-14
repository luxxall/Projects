#include <iostream>
using namespace std;

//funkcja wliczajaca NWD ktore jest potrzebne do wzoru na NNW
int NWD(int a, int b)
{
    int pom;
    while(b!=0)
    {
        pom = b;
        b = a%b;
        a = pom;
    }
    return a;
}

int main() {
    
    //zmienna okreslajaca liczbe zestawow
    int n;
    cin >> n;
    
    //zmienne z liczba dzieci w grupach zapisane w tablicach
    int a[n], b[n];
    
    //petla wypisuje do a i b liczbe dzieci i zapisuje wynik w tablicy
    for(int i=0;i<n;i++)
    {
        cin >> a[i] >> b[i];
    }
    
    //obliczenie NNW przez wzor
    for(int i=0;i<n;i++)
    {
        cout << (a[i]*b[i])/NWD(a[i], b[i]) << endl;
    }
    
    return 0;
}