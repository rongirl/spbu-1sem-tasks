#include <stdlib.h>
#include <stdbool.h>
#include "stack.h"
#include "testOfStack.h"

typedef struct StackElement
{
    int value;
    struct StackElement* next;
} StackElement; 

void push(StackElement** head, int number)
{
    StackElement* newElement = calloc(1, sizeof(StackElement));
    if (newElement == NULL)
    {
        return NULL;
    }
    newElement->value = number;
    newElement->next = *head;
    *head = newElement;
}

int pop(StackElement** head)
{
    if (head == NULL || *head == NULL)
    {
        return NULL;
    }
    StackElement* temporary = *head;
    int value = temporary->value;
    *head = (*head)->next;
    free(temporary);
    return value;
}

bool isEmpty(StackElement* head)
{
    return head == NULL;
}

void deleteStack(StackElement** head)
{
    while (!isEmpty(*head))
    {
        pop(head);
    }
}
