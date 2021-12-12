#include "hashTable.h"
#include "list.h"
#include <stdlib.h>
#include <string.h>

typedef struct HashTable
{   
    List** lists;
    int size;
    int count;
    double fillFactor;
} HashTable;

HashTable* createHashTable()
{
    HashTable* hashTable = calloc(1, sizeof(HashTable));
    if (hashTable == NULL)
    {
        return NULL;
    }
    hashTable->size = 41;
    hashTable->count = 0;
    hashTable->fillFactor = 0.0;
    hashTable->lists = calloc(hashTable->size, sizeof(List*));
    if (hashTable->lists == NULL)
    {
        return NULL;
    }
    for (int i = 0; i < hashTable->size; i++)
    {
        hashTable->lists[i] = createList();
    }
    return hashTable;
}

int hashFunction(const char* word, int size)
{
    int hash = 0;
    int length = strlen(word);
    for (int i = 0; i < length; i++)
    {
        hash = (hash + word[i]) % size;
    }
}