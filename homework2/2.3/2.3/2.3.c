#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

void countingSort(int* array, int size)
{
    int minimumInArray = array[0];
    int maximumInArray = array[0];
    for (int i = 0; i < size; i++)
    {
        maximumInArray = max(maximumInArray, array[i]);
        minimumInArray = min(minimumInArray, array[i]);
    }
    int* arrayTemporary = calloc(maximumInArray - minimumInArray + 1, sizeof(int));
    if (arrayTemporary == NULL)
    {
        printf("Все плохо :(");
        return;
    }
    for (int i = 0; i < size; i++)
    {
        ++arrayTemporary[array[i] - minimumInArray];
    }
    int j = 0;
    for (int i = 0; i < maximumInArray - minimumInArray + 1; i++)
    {
        while (arrayTemporary[i] > 0 && j < size)
        {
            array[j] = i + minimumInArray;
            --arrayTemporary[i];
            ++j;
        }
    }
    free(arrayTemporary);
}

void bubbleSort(int* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (array[i] > array[j])
            {
                const int temporary = array[i];
                array[i] = array[j];
                array[j] = temporary;
            }
        }
    }
}

void printArray(int* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
}

bool checkSort(int* arrayBubbleSort, int* arrayCountingSort, int sizeOfArrays)
{
    for (int i = 0; i < sizeOfArrays - 1; i++)
    {
        if (arrayBubbleSort[i] > arrayBubbleSort[i + 1] && arrayCountingSort[i] > arrayCountingSort[i + 1])
        {
            return false;
        }
    }
    return true;
}

bool testSort()
{
    int arrayOfRandomElementsCountingSort[500] = { 0 };
    int arrayOfRandomElementsBubbleSort[500] = { 0 };
    for (int i = 0; i < 500; i++)
    {
        arrayOfRandomElementsCountingSort[i] = rand();
        arrayOfRandomElementsBubbleSort[i] = arrayOfRandomElementsCountingSort[i];
    }
    bubbleSort(arrayOfRandomElementsBubbleSort, 500);
    countingSort(arrayOfRandomElementsCountingSort, 500);
    int arrayOfEqualElementsBubbleSort[400] = { 0 };
    int arrayOfEqualElementsCountingSort[400] = { 0 };
    for (int i = 0; i < 400; i++)
    {
        arrayOfEqualElementsBubbleSort[i] = 1000;
        arrayOfEqualElementsCountingSort[i] = 1000;
    }
    bubbleSort(arrayOfEqualElementsBubbleSort, 400);
    countingSort(arrayOfEqualElementsCountingSort, 400);
    int arrayOfSortedElementsBubbleSort[600] = { 0 };
    int arrayOfSortedElementsCountingSort[600] = { 0 };
    for (int i = 0; i < 600; i++)
    {
        arrayOfSortedElementsCountingSort[i] = i;
        arrayOfSortedElementsBubbleSort[i] = i;
    }
    bubbleSort(arrayOfSortedElementsBubbleSort, 600);
    countingSort(arrayOfSortedElementsCountingSort, 600);
    return
        checkSort(arrayOfRandomElementsBubbleSort, arrayOfRandomElementsCountingSort, 500) &&
        checkSort(arrayOfEqualElementsBubbleSort, arrayOfEqualElementsCountingSort, 400) &&
        checkSort(arrayOfSortedElementsBubbleSort, arrayOfSortedElementsCountingSort, 600);
}

int main()
{
    setlocale(LC_ALL, "Rus");
    if (!testSort())
    {
        printf("Tests failed.");
        return 0;
    }
    int sizeOfArrayOne = 0;
    int sizeOfArrayTwo = 0;
    printf("Введите два числа, обозначающие размеры массива: ");
    scanf("%d %d", &sizeOfArrayOne, &sizeOfArrayTwo);
    int* arrayOne = calloc(sizeOfArrayOne, sizeof(int));
    int* arrayTwo = calloc(sizeOfArrayTwo, sizeof(int));
    if (arrayOne == NULL)
    {
        printf("Все плохо :(");
        free(arrayTwo);
        return -1;
    }
    if (arrayTwo == NULL)
    {
        printf("Все плохо :(");
        free(arrayOne);
        return -1;
    }
    for (int i = 0; i < sizeOfArrayOne; i++)
    {
        arrayOne[i] = rand() % 100000;
    }
    for (int i = 0; i < sizeOfArrayTwo; i++)
    {
        arrayTwo[i] = rand() % 100000;
    }
    int timeForCountingSortStart = clock();
    countingSort(arrayOne, sizeOfArrayOne);
    int timeForCountingSortEnd = clock();
    printf("Время работы сортировки подсчетом: ");
    printf("%d ", timeForCountingSortEnd - timeForCountingSortStart);
    printf("\n");
    int timeForBubbleSortStart = clock();
    bubbleSort(arrayTwo, sizeOfArrayTwo);
    int timeForBubbleSortEnd = clock();
    printf("Время работы сортировки пузырьком: ");
    printf("%d", timeForBubbleSortEnd - timeForBubbleSortStart);
    printf("\n");
    printf("Отсортированный подсчетом массив: ");
    printArray(arrayOne, sizeOfArrayOne);
    printf("\n");
    printf("Отсортированный пузырьком массив: ");
    printArray(arrayTwo, sizeOfArrayTwo);
    printf("\n");
    free(arrayOne);
    free(arrayTwo);
}
