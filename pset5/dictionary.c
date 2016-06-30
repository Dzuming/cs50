/****************************************************************************
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 ***************************************************************************/

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "dictionary.h"
#include <string.h>
#include <ctype.h>
// size of hashtable
#define SIZE  5012
// define node

typedef struct node
{
char word[LENGTH + 1];
struct node* next;
}
node;
node* hashtable[SIZE] ={NULL};
int dic_Size = 0;
// hash function for strings
int hash(const char* word)
{
    int hash = 0;
    int n;
    for (int i = 0; word[i] != '\0'; i++)
    {
        // alphabet case
        if (isalpha(word[i]))
        {
            n = word[i] - 'a' + 1;
}
        // comma case
        else
            n = 27;

        hash = ((hash << 3) + n) % SIZE;
    }
    return hash;
}
/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{
// create temp variable
    char temp_word[LENGTH + 1];
    int temp_len = strlen(word);
    for (int i = 0; i < temp_len; i++)
    {
    // word is always lowercase
        temp_word[i] = tolower(word[i]);
     
      }
    temp_word[temp_len] = '\0';
    int index =  hash(temp_word);
     // if hashtable is empty, return false
    if ( hashtable[index] == NULL)
    {
        return false;
    }
    // variable to compare with a word
    node* list = hashtable[index];
    while (list != NULL)
    {
    // if word is compare to list variable, return true
        if (strcmp(temp_word, list->word ) == 0 )
        {   
            return true;
    }
        list = list->next;
    }  
    
    return false;
}
/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
// open directory
    FILE* open_dict = fopen(dictionary, "r");
    if (open_dict == NULL)
    {
        printf("Could not open %s.\n", dictionary);
        return false;
    }
    char word[LENGTH + 1];
    int index = 0;
    
    // scan through the file
    while (fscanf(open_dict, "%s\n", word) != EOF)
    {
    // allocate memory for a new word
        node* new_word = malloc(sizeof(node));
    // place word into a new word
        strcpy(new_word->word, word);
        index = hash(word);
        dic_Size++;
    // if hashtable is empty, insert new word
        if (hashtable[index] == NULL)
        {
            hashtable[index] = new_word;
            new_word->next = NULL;
   }
   // if hashtable is empty, append new word
   else 
        {
            new_word->next = hashtable[index];
            hashtable[index] = new_word;
   }
   }
    fclose(open_dict);
    return true;
}

/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{   
    // if a word exist return size of a dictionary
    if (dic_Size > 0)
    {
        return dic_Size;
    }
    else
        return 0;
}
/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    for (int i = 0; i < SIZE; i++)
    {
        node* list = hashtable[i];
     
     // if hashtable is not empty go through it and free memory
        while (list != NULL)
        {

            node* temp= list->next;    
            free(list);
            list = temp;   
    }  
    }   
    return true;
}
