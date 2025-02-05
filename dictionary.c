// Implements a dictionary's functionality
#include "dictionary.h"
#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>

// Represents a node in a hash table
typedef struct node
{
    char word[LENGTH + 1];
    struct node *next;
} node;

// TODO: Choose number of buckets in hash table
const unsigned int N = 15000;

// Hash table
node *table[N];
unsigned int word_count = 0;

// Returns true if word is in dictionary, else false
bool check(const char *word)
{
    unsigned int index = hash(word);
    // traverse linked list, find the word
    node *cursor = table[index];
    while (cursor != NULL)
    {
        if (strcasecmp(cursor->word, word) == 0)
        {
            return true;
        }
        cursor = cursor->next;
    }

    return false;
}

// Hashes word to a number
unsigned int hash(const char *word)
{
    // djb2 hash function by Dan Bernstein
    unsigned long hash = 5381;
    int c;
    while ((c = *word++))
    {
        hash = ((hash << 5) + hash) + toupper(c);
    }
    return hash % N; // size of the hash tableThans
}

// Loads dictionary into memory, returning true if successful, else false
bool load(const char *dictionary)
{
    // Open the dictionary file
    FILE *source = fopen(dictionary, "r");
    if (source == NULL)
    {
        printf("Could not open dictionary file at path: %s\n", dictionary);
        return false;
    }
    char word[LENGTH + 1];
    // Read each word in the file
    while (fscanf(source, "%s", word) != EOF)
    {
        node *new_node = malloc(sizeof(node));
        if (new_node == NULL)
        {
            return false;
        }
        // Add each word to the hash table
        strcpy(new_node->word, word);
        unsigned int index = hash(word);
        // set pointers
        new_node->next = table[index];
        table[index] = new_node;
        word_count++;
    }
    // Close the dictionary file
    fclose(source);
    return true;
}

// Returns number of words in dictionary if loaded, else 0 if not yet loaded
unsigned int size(void)
{
    // returns counted words
    return word_count;
}

// Unloads dictionary from memory, returning true if successful, else false
bool unload(void)
{
    // iterate over hash table
    for (int i = 0; i < N; i++)
    {
        // free list at each bucket
        node *cursor = table[i];
        while (cursor != NULL)
        {
            node *temp = cursor;
            cursor = cursor->next;
            free(temp);
        }
    }
    return true;
}
