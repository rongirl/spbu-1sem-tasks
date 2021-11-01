#include "list.h"
#include <stdio.h>

typedef struct ListElement
{
    int value;
    struct ListElement* next;
} ListElement;

typedef struct List
{
    ListElement* head;
} List;

typedef struct Position
{
    Position* position;
} Position;

List* createList()
{
    return calloc(1, sizeof(List*));
}

void deleteList(List* list)
{
    ListElement* position = list->head;
    while (position != NULL)
    {
        list->head = list->head->next;
        free(position);
        position = list->head;
    }
    free(list);
}



void add(List* list, int value)
{
    ListElement* currentElement = list->head;
    ListElement* previousElement = NULL;
    while (currentElement != NULL && currentElement->value < value)
    {
        previousElement = currentElement;
        currentElement = currentElement->next;
    }
    ListElement* newElement = calloc(1, sizeof(ListElement));
    newElement->next = currentElement;
    newElement->value = value;
    if (previousElement == NULL)
    {
        list->head = newElement;
        return;
    }
    previousElement->next = newElement;
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