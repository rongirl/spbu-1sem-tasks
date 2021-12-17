#pragma once 

#include <stdbool.h>

// структура хеш таблицы
typedef struct HashTable HashTable;

// добавление элемента в хеш таблицу 
void addWordInHashTable(HashTable* hashTable, const char* word);

// создание хеш таблицы
HashTable* createHashTable();

// вывод хеш таблицы
void printHashTable(HashTable* hashTable);

// взятие максимальной длины списка в хеш таблице
int getMaximumLength(HashTable* hashTable);

// взятие коэффициента заполнения хеш таблицы
double getFillFactor(HashTable* hashTable);
 
// взятие средней длины списков хеш таблицы
double getMiddleLength(HashTable* hashTable);

// удаление хеш таблицы
void deleteHashTable(HashTable* hashTable);

// проверка хеш функции
bool testHashFunction();