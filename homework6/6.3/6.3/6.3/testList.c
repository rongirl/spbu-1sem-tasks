#include "testList.h"
#include <string.h>

bool areTestsOfListPassed()
{
    List* list = createList();
    if (!isEmpty(list))
    {
        return false;
    }
    add(list, "ar", "89");
    add(list, "yar", "79");
    if (strcmp(getHeadName(list), "ar") != 0 || strcmp(getHeadPhone(list), "89") != 0 || getLength(list) != 2)
    {
        return false;
    }
    deleteHead(list);
    if (strcmp(getHeadName(list), "yar") != 0 || strcmp(getHeadPhone(list), "79") != 0)
    {
        return false;
    }
    deleteList(list);
    return true;
}