#include "hashTable.h"
#include "list.h"
#include <stdlib.h>

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