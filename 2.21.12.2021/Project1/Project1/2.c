#include "queue.h"
#include <stdbool.h>
#include <stdio.h>

bool areTestsPassed()
{
    QueuePriority* queue = createQueue();
    if (!isEmpty(queue))
    {
        deleteQueue(queue);
        return false;
    }
    enqueue(queue, 12345, 9);
    enqueue(queue, 5, 10);
    enqueue(queue, 12345, 1);
    enqueue(queue, 1, 90);
    enqueue(queue, 0, 90);
    if (getValueHead(queue) != 1 && getKeyHead(queue) != 90)
    {
        deleteQueue(queue);
        return false;
    }
    if (dequeue(queue) != 1)
    {
        deleteQueue(queue);
        return false;
    }
    if (getValueHead(queue) != 0 && getKeyHead(queue) != 90)
    {
        deleteQueue(queue);
        return false;
    }
    dequeue(queue);
    if (dequeue(queue) != 5)
    {
        deleteQueue(queue);
        return false;
    }
    dequeue(queue);
    if (dequeue(queue) != 12345)
    {
        deleteQueue(queue);
        return false;
    }
    if (dequeue(queue) != -1)
    {
        deleteQueue(queue);
        return false;
    }
    deleteQueue(queue);
    return true;
}

int main()
{ 
    if (!areTestsPassed())
    {
        printf("Tests are failed :(");
        return -1;
    }
    printf("Tests are passed :)");
}