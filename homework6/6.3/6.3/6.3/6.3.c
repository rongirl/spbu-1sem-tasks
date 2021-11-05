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
    printf("�������� ������: \n");
    printList(list);
    printf("\n");
    printf("������� ���� 0, ���� 1:\n0 - ���������� �� �����\n1 - ���������� �� ������ ��������\n");
    int command = 0;
    scanf("%d", &command);
    List* newList = createList();
    newList = mergeSort(list, command);
    printList(newList);
}