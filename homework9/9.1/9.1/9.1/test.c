#include "hashTable.h"
#include <stdbool.h>
#include <stdio.h>

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
	return true;
}