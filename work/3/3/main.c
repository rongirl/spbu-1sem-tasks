#include <stdio.h>

int main()
{
    FILE *fileOne = fopen("f.txt", "r");
    if (fileOne == NULL)
    {
        printf("Not found");
        return -1;
    }
    int array[50] = { 0 };
    int i = 0;
    while (!feof(fileOne))
    {
        fscanf(fileOne, "%d", &array[i]);
        i++;
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
}