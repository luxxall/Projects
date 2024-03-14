#include <iostream>
using namespace std;

int LastDigit(long long a)
{
    int digit;
    //this separates last digit from number
    digit = a % 10;

    return digit;
}

int main()
{
    //varaibles
    int Tests, a, b;

    //input nr of tests
    cin >> Tests;

    //varaible for number of outputs and bufor for inside loop of adding
    int Output[Tests];
    long long Bufor;

    //loop for running tests
    for(int Loop=0;Loop<Tests;Loop++)
    {
        cin >> a >> b;

        //reset bufor for next loop
        Bufor=1;
        
        //loop to do expotentiate
        for(int Loop2=0;Loop2<b;Loop2++)
        {
            //bufor rises by multiplate by a
            Bufor*=a;
        }
        
        //separate last digit
        Output[Loop]=LastDigit(Bufor);
    }

    //loop for output
    for(int Loop3=0;Loop3<Tests;Loop3++)
    {
        cout << Output[Loop3] << endl;
    }

    return 0;
}