#include "hashTable.h"
#include "test.h"
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{   
    setlocale(LC_ALL, "rus");
    if (!isPassed())
    {
        printf(":(");
        return -1;
    }
    HashTable* hashTable = createHashTable();
    FILE* file = fopen("test.txt", "r");
    if (!file)
    {
        printf("File not found");
        deleteHashTable(hashTable);
        return 1;
    }
    while (!feof(file))
    {
        char word[50] = { '\0' };
        fscanf_s(file, "%s", word, 50); 
        if (strlen(word) > 0)
        {
            addWordInHashTable(hashTable, word);
        }
    }
    fclose(file);
    printf("�����:\n");
    printHashTable(hashTable);
    printf("\n\n����������� ����������: %f", getFillFactor(hashTable));
    printf("\n������������ ����� ������: %d", getMaximumLength(hashTable));
    printf("\n������� ����� ������: %f\n", getAverageLength(hashTable));
    deleteHashTable(hashTable);
}