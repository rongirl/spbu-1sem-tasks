#pragma once 

#include <stdbool.h>

// ��������� ��� �������
typedef struct HashTable HashTable;

// ���������� �������� � ��� ������� 
bool addWordInHashTable(HashTable* hashTable, const char* word);

// �������� ��� �������
HashTable* createHashTable();

// ����� ��� �������
void printHashTable(HashTable* hashTable);

// ������ ������������ ����� ������ � ��� �������
int getMaximumLength(HashTable* hashTable);

// ������ ������������ ���������� ��� �������
double getFillFactor(HashTable* hashTable);
 
// ������ ������� ����� ������� ��� �������
double getAverageLength(HashTable* hashTable);

// �������� ��� �������
void deleteHashTable(HashTable* hashTable);