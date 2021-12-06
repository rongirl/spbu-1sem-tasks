#include "testCyclicList.h"
#include "cyclicList.h"

bool areTestsPassed()
{
    List* list = createList();
    if (!isEmpty(list))
    {    
        deleteList(list);
        return false;
    }
    add(list, 6);
    if (!isInListOneElement(list))
    {   
        deleteList(list);
        return false;
    }
    if (getValue(list) != 6)
    {
        deleteList(list);
        return false;
    }
    add(list, 8);
    deleteValue(list, 1);
    deleteValue(list, 1);
    if (!isEmpty(list))
    {   
        deleteList(list);
        return false;
    }
    free(list);
    return true;
}