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
    char* newName = calloc(1, sizeof(char));
    char* newPhone = calloc(1, sizeof(char));
    strcpy(newName, name);
    strcpy(newPhone, phone);
    newElement->name = newName;
    newElement->phone = newPhone;
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
    ListElement* position = list->head;
    while (position != NULL)
    {   
        list->length--;
        list->head = list->head->next;
        free(position);
        position = list->head;
    }
    free(list);
}