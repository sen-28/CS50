#include <stdio.h>
#include <cs50.h>

int get_height(void);

int main(void)
{
   int h = get_height();

   for (int i = 1; i <= h; i++)
   {
        //to insert spaces
       for (int m = 1; m <= h-i; m++)
       {
           printf(" ");
       }

       //to insert 1st #
       for(int m = 1; m <= i; m++)
       {
           printf("#");
       }

       //to insert space b/w towers
       printf("  ");

       //to insert 2nd #
       for(int m = 1; m <= i; m++)
       {
           printf("#");
       }

       //to break line
       printf("\n");
   }
}

//function to limit height from 1 to 8
int get_height(void)
{
    int n;

    do
    {
        n = get_int("Height:");
    }
    while (n < 1 || n > 8);

    return n;

}
