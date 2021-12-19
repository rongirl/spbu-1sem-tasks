#include <stdio.h>
#include <locale.h>
#include "list.h"
#include "mergeSort.h"
#include "testList.h"

bool testMergeSort()
{
    List* listTestOne = createList();
    add(listTestOne, "abc", "1234");
    add(listTestOne, "bac", "12345");
    add(listTestOne, "cba", "1233");
    add(listTestOne, "acb", "2345");
    add(listTestOne, "bcc", "4123");
    add(listTestOne, "ccb", "12346");
    List* newListTestOne = createList();
    newListTestOne = mergeSort(newListTestOne, 0);
    bool checkSortOne = checkSort(newListTestOne);
    List* listTestTwo = createList();
    add(listTestTwo, "abc", "1234");
    add(listTestTwo, "bac", "12345");
    add(listTestTwo, "cba", "1233");
    add(listTestTwo, "acb", "2345");
    add(listTestTwo, "bcc", "4123");
    add(listTestTwo, "ccb", "12346");
    List* newListTestTwo = createList();
    newListTestTwo = mergeSort(newListTestTwo, 1);
    bool checkSortTwo = checkSort(newListTestTwo);
    return
        checkSortOne && 
        checkSortTwo;
}

bool areTestsPassed()
{
    return  areTestsOfListPassed() && testMergeSort();
}

int main()
{   
    setlocale(LC_ALL, "rus");
    if (!areTestsPassed())
    {
        return -1;
    }
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
    printf("»сходные данные: \n");
    printList(list);
    printf("\n");
    printf("¬ведите либо 0, либо 1:\n0 - сортировка по имени\n1 - сортировка по номеру телефона\n");
    int command = 0;
    scanf("%d", &command);
    List* newList = createList();
    newList = mergeSort(list, command);
    printList(newList);
}