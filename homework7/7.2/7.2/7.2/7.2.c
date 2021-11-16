#include "tree.h"
#include <stdio.h>
#include <locale.h>

int main()
{   
    setlocale(LC_ALL, "rus");
    char string[200] = { '\0' };
    FILE* file = fopen("text.txt", "r");
    if (file == NULL)
    {
        printf(":(");
        return -1;
    }
    else
    {
        while (!feof(file))           
        {
            fgets(string, 200, file);      
        }
    }
    fclose(file);
    Node* tree = makeTree(string);
    printf("Дерево:\n");
    printTree(tree);
    printf("\nРезультат вычисления:");
    printf("\n%d", calculate(tree));
    deleteTree(&tree);
}