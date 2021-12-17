#include "hashTable.h"
#include <stdbool.h>
#include <stdio.h>
#include "test.h"

bool isPassed()
{
    HashTable* tableTest = createHashTable();
	FILE* file = fopen("test.txt", "r");
	if (!file)
	{
		printf("File not found");
		return 1;
	}
	while (!feof(file))
	{
		char word[50] = { '\0' };
		fscanf(file, "%s", word);
		if (strlen(word) > 0)
		{
			addWordInHashTable(tableTest, word);
		}
	}
	fclose(file);
	double fillFactorTest = getFillFactor(tableTest);
	double middleLengthTest = getMiddleLength(tableTest);
	int maximumLengthTest = getMaximumLength(tableTest);
	deleteHashTable(tableTest);
	return
		maximumLengthTest == 28 &&
		0.646341 - fillFactorTest < 0.00001 &&
		9.636364 - middleLengthTest < 0.00001 &&
		testHashFunction();;
}