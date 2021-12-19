#include "list.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct ListElement
{
    char* name;
    char* phone;
    struct ListElement* next;
} ListElement;

typedef struct List
{
    ListElement* head;
    ListElement* tail;
    int length;
} List;

typedef struct Position
{
    ListElement* position;
} Position;

List* createList()
{
    return calloc(1, sizeof(List));
}

bool isEmpty(List* list)
{
    return list->head == NULL;
}

void add(List* list, char* name, char* phone)
{
    list->length++;
    ListElement* newElement = calloc(1, sizeof(ListElement));
    char* newName = calloc(1, sizeof(char));
    strcpy(newName, name);
    char* newPhone = calloc(1, sizeof(char));
    strcpy(newPhone, phone);
    newElement->name = newName;
    newElement->phone = newPhone;
    newElement->next = NULL;
    if (isEmpty(list))
    {
        list->head = newElement;
        list->tail = list->head;
        return;
    }
    list->tail->next = newElement;
    list->tail = list->tail->next;
}

void printList(List* list)
{
    ListElement* currentElement = list->head;
    while (currentElement != NULL)
    {
        printf("%s - %s\n", currentElement->name, currentElement->phone);
        currentElement = currentElement->next;
    }
}

int getLength(List* list)
{
    return list->length;
}

char* getHeadName(List* list)
{
    return list->head->name;
}

char* getHeadPhone(List* list)
{
    return list->head->phone;
}

void deleteHead(List* list)
{
    if (isEmpty(list))
    {
        return;
    }
    ListElement* position = list->head;
    ListElement* currentElement = list->head->next;
    list->length--;
    free(position);
    list->head = currentElement;
}

void deleteList(List* list)
{
    if (!isEmpty(list))
    {
        deleteHead(list);
    }
    free(list);
}

bool checkSort(List* list, int command)
{
    if (isEmpty(list))
    {
        return true;
    }
    ListElement* previousElement = list->head;
    ListElement* currentElement = list->head->next;
    while (currentElement != NULL)
    {
        int comparison = 0;
        if (command == 0)
        {
            comparison = strcmp(currentElement->name, previousElement->name);
        }
        else
        {
            comparison = strcmp(currentElement->phone, previousElement->phone);
        }

        if (comparison < 0)
        {
            return false;
        }
        previousElement = currentElement;
        currentElement = currentElement->next;
    }
    return true;
}
