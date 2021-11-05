#include <stdio.h>
#include <locale.h>
#include "list.h"
#include "mergeSort.h"

int main()
{   
    setlocale(LC_ALL, "rus");
    FILE* file = fopen("input.txt", "r");
    if (file == NULL)
    {
        printf("file not found");
        return -1;
    }
    List* list = createList();
    while (!feof(file))
    {
        char name[100] = { '\0' };
        char phone[100] = { '\0' };
        fscanf(file, "%[^-]%*c%*c", name);
        fscanf(file, "%[^\n]%*c", phone);
        add(list, name, phone);
    }
    fclose(file);
    printf("Исходные данные: \n");
    printList(list);
    printf("%d", getLength(list));
    printf("\n");
    List* newList = list;
    printList(newList);
    newList = mergeSort(list, 1);
    printList(newList);
}