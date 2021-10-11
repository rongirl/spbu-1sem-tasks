#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>
#include "qsort.h"
#include "search.h"

int main()
{
    setlocale(LC_ALL, "rus");
    FILE* file = fopen("input.txt", "r");
    if (file == NULL)
    {
        printf("file not found");
        return 1;
    }
    int size = 0;
    int array[100] = { 0 };
    while (!feof(file))
    {
        fscanf(file, "%d", &array[size]);
        ++size;
    }
    fclose(file);
    if (size > 0)
    {
        printf("Ёлементы массива: ");
        for (int i = 0; i < size; i++)
        {
            printf("%d ", array[i]);
        }
        printf("\n");
        const int answer = findFrequentElement(array, size);
        printf("—амый частый элемент: %d", answer);
    }
    else
    {
        printf(":(");
    }
}