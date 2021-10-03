#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <locale.h>

int partition(int* array, int leftIndex, int rightIndex)
{
    int pivot = array[(leftIndex + rightIndex) / 2];
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
            int temporary = array[leftIndex];
            array[leftIndex] = array[rightIndex];
            array[rightIndex] = temporary;
            ++leftIndex;
            --rightIndex;
        }
    }
    return leftIndex;
}

void quickSort(int* array, int leftIndex, int rightIndex)
{
    if (leftIndex >= rightIndex)
    {
        return;
    }
    if (rightIndex - leftIndex + 1 < 10)
    {
        for (int i = leftIndex + 1; i < rightIndex + 1; i++)
        {
            int j = i - 1;
            while (j >= 0 && array[j] > array[j + 1])
            {
                int temporary = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temporary;
                --j;
            }
        }
    }
    else
    {
        int pivotIndex = partition(array, leftIndex, rightIndex);
        quickSort(array, leftIndex, pivotIndex - 1);
        quickSort(array, pivotIndex, rightIndex);
    }
}

int findFrequentElement(int* array, int size)
{   
    quickSort(array, 0, size - 1);
    int countOfElements = 1;
    int maximumCountOfElements = 1;
    int lastElement = array[0];
    int saveElement = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] == lastElement)
        {
            ++countOfElements;
        }
        else
        {
            if (maximumCountOfElements < countOfElements)
            {
                maximumCountOfElements = countOfElements;
                saveElement = lastElement;
            }
            lastElement = array[i];
            countOfElements = 1;
        }
    }
    if (maximumCountOfElements < countOfElements)
    {
        maximumCountOfElements = countOfElements;
        saveElement = lastElement;
    }
    return saveElement;
}

bool testFindFrequentElement(int* array, int size, int answer)
{
    if (findFrequentElement(array, size) == answer)
    {
        return true;
    }
    return false;
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
    setlocale(LC_ALL, "rus");
    if (!test())
    {
        printf("Tests failed");
        return 0;
    }
    int size = 0;
    printf("Введите размер массива: ");
    scanf("%d", &size);
    int* array = calloc(size, sizeof(int));
    if (array == NULL)
    {
        printf("Все плохо :(");
        return -1;
    }
    printf("Введите элементы массива: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &array[i]);
    }
    int answer = findFrequentElement(array, size);
    printf("Наиболее часто встречающийся элемент: %d", answer);
    free(array);
}
