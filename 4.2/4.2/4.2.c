#include <stdio.h>
#include <stdbool.h>
#include <locale.h>
#include <stdlib.h>
#include "qsort.h"
#include "search.h"

bool testFindFrequentElement(int* array, int size, int answer)
{
    return findFrequentElement(array, size) == answer;
}

bool test()
{
    int arrayOne[10] = { 4, 90, 2, 1, 2, 90, 5, 2, 1, 6 };
    int arrayTwo[8] = { 4, 2, 3, 9, 1, 6, 5, 10 };
    int arrayThree[9] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    return
        testFindFrequentElement(arrayOne, 10, 2) &&
        !testFindFrequentElement(arrayOne, 10, 90) &&
        testFindFrequentElement(arrayTwo, 8, 1) &&
        !testFindFrequentElement(arrayTwo, 8, 4) &&
        testFindFrequentElement(arrayThree, 9, 1) &&
        !testFindFrequentElement(arrayThree, 9, 7);
}

int main()
{
    if (!test())
    {
        printf("Все плохо :(");
        return 0;
    }
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
        printf("Элементы массива: ");
        for (int i = 0; i < size; i++)
        {
            printf("%d ", array[i]);
        }
        printf("\n");
        const int answer = findFrequentElement(array, size);
        printf("Самый частый элемент: %d", answer);
    }
    else
    {
        printf(":(");
    }
}