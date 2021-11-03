#include "testCyclicList.h"
#include "cyclicList.h"

bool areTestsPassed()
{
    List* list = createList();
    if (!isEmpty(list))
    {
        return false;
    }
    add(list, 6);
    if (!isInListOneElement)
    {
        return false;
    }
    if (getValue(list) != 6)
    {
        return false;
    }
    add(list, 8);
    deleteValue(list, 1);
    deleteValue(list, 1);
    if (!isEmpty(list))
    {
        return false;
    }
    return true;
}