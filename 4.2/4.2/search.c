#include <stdio.h>
#include "qsort.h"
#include "search.h"

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
        saveElement = lastElement;
    }
    return saveElement;
}