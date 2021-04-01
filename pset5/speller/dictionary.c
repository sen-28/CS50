// Implements a dictionary's functionality

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Number of buckets in hash table
const unsigned int N = 26;

// Hash table
node *table[N];

// Returns true if word is in dictionary else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO
    return 0;
}

// Loads dictionary into memory, returning true if successful else false
bool load(const char *dictionary)
{
    // open dictionary to read
    FILE *finpt = fopen(dictionary, "r");

    // if not opened, return false
    if (finpt == NULL)
    {
        return false;
    }

    char *word = NULL;

    // start reading strings, one at a time
    while (fscanf(finpt, "%s", word) != EOF)
    {
        // node memory allocated for word
        node *n = malloc(sizeof(node));

        // if no memory alllocated, return false
        if (n == NULL)
        {
            return false;
        }

        // add to node
        else
        {
            strcpy(n ->word, word);
            n ->next = NULL;


            // adding to hashtable
            int index = hash(n ->word);

            // new addition to an index
            if (table[index] == NULL)
            {
                table[index] = n;
            }

            //adding to an index
            else
            {
                n ->next = table[index];
                table[index] = n;
            }
        }

        free(n);
    }

    fclose(finpt);
    return true;
}

// Returns number of words in dictionary if loaded else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful else false
bool unload(void)
{
    // TODO
    return false;
}
