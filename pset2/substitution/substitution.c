#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <cs50.h>

int main (int argc, string argv[])
{
    //terminates when incorrect number of command line arguments
    if (argc != 2)
    {
        printf(" Usage: ./substitution key\n");
        return 1;
    }

    else
    {
        //length of key
        int n = strlen(argv[1]);

        if (n != 26)
        {
            printf("Key must contain 26 characters.\n");
            return 1;
        }

        else
        {
            //keys obtained will be stored here if program doesn't terminate
            char uk[n];
            char lk[n];


            //char by char for key
            for (int i = 0; i < n; i++)
            {

                //all alphabets
                if (isalpha(argv[1][i]) == 0)
                {
                    printf("Key must contain only alphabets.\n");
                    return 1;
                }

                //no repetitions
                for (int y = 0; y < i; y++)
                {
                    if (argv[1][i] == argv[1][y])
                    {
                        printf("Key must not contain duplicate characters.\n");
                        return 1;
                    }
                }

                //key obtained

                //generates separate keys for upper and lower
                uk[i] = toupper(argv[1][i]);
                lk[i] = tolower(argv[1][i]);
            }

            //obtain text
            string pt = get_string("plaintext: ");
            printf("ciphertext: ");

            for (int x = 0, m = strlen(pt); x < m; x++)
            {
                //upper case letters
                if (isupper(pt[x]) != 0)
                {
                    int u_index = pt[x] - 65;
                    printf("%c", uk[u_index]);
                }

                //lower case letters
                else if (islower(pt[x]) != 0)
                {
                    int l_index = pt[x] - 97;
                    printf("%c", lk[l_index]);
                }

                //other characters
                else
                {
                    printf("%c", pt[x]);
                }
            }

            printf("\n");
            return 0;
        }
    }
}
