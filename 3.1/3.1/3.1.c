#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

int partition(int* array, int leftIndex, int rightIndex)
{
    const int pivot = array[(leftIndex + rightIndex) / 2];
    while (leftIndex <= rightIndex)
    {
        while (array[leftIndex] < pivot)
        {
            ++leftIndex;
        }
        while (array[rightIndex] > pivot)
        {
            --rightIndex;
        }
        if (leftIndex <= rightIndex)
        {
            const int temporary = array[leftIndex];
            array[leftIndex] = array[rightIndex];
            array[rightIndex] = temporary;
            ++leftIndex;
            --rightIndex;
        }
    }
    return leftIndex;
}

void insertionSort(int* array, int leftIndex, int rightIndex)
{
    for (int i = leftIndex + 1; i < rightIndex + 1; i++)
    {
        int j = i - 1;
        while (j >= 0 && array[j] > array[j + 1])
        {
            const int temporary = array[j];
            array[j] = array[j + 1];
            array[j + 1] = temporary;
            --j;
        }
    }
}

void quickSort(int* array, int leftIndex, int rightIndex)
{
    if (leftIndex >= rightIndex)
    {
        return;
    }
    if (rightIndex - leftIndex + 1 < 10)
    {
        insertionSort(array, leftIndex, rightIndex);
    }
    else
    {
        int pivotIndex = partition(array, leftIndex, rightIndex);
        quickSort(array, leftIndex, pivotIndex - 1);
        quickSort(array, pivotIndex, rightIndex);
    }
}

bool checkSort(int* array, int size)
{
    quickSort(array, 0, size - 1);
    for (int i = 0; i < size - 1; i++)
    {
        if (array[i] > array[i + 1])
        {
            return false;
        }
    }
    return true;
}

void createArrayOfRandomElements(int* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 1000;
    }
}

void createArrayOfEqualElements(int* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = 544;
    }
}

void createArrayOfSortedElements(int* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = i;
    }
}

bool test()
{
    int arrayOfRandomElements[501] = { 0 };
    createArrayOfRandomElements(arrayOfRandomElements, 501);
    int arrayOfEqualElements[400] = { 0 };
    createArrayOfEqualElements(arrayOfEqualElements, 400);
    int arrayOfSortedElements[300] = { 0 };
    createArrayOfSortedElements(arrayOfSortedElements, 300);
    return
        checkSort(arrayOfRandomElements, 501) &&
        checkSort(arrayOfEqualElements, 400) &&
        checkSort(arrayOfSortedElements, 300);
}

int main()
{
    if (!test())
    {
        printf("Tests failed");
        return 0;
    }
    setlocale(LC_ALL, "rus");
    int size = 0;
    printf("Введите размер массива: ");
    scanf("%d", &size);
    int* array = calloc(size, sizeof(int));
    if (array == NULL)
    {
        printf("Все плохо :(");
        return -1;
    }
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 1000;
    }
    printf("Исходный массив: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n\n");
    quickSort(array, 0, size - 1);
    printf("Отсортированный массив: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    free(array);
}
