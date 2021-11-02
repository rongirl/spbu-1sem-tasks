#include "cyclicList.h"
#include <stdlib.h>
#include <stdio.h>

typedef struct ListElement
{
    int value;
    struct ListElement* next;
} ListElement;

typedef struct List
{
    ListElement* head;
    ListElement* tail;
} List;

List* createList()
{
    return calloc(1, sizeof(List));
}

bool isEmpty(List* list)
{
    return list->head == NULL;
}

void add(List* list, int value)
{   
    ListElement* newElement = calloc(1, sizeof(ListElement));
    newElement->value = value;
    if (list->head == NULL)
    {   
        newElement->next = list->head;
        list->head = newElement;
    }
    else
    {
        list->tail->next = newElement;
    }
    list->tail = newElement;
    list->tail->next = list->head;
}

void printList(List* list)
{
    ListElement* currentElement = list->head;
    while (currentElement != NULL)
    {
        printf("%d ", currentElement->value);
        currentElement = currentElement->next;
    }
}