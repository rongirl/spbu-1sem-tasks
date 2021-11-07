#include "testList.h"

bool areTestsPassed()
{
    List* list = createList();
    if (!isEmpty(list))
    {
        return false;
    }
    add(list, "ar", "89");
    add(list, "yar", "79");
    if (getHeadName(list) != "ar" || getHeadPhone(list) != "89" || getLength(list) != 2)
    {
        return false;
    }
    deleteHead(list);
    if (getHeadName(list) != "yar" || getHeadPhone(list) != "79")
    {
        return false;
    }
    deleteList(list);
    return true;
}