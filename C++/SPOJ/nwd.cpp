#include <iostream>
using namespace std;

int NWD(int a, int b)
{
    int pom;
    pom = a%b;

    while(b!=0)
    {
        pom=a%b;
        a=b;
        b=pom;
    }

    return a;
}

int main()
{
    //varaibles
    int Tests, a, b;

    //input nr of tests
    cin >> Tests;

    //varaible for number of outputs
    int Output[Tests];

    //loop for running tests
    for(int Loop=0;Loop<Tests;Loop++)
    {
        cin >> a >> b;
        Output[Loop] = NWD(a,b);
    }

    //loop for output
    for(int Loop2=0;Loop2<Tests;Loop2++)
    {
        cout << Output[Loop2] << endl;
    }

    return 0;
}