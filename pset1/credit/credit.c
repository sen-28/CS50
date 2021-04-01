#include <stdio.h>
#include <cs50.h>

int sum(long);
int dg(long);
int td(long);
int od(long);


int main()
{
    long x = get_long("Number: ");
    int s = sum(x);
    int dig = dg(x);
    int twodig = td(x);
    int onedig = od(x);

    if (s % 10 == 0)
    {
        //AMEX
        if (dig == 15 && (twodig == 34 || twodig == 37))
        {
            printf("AMEX\n");
        }

        //MASTERCARD
        else if (dig == 16 && (twodig == 51 || twodig == 52 || twodig == 53 || twodig == 54 || twodig == 55))
        {
            printf("MASTERCARD\n");
        }

        //VISA
        else if ((dig == 13 || dig == 16) && onedig == 4)
        {
            printf("VISA\n");
        }

        else
        {
        printf("INVALID\n");

        }
    }

    else
    {
        printf("INVALID\n");
    }

}

//to find sum
int sum(long n)
{
    int sum_odd = 0;
    int sum_even = 0;

    for (int i = 1; n > 0 ; i++)
    {
       //odd sum
       sum_odd+= n % 10;

       //to get to next digit
       n-= n % 10;
       n /= 10;

       //even sum
       int m = (n % 10)*2;
       sum_even += m % 10;
       m-= m % 10;
       m /= 10;
       sum_even += m %10;

        //to get to next digit
        n-= n % 10;
        n/= 10;
    }

    return sum_odd + sum_even;
}


// to find number of digits in the number
int dg(long n)
{
    int dig;
    for(dig = 0; n > 0; dig++)
    {
        n-= n % 10;
        n/= 10;
    }

    return dig;
}


//to find first two digits
int td(long n)
{
    for (int i = 1; n > 99; i++)
    {
        n-= n % 10;
        n/= 10;
    }
    return n;
}


//to find first one digit
int od(long n)
{
    for (int i = 1; n > 9; i++)
    {
        n-= n % 10;
        n/= 10;
    }
    return n;
}
