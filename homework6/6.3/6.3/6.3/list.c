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
    int length;
} List;

typedef struct Position
{
    ListElement* position;
} Position;

List* createList()
{
    List* list = calloc(1, sizeof(List));
    list->length = 0;
    return list;
}

bool isEmpty(List* list)
{
    return list->head == NULL;
}

void add(List* list, char* name, char* phone)
{
    list->length++;
    ListElement* newElement = calloc(1, sizeof(ListElement));
    newElement->name = name;
    newElement->phone = phone;
    newElement->next = NULL;
    if (isEmpty(list))
    {
        list->head = newElement;
        return;
    }
    ListElement* currentElement = list->head;
    while (currentElement->next != NULL)
    {
        currentElement = currentElement->next;
    }
    currentElement->next = newElement;
}