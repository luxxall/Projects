#include <iostream>
using namespace std;

int main()
{

    int Tests, ileNumbers;

    //nr of tests
    cin >> Tests;

    //outside loop to run tests
    for(int i=0;i<Tests;i++)
    {
        //how many numbers;
        cin >> ileNumbers;

        int Numbers[ileNumbers];

        //inside loop to insert numbers
        for(int j=0;j<ileNumbers;j++)
        {
            cin >> Numbers[j];
        }

        //loop to output reverse
        for(int l=ileNumbers-1;l>=0;l--)
        {
            cout << Numbers[l] << " ";
        }
        //to make new line after tests
        cout << endl;

    }

    return 0;
}