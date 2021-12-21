#include "queue.h"
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct QueueElement
{
    int value;
    int key;
    struct QueueElement* next;
} QueueElement;

typedef struct Queue
{
    QueueElement* head;
} QueuePriority;

QueuePriority* createQueue()
{
    return calloc(1, sizeof(QueuePriority*));
}

bool isEmpty(QueuePriority* queue)
{
    return queue->head == NULL;
}

void enqueue(QueuePriority* queue, int value, int key)
{
    if (isEmpty(queue))
    {
        QueueElement* newElement = calloc(1, sizeof(QueueElement));
        newElement->key = key;
        newElement->value = value;
        queue->head = newElement;
        return;
    }
    QueueElement* current = queue->head;
    QueueElement* previous = NULL;
    while (current != NULL && current->key >= key)
    {
        previous = current;
        current = current->next;
    }
    QueueElement* newElement = calloc(1, sizeof(QueueElement));
    newElement->next = current;
    newElement->key = key;
    newElement->value = value;
    if (previous == NULL)
    {
        queue->head = newElement;
        return;
    }
    previous->next = newElement;
}

int dequeue(QueuePriority* queue)
{
    if (isEmpty(queue))
    {
        return -1;
    }
    QueueElement* current = queue->head;
    int value = current->value;
    queue->head = queue->head->next;
    free(current);
    return value;
}

int getValueHead(QueuePriority* queue)
{
    return queue->head->value;
}

int getKeyHead(QueuePriority* queue)
{
    return queue->head->key;
}

void deleteQueue(QueuePriority* queue)
{
    while (!isEmpty(queue))
    {
        dequeue(queue);
    }
    free(queue);
}