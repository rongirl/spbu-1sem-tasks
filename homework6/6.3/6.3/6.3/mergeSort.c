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

List* mergeSort(List* list, bool command)
{
    int length = getLength(list);
    if (length <= 1)
    {
        return list;
    }
    List* leftList = createList();
    movingElements(list, leftList, length / 2);
    List* rightList = createList();
    movingElements(list, rightList, length - length / 2);
    deleteList(list);
    leftList = mergeSort(leftList, command);
    rightList = mergeSort(rightList, command);

}