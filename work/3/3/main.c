#include <stdio.h>
#include <stdbool.h>

void printElementsLessNumber(FILE *file, int* array, int size, int number)
{
    for (int i = 0; i < size; i++)
    {
        if (array[i] < number)
        {
            fprintf(file, "%d ", array[i]);
        }
    }
}

bool test()
{  
    int array[8] = { 5, 6, 7, 1, 2, 3, 4, 6 };
    int arrayTestOne[5] = { 5, 1, 2, 3, 4 };
    int number = 6;
   /*FILE* fileOneTest = fopen("fTest.txt", "r");
    if (fileOneTest == NULL)
    {
        printf("Not found");
        
    }
    for (int i = 0; i < 8; i++)
    {
        fscanf(fileOneTest, "%d", &array[i]);
    }
    fclose(fileOneTest);
    FILE* fileTwoTest = fopen("gTest.txt", "r");
    if (fileTwoTest == NULL)
    {
        printf("Not found");
        //return false;
    }
    fscanf(fileTwoTest, "%d", &number);
    fclose(fileTwoTest);
    */
    FILE *fileTest = fopen("hTest.txt", "a+");
    printElementsLessNumber(fileTest, array, 8, number);
    int arrayTestTwo[5] = { 0 };
    for (int i = 0; i < 5; i++)
    {
        fscanf(fileTest, "%d", &arrayTestTwo[i]);
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
    if (!test())
    {
        printf(":(");
        return -1;
    }
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