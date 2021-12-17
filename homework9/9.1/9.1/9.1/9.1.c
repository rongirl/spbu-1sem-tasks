#include "hashTable.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <locale.h>

int main()
{   
	setlocale(LC_ALL, "rus");
    HashTable* hashTable = createHashTable();
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
			addWordInHashTable(hashTable, word);
		}
	}
	fclose(file);
	printf("�����:\n");
	printHashTable(hashTable);
	printf("\n\n����������� ����������: %f", getFillFactor(hashTable));
	printf("\n������������ ����� ������: %d", getMaximumLength(hashTable));
	printf("\n������� ����� ������: %f\n", getMiddleLength(hashTable));
	deleteHashTable(hashTable);
}