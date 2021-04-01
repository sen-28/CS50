#include<stdio.h>
#include<cs50.h>
#include<string.h>
#include<math.h>

int main(void)
{
    //to get text input
    string text = get_string("Text: ");

    float letters = 0;
    float words = 1;
    float sentences = 0;

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        //number of words
        if (text[i] == ' ')
        {
            words++;
        }

        //number of sentences
        if (text[i] == '.' || text[i] == '!' || text[i] == '?')
        {
            sentences++;
        }

        //number of letters

        //upper-case
        if (text[i] <= 'Z' && text[i] >= 'A')
        {
            letters++;
        }

        //lower-case
        if (text[i] <= 'z' && text[i] >= 'a')
        {
            letters++;
        }

    }

    float L = (letters / words)*100;
    float S = (sentences / words)*100;

    //to find index
    int index = round (0.0588 * L - 0.296 * S - 15.8);

    //display result
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }

    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }

    else
    {
        printf("Grade %i\n", index);
    }
}
