#include "list.h"
#include "test.h"
#include <locale.h>

int main()
{   
    setlocale(LC_ALL, "rus");
    if (!isPassed() || !areTestsPassed())
    {   
        printf(":((((");
        return -1;
    }
    List* list = createList();
    FILE* file = fopen("input.txt", "r");
    if (file == NULL)
    {
        printf("File not found");
        return -1;
    }
    while (!feof(file))
    { 
        int number = 0;
        fscanf(file, "%d", &number);
        add(list, number);
    }
    fclose(file);
    printf("Введенный список: \n");
    printList(list);
    list = reverseList(list);
    printf("Перевернутый список: \n");
    printList(list);
    deleteList(list);
}