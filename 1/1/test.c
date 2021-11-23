#include "test.h"
#include "list.h"

bool areTestsPassed()
{
    List* list = createList();
    if (!isEmpty(list))
    {
        deleteList(list);
        return false;
    }
    add(list, 1);
    add(list, 2);
    if (isEmpty(list))
    {   
        deleteList(list);
        return false;
    }
    deleteList(list);
    return true;
}

bool isPassed()
{
    List* list = createList();
    add(list, 1);
    add(list, 2);
    add(list, 3);
    add(list, 4);
    add(list, 5);
    add(list, 6);
    list = reverseList(list);
    int array[6] = { 6, 5, 4, 3, 2, 1 };
    bool check = checkReverse(list, array);
    deleteList(list);
    return check;
}