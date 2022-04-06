// Implements a dictionary's functionality

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h> //for FILE
#include <string.h> //for strcpy
#include <strings.h> //for strcasecmp
#include <stdlib.h> //for malloc


#include "dictionary.h"

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
}
node;

// initialize buckets in hash table
const unsigned int N = 52;

// Hash table //global pointer array
node *table[N];

//initialize word_count
unsigned int word_count = 0;

// Returns true if word is in dictionary, else false (case-insensitive)
bool check(const char *word)
{
    // hash word
    unsigned int hash_index = hash(word);

    //check access to linked list at index in hash table
    if (table[hash_index] == NULL)
    {
        return false;
    }

    //traverse linked list
    for (p = table[hash_index]; p != NULL; p = p->next)
    {
        if (strcasecmp(p->word,word) == 0)
        {
            return true;
        }
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    //hash function
    return toupper(word[0] + word[1]) - 'A';
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
            strcpy(n->word, word);
            n->next = NULL;

            //hash word to obtain hash value
            int hash_index = hash(n->word);

            //insert node into hash table at that location
            //point n to table node
            n->next = table[hash_index];
            //point table node to n
            table[hash_index] = n;

            //free n
            free(n);

            //increment size
            word_count++;

            //return true
            return true;
        }
    }

    return false;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    //return word_count
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // TODO
    return false;
}
