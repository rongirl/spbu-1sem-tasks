#include "stack.h"
#include <stdbool.h>
#include <stdlib.h>

bool areTestsPassing()
{
    StackElement* headTest = NULL;
    if (!isEmpty(headTest))
    {   
        deleteStack(&headTest);
        return false;
    }
    push(&headTest, 7);
    push(&headTest, 8);
    if (isEmpty(headTest))
    {
        deleteStack(&headTest);
        return false;
    }
    if (pop(&headTest) != 8)
    {   
        deleteStack(&headTest);
        return false;
    }
    pop(&headTest);
    if (!isEmpty(headTest))
    {   
        deleteStack(&headTest);
        return false;
    }
    push(&headTest, 9);
    deleteStack(&headTest);
    return isEmpty(headTest);
}