#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

const int BLOCK_SIZE = 512;
typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check correct command line argument
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open a file to read and check if exists
    char *input_filename = argv[1];
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // varaibles
    BYTE buffer[BLOCK_SIZE];
    FILE *output = NULL;
    char output_name[8];
    int file_count = 0;

    // loop checks freads value if less than BLOCK_SIZE then original file is done
    while (fread(&buffer, BLOCK_SIZE, 1, input) == 1)
    {
        // check is first bytes of a file in 512 block are pattern of a new jpg file
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // if thats not first jpg then close one before
            if (!(file_count == 0))
            {
                fclose(output);
            }

            // make a new file for jpg
            sprintf(output_name, "%03i.jpg", file_count);
            output = fopen(output_name, "w");
            file_count++;
        }

        // rewrite data to a new jpg intil next jpg found
        if (!(file_count == 0))
        {
            fwrite(&buffer, BLOCK_SIZE, 1, output);
        }
    }

    fclose(input);
    fclose(output);

    return 0;
}