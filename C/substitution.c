#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//check if key has valid length
int KeyLength(string Key);

//check if each key character is alfabetical
bool KeyCharacterCheck(string argv[]);

//check if key has no repetition of letters
bool KeyRepetitionCheck(string Key);

int main(int argc, string argv[])
{
    string Key = argv[1];

    //check if input is correct
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    else if (KeyLength(Key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    else if (KeyCharacterCheck(argv) == 0)
    {
        printf("Key must contain only alphabetical letters.\n");
        return 1;
    }
    else if (KeyRepetitionCheck(Key) == 1)
    {
        printf("Key must not contain repeated characters.\n");
        return 1;
    }

    //make key upper letters
    char UpKey[25];
    for (int i = 0; i < 26; i++)
    {
        UpKey[i] = toupper(Key[i]);
    }
    //make key lower letters
    char LowKey[25];
    for (int j = 0; j < 26; j++)
    {
        LowKey[j] = tolower(Key[j]);
    }

    //get normal text from user if key is valid
    string PlainText = get_string("plain text: ");

    //check lengnth of normal text
    int WordLength = strlen(PlainText);

    //variable for ciphertext
    char CipherText[100];

    //general loop for each letter
    for (int Loop = 0; Loop < WordLength; Loop++)
    {
        //reset position of letter in key
        int Position = 0;
        //check if letter from plain text is upper
        if (PlainText[Loop] >= 65 && PlainText[Loop] <= 90)
        {
            int Alphabet = 65;
            //loop to search for letter and if found sign it to letter from key on its order
            do
            {
                if (PlainText[Loop] != Alphabet)
                {
                    Alphabet++;
                    Position++;
                }
                else
                {
                    CipherText[Loop] = UpKey[Position];
                }
            }
            while (CipherText[Loop] != UpKey[Position] && Alphabet <= 90);
        }
        //check if letter from plain text is lower
        else if (PlainText[Loop] >= 97 && PlainText[Loop] <= 122)
        {
            int Alphabet2 = 97;
            //loop to search for letter and if found sign it to letter from key on its order
            do
            {
                if (PlainText[Loop] != Alphabet2)
                {
                    Alphabet2++;
                    Position++;
                }
                else
                {
                    CipherText[Loop] = LowKey[Position];
                }
            }
            while (CipherText[Loop] != LowKey[Position] && Alphabet2 <= 122);
        }
        //if sign in plain text is not a letter just sign it to cipher without changing
        else
        {
            CipherText[Loop] = PlainText[Loop];
        }
    }

    printf("ciphertext: %s\n", CipherText);

}

//check if key has valid length
int KeyLength(string Key)
{
    //check length of CLI
    int KeyLength = strlen(Key);

    return KeyLength;
}

//check if each key character is alfabetical
bool KeyCharacterCheck(string argv[])
{
    int Loop = 25;
    bool Letter = true;
    do
    {
        if (argv[1][Loop] >= 65 && argv[1][Loop] <= 90)
        {
            Loop--;
        }
        else if (argv[1][Loop] >= 97 && argv[1][Loop] <= 122)
        {
            Loop--;
        }
        else
        {
            Letter = false;
        }
    }
    while (Letter != false && Loop >= 0);

    return Letter;
}

//check if key has no repetition of letters
bool KeyRepetitionCheck(string Key)
{
    int Loop = 0;
    int Letter = 1;
    int KeyLength = 25;
    bool Repetition = false;
    do
    {
        if (Key[Loop] == Key[Letter])
        {
            Repetition = true;
        }
        else if (Key[Loop] != Key[Letter] && Letter < KeyLength)
        {
            Letter++;
        }
        else if (Letter == KeyLength)
        {
            Loop++;
            Letter = Loop + 1;
        }
    }
    while (Repetition != true && Loop != KeyLength);

    return Repetition;
}
