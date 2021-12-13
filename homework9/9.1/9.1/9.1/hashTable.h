#pragma once 

typedef struct HashTable HashTable;

void addWordInHashTable(HashTable* hashTable, const char* word);

HashTable* createHashTable();

void printHashTable(HashTable* hashTable);

int getMaximumLength(HashTable* hashTable);

double getFillFactor(HashTable* hashTable);

double getMiddleLength(HashTable* hashTable);

void deleteHashTable(HashTable* hashTable);