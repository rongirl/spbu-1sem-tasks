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

void deleteValue(List* list, int position)
{
    ListElement* currentElement = list->head;
    ListElement* previousElement = list->tail;
    for (int i = 1; i < position; i++)
    {
        previousElement = currentElement;
        currentElement = currentElement->next;
    }
    previousElement->next = currentElement->next;
    list->head = currentElement->next;
    list->tail = previousElement;
    free(currentElement);
}

bool isInListOneElement(List* list)
{
    return list->head == list->tail;
}

int getValue(List* list)
{
    return list->head->value;
}

void deleteList(List* list)
{
    while (list->head != list->tail)
    {
        deleteValue(list, 1);
    }
    free(list->head);
    free(list);
}

bool isEmpty(List* list)
{
    return list->head == NULL;
}
