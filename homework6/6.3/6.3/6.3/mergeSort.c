#include "mergeSort.h"
#include "list.h"

void moveElements(List* listOne, List* listTwo, int count)
{
    for (int i = 0; i < count; i++)
    {
        add(listTwo, getHeadName(listOne), getHeadPhone(listOne));
        deleteHead(listOne);
    }
}

List* merge(List* leftList, List* rightList, int command)
{
    List* newList = createList();
    while (getLength(leftList) != 0 && getLength(rightList) != 0)
    {   
        int comparison = 0;
        if (command == 0)
        {
            comparison = strcmp(getHeadName(leftList), getHeadName(rightList));
        }
        else
        {
            comparison = strcmp(getHeadPhone(leftList), getHeadPhone(rightList));
        }
        if (comparison < 0)
        {
            moveElements(leftList, newList, 1);
        }
        else
        {
            moveElements(rightList, newList, 1);
        }
    }
    if (getLength(rightList) == 0)
    {
        moveElements(leftList, newList, getLength(leftList));
    }
    else
    {
        moveElements(rightList, newList, getLength(rightList));
    }
    deleteList(leftList);
    deleteList(rightList);
    return newList;
}

List* mergeSort(List* list, int command)
{
    int length = getLength(list);
    if (length <= 1)
    {
        return list;
    }
    List* leftList = createList();
    moveElements(list, leftList, length / 2);
    List* rightList = createList();
    moveElements(list, rightList, length - length / 2);
    deleteList(list);
    leftList = mergeSort(leftList, command);
    rightList = mergeSort(rightList, command);
    return merge(leftList, rightList, command);
}