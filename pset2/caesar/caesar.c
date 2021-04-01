#include <stdio.h>
#include <string.h>
#include <cs50.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        //going through key char by char
        for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            //terminates when encounters character other than positive digit
            if (argv[1][i] < '0' || argv[1][i] > '9')
            {
                printf("Usage: ./caesar key\n");
                return 1;
            }
        }
    }
    //terminates when incorrect number of command line arguments passed
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    //key
    int k = atoi(argv[1]);

    //terminates when key is non-positive
    if (k < 0)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

    else
    {
        k = k % 26;
        string pt = get_string("plaintext: ");
        printf("ciphertext: ");
        int ct[strlen(pt)];

        //running program char by char for plaintext
        for (int i = 0, n = strlen(pt); i < n; i++)
        {
            //lower-case
            if (pt[i] <= 'z' && pt[i] >= 'a')
            {

                ct[i] = (pt[i]) + k;

                //to warp after z
                if (ct[i] > 'z')
                {
                    ct[i] -= 26;
                    printf("%c", ct[i]);
                }
                //no warping
                else
                {
                    printf("%c", ct[i]);
                }
            }

            //upper-case
            else if (pt[i] <= 'Z' && pt[i] >= 'A')
            {

                ct[i] = (pt[i]) + k;

                //to warp after Z
                if (ct[i] > 'Z')
                {
                    ct[i] -= 26;
                    printf("%c", ct[i]);
                }
                //no warping
                else
                {
                    printf("%c", ct[i]);
                }
            }

            //other charcters
            else
            {
                ct[i] = (pt[i]);
                printf("%c", ct[i]);
            }
        }

        printf("\n");
        return 0;
    }

}
