#include "list.h"
#include "testList.h"

bool areTestsPassed()
{
    List* list = createList();
    if (!isEmpty(list))
    {
        return false;
    }
    add(list, 8);
    if (get(list, first(list)) == 9)
    {
        deleteList(list);
        return false;
    }
    add(list, 9);
    add(list, 1);
    add(list, 100);
    if (!checkSort(list))
    {   
        deleteList(list);
        return false;
    }
    deleteValue(list, 8);
    deleteValue(list, 9);
    deleteValue(list, 1);
    deleteValue(list, 100);
    if (isEmpty(list))
    {
        deleteList(list);
        return true;
    }
    deleteList(list);
    return false;
}

bool checkSort(List* list)
{
    int length = 0;
    for (Position* i = first(list); !last(i); i = next(i))
    {
        ++length;
    }
    int lengthSortedElements = 0;
    for (Position* i = first(list); !last(i); i = next(i))
    {
        if (!last(next(i)))
        {
            if (get(list, i) <= get(list, next(i)))
            {
                ++lengthSortedElements;
            }
        }
    }
    return (length - lengthSortedElements) == 1;
}