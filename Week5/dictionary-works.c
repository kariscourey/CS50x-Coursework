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
const unsigned int N = 10000;

// Hash table //global pointer array
node *table[N];

//initialize word_count
unsigned int word_count = 0;

// Returns true if word is in dictionary, else false (case-insensitive)
bool check(const char *word)

{
    // hash word
    unsigned int hash_index = hash(word);

    //initialize cursor
    node *cursor = table[hash_index];

    //traverse linked list while address for next node is not null
    while (cursor != NULL)
    {
        //compare word in text to dictionary (cursor.word)
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }

        //set cursor to next node
        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    //initialize hash_sum
    long hash_sum = 0;

    //hash function
    for (int i = 0; i < strlen(word); i ++)
    {
        hash_sum += toupper(word[i]);
    }
    return hash_sum % N;
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
        char word[LENGTH + 1];

        //read dictionary_file while not EOF
        while (fscanf(dictionary_file, "%s", word) != EOF)
        {
            //allocate memory for node/store address for node inside of n
            node *n = malloc(sizeof(node));

            //check node pointer
            if (n == NULL)
            {
                return false;
            }

            //create new node for each word
            strcpy(n->word, word);
            n->next = NULL;

            //hash word to obtain hash value
            int hash_index = hash(word);

            //check if new node
            if (table[hash_index] == NULL)
            {
                table[hash_index] = n;
            }
            else
            {
                //insert node into hash table at that location
                //point n to table node
                n->next = table[hash_index];
                //point table node to n
                table[hash_index] = n;
            }

            //increment size
            word_count++;

            // //not here!!
            // //close file
            // fclose(dictionary_file);

            // return true;
        }

        //close file .. here!!
        fclose(dictionary_file);

        return true;
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
    for (int i = 0; i < N; i++)
    {
        //initialize cursor
        node *cursor = table[i];

        //traverse linked list while address for node is not null
        while (cursor != NULL)
        {
            //initialize tmp
            node *tmp = cursor;

            //set cursor to next node
            cursor = cursor->next;

            //free cursor
            free(tmp);
        }

        //check if contents of cursor are null and on last item
        if (cursor == NULL && i == N - 1)
        {
            return true;
        }
    }
    return false;
}
