#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    // Define a byte
    typedef uint8_t byte;

    // Checks for a single command line argument
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // opens file to read
    FILE *file = fopen(argv[1], "r");

    // Cannot be opened for reading
    if (file == NULL)
    {
        printf("Failed: %s could not be opened.\n", argv[1]);
        return 1;
    }

    int count = -1;
    FILE *img = NULL;
    byte buffer[512];
    char str[8];

    // repeat until end of card
    while (fread(buffer, 1, 512, file) == 512)
    {
        //check if start of a new JPEG
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // close already open file and start writing new one
            if (img != NULL)
            {
                fclose(img);
            }

            // to number the JPEGs
            count ++;

            sprintf(str, "%03i.jpg", count);

            // open file
            img = fopen(str, "w");

            // start writing
            fwrite(buffer, 1, 512, img);
        }

        else
        {
            if (img != NULL)
            {
                fwrite(buffer, 1, 512, img);
            }
        }
    }

    // closes input file
    fclose(file);

    // closes output file
    fclose(img);

    return 0;
}
