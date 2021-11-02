#include <stdio.h>
#include "cyclicList.h"

int main()
{
    List* list = createList();
    add(list, 44);
    add(list, 555);
    printList(list);
}