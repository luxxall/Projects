#include <iostream>
using namespace std;

int main() {
    
    //zmienne okreslajace liczbe zestawow, ile liczb, liczby, sume i tablice sumy
    int t, x, n, suma, pom[9999];
    cin >> t;
    
    //petla zewnetrzna do wykonania liczby zestawow
    for(int i=0;i<t;i++)
    {
        //okreslenie ile bedzie cyfr do dodawania
        suma=0;
        cin >> n;
        
        //petla wewnetrzna do wpisania cyfr do dodania oraz liczaca sume
        for(int j=0;j<n;j++)
        {
            cin >> x;
            suma+=x;
        }
        
        //wpisanie sumy z kazdej petli do zmiennej pom
        pom[i]=suma;
    }

    //wypisanie wynikow
    for(int m=0;m<t;m++)
    {
        cout << pom[m] << endl;
    }
    
    return 0;
}