#include "list.h"
#include <stdio.h>
#include <stdbool.h>

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
    ListElement* position;
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

void printList(List* list)
{
    ListElement* currentElement = list->head;
    while (currentElement != NULL)
    {
        printf("%d ", currentElement->value);
        currentElement = currentElement->next;
    }
    printf("\n");
}

void add(List* list, int value)
{
    ListElement* currentElement = list->head;
    ListElement* previousElement = NULL;
    while (currentElement != NULL)
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

ListElement* reverse(ListElement* head)
{
    ListElement* newHead = NULL;
    while (head != NULL)
    {
        List* currentElement = head->next;
        head->next = newHead;
        newHead = head;
        head = currentElement;
    }
    return newHead;
}

List* reverseList(List* list)
{
    list->head = reverse(list->head);
    return list;
}

bool isEmpty(List* list)
{
    return list->head == NULL;
}

bool checkReverse(List* list, int* array, int size)
{
    ListElement* current = list->head;
    int index = 0;
    while (current != NULL && index < size)
    {
        if (current->value != array[index])
        {
            return false;
        }
        index++;
        current = current->next;
    }
    return true;
}