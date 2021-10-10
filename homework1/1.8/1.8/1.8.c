#include <stdio.h>
#include <locale.h>

void reverse(int indexOfFirstElement, int indexOfLastElement, int* arrayOfElements)
{
    const int size = indexOfFirstElement + indexOfLastElement;
    for (int i = indexOfFirstElement; i < size / 2; i++)
    {
        const int temporary = arrayOfElements[i];
        arrayOfElements[i] = arrayOfElements[size - 1 - i];
        arrayOfElements[size - 1 - i] = temporary;
    }
}

void printArrayOfElements(int sizeOfArray, int* arrayOfElements)
{
    for (int i = 0; i < sizeOfArray; i++)
    {
        printf("%d ", arrayOfElements[i]);
    }
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int sizeOfFirstSegment = 0;
    int sizeOfSecondSegment = 0;
    printf("%s", "Введите длину двух отрезков: ");
    scanf("%d %d", &sizeOfFirstSegment, &sizeOfSecondSegment);
    int array[500] = { 0 };
    const int sizeOfArray = sizeOfFirstSegment + sizeOfSecondSegment;
    for (int i = 0; i < sizeOfArray; i++)
    {
        array[i] = rand() % 20;
    }
    printf("%s", "Исходный массив чисел: ");
    printArrayOfElements(sizeOfArray, array);
    printf("\n");
    reverse(0, sizeOfFirstSegment, array);
    reverse(sizeOfFirstSegment, sizeOfSecondSegment + sizeOfFirstSegment, array);
    reverse(0, sizeOfArray, array);
    printf("%s", "Получившийся массив: ");
    printArrayOfElements(sizeOfArray, array);
}

