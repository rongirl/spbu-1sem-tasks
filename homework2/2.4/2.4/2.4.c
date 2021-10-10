#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <stdbool.h>

void pastQuickSort(int* array, int size)
{
    int leftIndex = 0;
    int rightIndex = size - 1;
    const int supportElement = array[0];
    while (leftIndex <= rightIndex)
    {
        while (leftIndex < size && array[leftIndex] < supportElement)
        {
            ++leftIndex;
        }
        while (rightIndex >= 0 && array[rightIndex] >= supportElement)
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
}

void arrayOfRandomElements(int* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 1000;
    }
}

void arrayOfEqualElements(int* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = 544;
    }
}

void arrayOfSortedElements(int* array, int size)
{
    for (int i = 0; i < size; i++)
    {
        array[i] = i;
    }
}

bool checkPastQuickSort(int* array, int size)
{
    int pivot = array[0];
    int numbersLessPivot = 0;
    for (int i = 1; i < size; i++)
    {
        if (pivot > array[i])
        {
            numbersLessPivot++;
        }
    }
    int temporary = 0;
    pastQuickSort(array, 100);
    for (int i = 0; i < size; i++)
    {
        if (array[i] < pivot)
        {
            ++temporary;
        }
        else if (temporary != numbersLessPivot)
        {
            return false;
        }
    }
    return true;
}

bool test()
{
    int arrayRandomElements[100] = { 0 };
    arrayOfRandomElements(arrayRandomElements, 100);
    int arraySortedElements[100] = { 0 };
    arrayOfSortedElements(arraySortedElements, 100);
    int arrayEqualElements[100] = { 0 };
    arrayOfEqualElements(arrayEqualElements, 100);
    return
        checkPastQuickSort(arrayRandomElements, 100) &&
        checkPastQuickSort(arrayEqualElements, 100) &&
        checkPastQuickSort(arraySortedElements, 100);
}

int main()
{
    setlocale(LC_ALL, "Rus");
    if (!test())
    {
        printf("Tests failed");
        return 0;
    }
    int size = 0;
    scanf("%d", &size);
    int* array = calloc(size, sizeof(int));
    if (array == NULL)
    {
        printf("Все плохо");
        return -1;
    }
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 100000;
    }
    printf("Исходный массив: ");
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    pastQuickSort(array, size);
    printf("\n");
    printf("После выполнения алгоритма: ");
    printf("\n");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    free(array);
}
