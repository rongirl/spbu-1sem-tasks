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