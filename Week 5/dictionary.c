// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h> //for FILE
#include <string.h> //for strcpy
#include <stdlib.h> //for malloc

#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// Choose number of buckets in hash table
const unsigned int N = 26;

// Hash table //global pointer array
node *table[N];

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    // TODO
    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // TODO: Improve this hash function
    return toupper(word[0]) - 'A';
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    //open dictionary
    FILE *dictionary_file = fopen(dictionary, "r");

    //check file pointer
    if (dictionary_file != NULL)
    {
        //initialize word
        char *word = NULL;

        //read dictionary_file while not null (EOF)
        while (fgets(word, 46, dictionary_file) != NULL)
        {
            fgets(word, 46, dictionary_file);

            //allocate memory for node/store address for node inside of n
            node *n = malloc(sizeof(node));

            //create new node for each word
            strcpy(n->word, "Hello");
            n->next = NULL;

            //hash word to obtain hash value
            int hash_result = hash(n->word);

            //insert node into hash table at that location
            table[hash_result] = n;

            //return true
            return true;
        }
    }

    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // TODO
    return 0;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
