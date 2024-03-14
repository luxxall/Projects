#include <cs50.h>
#include <stdio.h>

//check checksum
bool Checksum(long CardNr, int NumberLength);

//check nr of digits in input
int InputLength(long Number);

//Check first numbers to relate brand
bool CorrectNumber(int InputLength);

//separate first two digits
int TwoDigits(long CardNr, int NumberLength);

//separate first digit
int OneDigit(long CardNr);

//check if number is amex, mc or visa
bool AMEX(int NumberLength, int FirstDigits);
bool MASTERCARD(int NumberLength, int FirstDigits);
bool VISA(int NumberLength, int FirstDigit);

int main(void)
{
    //loop to input card number
    long CardNr = get_long("Number: ");
    int NumberLength = InputLength(CardNr);
    int CheckNumbers = TwoDigits(CardNr, NumberLength);
    int CheckOneNumber = OneDigit(CardNr);

    printf("%i\n", TwoDigits(CardNr, NumberLength));

    //condition if input isnt a card nr it returns invalid and exits
    if (CorrectNumber(NumberLength) == 0)
    {
        printf("INVALID\n");
    }
    //if checksum ist 20
    else if (Checksum(CardNr, NumberLength) == 0)
    {
        printf("INVALID\n");
    }
    //if evereything is correct, check first two digits and output card brand
    else if (AMEX(NumberLength, CheckNumbers) == true)
    {
        printf("AMEX\n");
    }
    else if (MASTERCARD(NumberLength, CheckNumbers) == true)
    {
        printf("MASTERCARD\n");
    }
    else if (VISA(NumberLength, CheckOneNumber) == true)
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}

bool Checksum(long CardNr, int NumberLength)
{
    //Loop to separate digits in second to last order, loop does as many times as long the input is
    int Digit;
    int SecondToLast = 0;
    int AddLater = 0;

    for (int i = 0; i < NumberLength; i++)
    {
        Digit = CardNr % 10;
        //sign to Position digits in second to last order
        if (i == 1 || i == 3 || i == 5 || i == 7 || i == 9 || i == 11 || i == 13 || i == 15)
        {
            SecondToLast = (SecondToLast * 10) + Digit;
        }
        //sing to AddLater number that are not later mutiplied but we add them later to checksum
        else if (i == 0 || i == 2 || i == 4 || i == 6 || i == 8 || i == 10 || i == 12 || i == 14 || i == 16)
        {
            AddLater = (AddLater * 10) + Digit;
        }
        //check if any numbers left
        CardNr = CardNr / 10;
    }

    //now loop to multiply every number by 2
    int Multiplied = 0;
    int Digit2;

    do
    {
        //separate digit but this time multiply it by 2
        Digit2 = (SecondToLast % 10) * 2;
        Multiplied = (Multiplied * 10) + Digit2;
        SecondToLast = SecondToLast / 10;
    }
    while (SecondToLast != 0);

    //loop to add every single digit to each other from multiplied one
    int Digit3;
    int Adding = 0;
    int FirstResult = 0;

    do
    {
        Digit3 = Multiplied % 10;
        Adding = (Adding * 10) + Digit3;
        Multiplied = Multiplied / 10;
        //Add each number to varaible FirstNumber and result is sum of addiction
        FirstResult += Digit3;
    }
    while (Multiplied != 0);

    //another loop to add every digit but this time i add digits from AddLater variable
    int Digit4;
    int Adding2 = 0;
    int SecondResult = 0;

    do
    {
        Digit4 = AddLater % 10;
        Adding2 = (Adding2 * 10) + Digit4;
        AddLater = AddLater / 10;
        //Add numbers and sign them to SecondResult variable
        SecondResult += Digit4;
    }
    while (AddLater != 0);

    //return true or false to confirm checksum
    int FinalResult = FirstResult + SecondResult;

    if (FinalResult % 10 != 0)
    {
        return false;
    }
    else
    {
        return true;
    }
}

//check length of number from input
int InputLength(long Number)
{
    //for counting nr of loops and digits
    int Counter = 0;
    do
    {
        Number /= 10;
        Counter++;
    }
    while (Number != 0);

    //how many digits
    return Counter;
}

//check if input matches length
bool CorrectNumber(int NumberLength)
{
    if (NumberLength == 13 || NumberLength == 15 || NumberLength == 16)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//separate first two digits from the number
int TwoDigits(long CardNr, int NumberLength)
{
    //if card number is odd its problem to separate first two numbers, this if detects it
    if (NumberLength == 15 || NumberLength == 13)
    {
        //when number is odd, loop stops after hundreds and devides number by ten to leave only first two digits
        while (CardNr >= 999)
        {
            CardNr /= 100;
        }

        //number with hundreds divided by 10 to separate 2 digits
        CardNr = CardNr / 10;
    }

    //in other way do normal loop to separate two digits
    else if (NumberLength != 15 && NumberLength != 13)
    {
        while (CardNr >= 100)
        {
            CardNr /= 100;
        }
    }
    
    return CardNr;
}

int OneDigit(long CardNr)
{
    while (CardNr >= 10)
    {
        CardNr /= 10;
    }

    return CardNr;
}

//take first two digits and sign them to card brand
bool AMEX(int NumberLength, int FirstDigits)
{
    if (NumberLength != 15)
    {
        return false;
    }
    else if (FirstDigits == 34 || FirstDigits == 37)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//check if mastercard
bool MASTERCARD(int NumberLength, int FirstDigits)
{
    if (NumberLength != 16)
    {
        return false;
    }
    else if (FirstDigits == 51 || FirstDigits == 52 || FirstDigits == 53 || FirstDigits == 54 || FirstDigits == 55)
    {
        return true;
    }
    else
    {
        return false;
    }
}

//check if visa
bool VISA(int NumberLength, int FirstDigit)
{
    if (NumberLength != 13 && NumberLength != 16)
    {
        return false;
    }
    else if (FirstDigit == 4)
    {
        return true;
    }
    else
    {
        return false;
    }
}
