#include "hashTable.h"
#include "list.h"
#include <stdlib.h>
#include <string.h>
#include <math.h>

typedef struct HashTable
{   
    List** lists;
    int size;
    int count;
} HashTable;

void deleteHashTable(HashTable* hashTable)
{
    for (int i = 0; i < hashTable->size; i++)
    {
        deleteList(hashTable->lists[i]);
    }
    free(hashTable->lists);
    free(hashTable);
}

HashTable* createHashTable()
{
    HashTable* hashTable = calloc(1, sizeof(HashTable));
    if (hashTable == NULL)
    {
        return NULL;
    }
    hashTable->size = 41;
    hashTable->count = 0;
    hashTable->lists = calloc(hashTable->size, sizeof(List*));
    if (hashTable->lists == NULL)
    {   
        deleteHashTable(hashTable);
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
    const int length = strlen(word);
    for (int i = 0; i < length; i++)
    {
        hash = (hash + abs(word[i])) % size;
    }
    return hash;
}

void printHashTable(HashTable* hashTable)
{
    for (int i = 0; i < hashTable->size; i++)
    {
        printList(hashTable->lists[i]);
    }
}

double getFillFactor(HashTable* hashTable)
{
    return 1.0 * hashTable->count / hashTable->size;
}

int getMaximumLength(HashTable* hashTable)
{   
    int maximumLength = 0;
    for (int i = 0; i < hashTable->size; i++)
    {   
        int currentLengthOfList = getLengthOfList(hashTable->lists[i]);
        if (maximumLength < currentLengthOfList)
        {
            maximumLength = currentLengthOfList;
        }
    }
    return maximumLength;
}

double getAverageLength(HashTable* hashTable)
{
    int sumOfLengths = 0;
    int countOfLists = 0;
    for (int i = 0; i < hashTable->size; i++)
    {   
        if (!isEmpty(hashTable->lists[i]))
        {
            sumOfLengths += getLengthOfList(hashTable->lists[i]);
            ++countOfLists;
        }
    }
    if (sumOfLengths != 0)
    {
        return 1.0 * sumOfLengths / countOfLists;
    }
    return 0;
}

bool addInHashTable(HashTable* hashTable, const char* word, int count)
{
    bool addInTable = addInList(hashTable->lists[hashFunction(word, hashTable->size)], word, count);
    if (addInTable)
    {
        ++hashTable->count;
        return true;
    }
    return false;
}

bool resize(HashTable* hashTable)
{
    List* currentList = createList();
    for (int i = 0; i < hashTable->size; i++)
    {
        while (!isEmpty(hashTable->lists[i]))
        {
            const char* word = getWordHead(hashTable->lists[i]);
            int count = getCountHead(hashTable->lists[i]);
            addInList(currentList, word, count);
            deleteHead(hashTable->lists[i]);
        }
        deleteList(hashTable->lists[i]);
    }
    free(hashTable->lists);
    hashTable->size *= 2;
    hashTable->count = 0;
    hashTable->lists = calloc(hashTable->size, sizeof(List*));
    if (hashTable->lists == NULL)
    {
        return false;
    }
    for (int i = 0; i < hashTable->size; i++)
    {
        hashTable->lists[i] = createList();
    }
    while (!isEmpty(currentList))
    {
        addInHashTable(hashTable, getWordHead(currentList), getCountHead(currentList));
        deleteHead(currentList);
    }
    deleteList(currentList);
    return true;
}   

bool addWordInHashTable(HashTable* hashTable, const char* word)
{
    addInHashTable(hashTable, word, 1);
    if (getFillFactor(hashTable) > 1)
    {
        if (!resize(hashTable))
        {
            return false;
        }
    }
    return true;
}