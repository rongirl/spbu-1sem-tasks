#include <stdio.h>
#include "qsort.h"

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
        const int pivotIndex = partition(array, leftIndex, rightIndex);
        quickSort(array, leftIndex, pivotIndex - 1);
        quickSort(array, pivotIndex, rightIndex);
    }
}
