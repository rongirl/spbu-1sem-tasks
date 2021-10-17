#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>

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

bool binarySearch(int* array, int size, int number)
{
    int left = 0;
    int right = size;
    while (right - left > 1)
    {
        int middle = (left + right) / 2;
        if (number < array[middle])
        {
            right = middle;
        }
        if (number > array[middle])
        {
            left = middle;
        }
        if (number == array[middle])
        {
            return true;
        }
    }
    return number == array[right] || number == array[left];
}

bool testBinarySearch(int* array, int size, int number, bool answer)
{
    quickSort(array, 0, size - 1);
    return binarySearch(array, size, number) == answer;
}

bool test()
{
    int arrayOfSortedElements[6] = { 1, 2, 3, 4, 5, 6 };
    int arrayOfRandomElements[7] = { 45, 1, 100, 2, 3, 0, 400 };
    int arrayOfEqualElements[8] = { 5, 5, 5, 5, 5, 5, 5, 5 };
    return
        testBinarySearch(arrayOfSortedElements, 6, 1, true) &&
        testBinarySearch(arrayOfSortedElements, 6, 7, false) &&
        testBinarySearch(arrayOfRandomElements, 7, 100, true) &&
        testBinarySearch(arrayOfRandomElements, 7, 401, false) &&
        testBinarySearch(arrayOfEqualElements, 8, 5, true) &&
        testBinarySearch(arrayOfEqualElements, 8, 10, false);
}

int main()
{
    setlocale(LC_ALL, "rus");
    if (!test())
    {
        printf("Tests failed");
        return 0;
    }
    int size = 0;
    int count = 0;
    printf("Введите размер массива и количество чисел: ");
    scanf("%d %d", &size, &count);
    int* array = calloc(size, sizeof(int));
    if (array == NULL)
    {
        printf("Все плохо :(");
        return -1;
    }
    for (int i = 0; i < size; i++)
    {
        array[i] = rand() % 10;
    }
    printf("Исходный массив: ");
    for (int i = 0; i < size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n\n");
    quickSort(array, 0, size - 1);
    for (int i = 0; i < count; i++)
    {
        const int x = rand() % 10;
        if (binarySearch(array, size, x))
        {
            printf("Число %d найдено в массиве ", x);
            printf("\n\n");
        }
        else
        {
            printf("Число %d не найдено в массиве ", x);
            printf("\n\n");
        }
    }
    free(array);
}
