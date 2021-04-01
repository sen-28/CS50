#include <stdio.h>
#include <cs50.h>
#include <math.h>

float get_change(void);

int main()
{
    //value converted into cents, rounded to nearest penny
    int cents = round(get_change()*100);

    int quarters; 
    int dimes;
    int nickels; 
    int pennies;
    
    //quarters
    for (quarters = 0; cents >= 25; cents-=25)
    {
       quarters ++;
    }

    //dimes
    for (dimes = 0; cents >= 10; cents-=10)
    {
       dimes ++;
    }
    
    //nickels
    for (nickels = 0; cents >= 5; cents-=5)
    {
       nickels ++;
    }
    
    //pennies
    for (pennies = 0; cents >= 1; cents-=1)
    {
       pennies ++;
    }

    printf("%d\n", quarters + dimes + nickels + pennies);

}

//gets a positive float value
float get_change(void)
{
    float n;
    do
    {
        n = get_float("Change owed: ");
    }
    while (n < 0);

    return n;
}
