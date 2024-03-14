#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // TODO: Prompt for start size
    int StartSize;
    do
    {
        StartSize = get_int("Start size: ");
    }
    while (StartSize < 9);

    // TODO: Prompt for end size
    int EndSize;
    do
    {
        EndSize = get_int("End size: ");
    }
    while (EndSize < StartSize);

    // TODO: Calculate number of years until we reach threshold
    int Years = 0;
    int llamas = StartSize;

    if (EndSize != StartSize)
    {
        do
        {
            llamas += (llamas / 3) - (llamas / 4);
            Years++;
        }
        while (llamas < EndSize);
    }

    // TODO: Print number of years
    printf("Years: %i\n", Years);
}
