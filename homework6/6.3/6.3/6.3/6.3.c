#include <stdio.h>
#include "list.h"

int main()
{
    List* list = createList();
    add(list, "sss", "54545");
    add(list, "fdsfd", "12");
    printList(list);
    printf("%s\n", getHeadName(list));
    printf("%s\n", getHeadPhone(list));
    printf("%d\n", getLength(list));
    deleteHead(list);
    printList(list);
    deleteList(list);
}