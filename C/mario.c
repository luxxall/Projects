#include <cs50.h>
#include <stdio.h>

//declaration of void to shift place of # as tower rises
void Spaces(int Amount);

//declaration of void to draw amount of #
void Draw(int Amount);

//declaration of void to draw space between towers
void Between();

int main(void)
{
    //User inputs towers height
    int Height;
    do
    {
        Height = get_int("Height: ");
    }
    while (Height > 8 || Height < 1);

    //varaible to shift spaces
    int Amount = Height;
    int Amount2 = 1;

    //loop for drawing
    for (int i = 0; i < Height; i++)
    {
        //draw spaces for each row
        Spaces(Amount);
        Amount -= 1;

        //draw # of left tower for each row
        Draw(Amount2);
        Amount2 += 1;

        //space between towers
        Between();

        //draw right tower for each row
        Draw(Amount2 - 1);

        //go to another row
        printf("\n");
    }
}

//body of void to shift place of #
void Spaces(int Amount)
{
    for (int i = 0; i < Amount - 1; i++)
    {
        printf(" ");
    }
}

//body of void to draw #
void Draw(int Amount)
{
    for (int i = 0; i < Amount; i++)
    {
        printf("#");
    }
}

//draw space between towers
void Between()
{
    printf("  ");
}