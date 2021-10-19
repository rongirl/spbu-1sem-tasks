#include <stdio.h>
#include <stdbool.h>

void printElementsLessNumber(FILE* file, int* array, int size, int number)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] < number)
        {
            fprintf(file, "%d ", array[i]);
        }
    }
}

void readFiles(int* array, int number)
{
    FILE* fileOneTest = fopen("fTest.txt", "r");
    if (fileOneTest == NULL)
    {
        printf("Not found");
        return;
    }
    int i = 0;
    while (!feof(fileOneTest))
    {
        fscanf(fileOneTest, "%d", &array[i]);
        i++;
    }
    fclose(fileOneTest);
    FILE* fileTwoTest = fopen("gTest.txt", "r");
    if (fileTwoTest == NULL)
    {
        printf("Not found");
        return;
    }
    fscanf(fileTwoTest, "%d", &number);
    fclose(fileTwoTest);
}

bool test()
{
    int array[10] = { 0 }; 
    int arrayTestOne[5] = { 5, 1, 2, 3, 4 };
    int number = 0;
    readFiles(array, number);
    FILE* fileTest = fopen("hTest.txt", "a+");
    printElementsLessNumber(fileTest, array, 10, number);
    int arrayTestTwo[10] = { 0 };
    for (int i = 0; !feof(fileTest); i++)
    {
        fscanf(fileTest, "%d", &arrayTestTwo);
    }
    fclose(fileTest);
    for (int i = 0; i < 5; i++)
    {
        if (arrayTestOne[i] != arrayTestTwo[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{  
    FILE *fileOne = fopen("f.txt", "r");
    if (fileOne == NULL)
    {
        printf("Not found");
        return -1;
    }
    int array[50] = { 0 };
    int size = 0;
    while (!feof(fileOne))
    {
        fscanf(fileOne, "%d", &array[size]);
        size++;
    }
    fclose(fileOne);
    FILE* fileTwo = fopen("g.txt", "r");
    if (fileTwo == NULL)
    {
        printf("Not found");
        return -1;
    }
    int number = 0;
    fscanf(fileTwo, "%d", &number);
    fclose(fileTwo);
    FILE* fileThree = fopen("h.txt", "a+");
    if (fileThree == NULL)
    {
        printf("Not found");
        return -1;
    }
    printElementsLessNumber(fileThree, array, size, number);
    fclose(fileThree);
}