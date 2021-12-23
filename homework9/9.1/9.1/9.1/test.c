#include "hashTable.h"
#include <stdbool.h>
#include <stdio.h>
#include "test.h"
#include <string.h>

bool isPassed()
{
    HashTable* tableTest = createHashTable();
    FILE* file = fopen("test.txt", "r");
    if (!file)
    {
        printf("File not found");
        deleteHashTable(tableTest);
        return 1;
    }
    while (!feof(file))
    {
        char word[50] = { '\0' };
        fscanf_s(file, "%s", word, 50);
        if (strlen(word) > 0)
        {
            addWordInHashTable(tableTest, word);
        }
    }
    fclose(file);
    double fillFactorTest = getFillFactor(tableTest);
    double averageLengthTest = getAverageLength(tableTest);
    int maximumLengthTest = getMaximumLength(tableTest);
    deleteHashTable(tableTest);
    return
        maximumLengthTest == 28 &&
        0.646341 - fillFactorTest < 0.00001 &&
        9.636364 - averageLengthTest < 0.00001;
}