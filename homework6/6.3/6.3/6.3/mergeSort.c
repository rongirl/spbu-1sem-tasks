#include "mergeSort.h"
#include "list.h"

void movingElements(List* listOne, List* listTwo, int count)
{
    for (int i = 0; i < count; i++)
    {
        add(listTwo, getHeadName(listOne), getHeadPhone(listOne));
        deleteHead(listOne);
    }
}

