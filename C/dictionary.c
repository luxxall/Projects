// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 143100;

// Hash table
node *table[N];

int word_counter = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    // loop to go throught every element
    for (node *cursor = table[hash(word)]; cursor != NULL; cursor = cursor->next)
    {
        // comparing
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
    }
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    unsigned int val = 0;
    for (int i = 0; i <= strlen(word); i++)
    {
        val = (31 * val + toupper(word[i])) % N;
    }
    return val;
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // TODO
    // open a file dictionary with words
    FILE *dict = fopen(dictionary, "r");
    if (dict == NULL)
    {
        printf("Could not open dictionary.\n");
        return false;
    }
    // read each word in file
    // allocate memmory for each word to read. check if allocating is possible
    char *words = malloc(LENGTH + 1);
    if (words == NULL)
    {
        printf("Error allocating memmory.\n");
        return false;
    }

    // read word after word from dict to variable words
    while (fscanf(dict, "%s", words) != EOF)
    {
        // allocate a memmory for each node with word and pointer to next node. check is allocating
        // is possible
        node *n = malloc(sizeof(node));
        if (n == NULL)
        {
            printf("Error allocating memmory.\n");
            return false;
        }

        // hash word to make index in hash table
        unsigned int index = hash(words);

        // copy read word to node in place for words
        strcpy(n->word, words);

        // insert node to hash table
        if (table[index] == NULL)
        {
            table[index] = NULL;
        }
        else
        {
            n->next = table[index];
        }
        table[index] = n;
        word_counter++;
    }

    // free memory and return that all works
    fclose(dict);
    free(words);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return word_counter;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    for (int i = 0; i < N; i++)
    {
        while (table[i] != NULL)
        {
            node *buff = table[i]->next;
            free(table[i]);
            table[i] = buff;
        }
    }


    return true;
}
