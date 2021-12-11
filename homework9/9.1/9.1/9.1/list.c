#include "list.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ListElement
{
    const char* word;
    int counter;
    struct ListElement* next;
} ListElement;

typedef struct List
{
    struct ListElement* head;
    int length;
} List;

List* createList()
{
    return (List*)calloc(1, sizeof(List));
}

void printList(List* list)
{
    ListElement* currentElement = list->head;
    while (currentElement != NULL)
    {
        printf("%s %d", currentElement->word, currentElement->counter);
        currentElement = currentElement->next;
    }
}

bool isEmpty(List* list)
{
    return list->head == NULL;
}

int getLengthOfList(List* list)
{
    return list->length;
}

bool addInList(List* list, char const* word, int count)
{
    ListElement* currentElement = list->head;
    ListElement* previousElement = NULL;
    while (currentElement != NULL && strcmp(currentElement->word, word) != 0)
    {
        previousElement = currentElement;
        currentElement = currentElement->next;
    }
    if (currentElement == NULL)
    {   
        ListElement* newElement = calloc(1, sizeof(ListElement));
        newElement->counter = count;
        char const* newWord = calloc(strlen(word) + 1, sizeof(char));
        strcpy(newWord, word);
        newElement->word = newWord;
        newElement->next = NULL;
        if (previousElement == NULL)
        {
            list->head = newElement;
            list->length = 1;
            return true;
        }
        else
        {
            previousElement->next = newElement;
        }
        ++list->length;
        return true;
    }
    currentElement->counter += count;
    return false;
}

bool isInList(List* list, char const* word)
{
    ListElement* currentElement = list->head;
    while (currentElement != NULL)
    {   
        if (strcmp(currentElement->word, word) == 0)
        {
            return true;
        }
        currentElement = currentElement->next;
    }
    return false;
}

char const* getWordHead(List* list)
{   
    if (isEmpty(list))
    {
        return NULL;
    }
    return list->head->word;
}

int getCountHead(List* list)
{
    if (isEmpty(list))
    {
        return NULL;
    }
    return list->head->counter;
}

void deleteHead(List* list)
{
    if (isEmpty(list))
    {
        return;
    }
    ListElement* currentElement = list->head;
    list->head = list->head->next;
    free(currentElement->word);
    free(currentElement);
    --list->length;
}

void deleteList(List* list)
{
    while (!isEmpty(list))
    {
        deleteHead(list);
    }
    free(list);
}