#include <stdio.h>
#include "stack.h"
#include <stdbool.h>

bool areTestsPassing()
{
    StackElement* headTest = NULL;
    if (!isEmpty(headTest))
    {
        return false;
    }
    push(&headTest, 7);
    push(&headTest, 8);
    if (isEmpty(headTest))
    {
        return false;
    }
    if (pop(&headTest) == 7)
    {
        return false;
    }
    pop(&headTest);
    if (!isEmpty(headTest))
    {
        return false;
    }
    push(&headTest, 9);
    deleteStack(&headTest);
    return isEmpty(headTest);
}