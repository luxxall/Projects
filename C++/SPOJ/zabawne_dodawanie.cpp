#include <iostream>
using namespace std;

//reverse the number
int reverse(int num)
{   //variables
     int digit, rev = 0;

     do
     {   //separate the last number
         digit = num % 10;
         //check on which posioion it should be, thusands, hundreds etc and add last number
         rev = (rev * 10) + digit;
         //check if any number left to reberse
         num = num / 10;
     } while (num != 0);
     //returning the reverse of original number
     return rev;
}

//adding rev and original number
int adding(int rev, int num)
{   
    int add = rev + num;
    //returning the score of adding
    return add;
}

//check if number is palindrome
bool check(int n, int num)
{
    if(n == num)
    {   //if number is palindrome
        return true;
    }
    else
    {   //if its not a palindrome
        return false;
    }
}


int main() {
    
    //variables
    int t, num, pom[99], loop[99];
    //enter number of tests
    cin >> t;
    //loop for tests
    for(int i=0;i<t;i++)
    {   //enter your number to check
        cin >> num;
        //if check is positive and number is palindrome sign it to pom and loop is 0 
        if(check(reverse(num),num)==true)
        {
            pom[i] = reverse(num);
            loop[i] = 0;
        }
        else
        {   //if the number is not palindrome do adding original number and reverse of the number
            int after = adding(reverse(num),num);
            //its a first loop of adding
            loop[i]=1;
            //loop that does adding resut from adding previous numbers as far as the result will be palindrome
            while(check(reverse(after),after)!=1)
            {
                after = adding(reverse(after),after);
                loop[i]++;
            }
            //when we found result of adding that is palindrome sign it to pom
            pom[i] = after;
        }

    }
    //loop to show the results
    for(int j=0;j<t;j++)
    {
        cout << pom[j] << " " << loop[j] << endl;
    }
    
    return 0;
}