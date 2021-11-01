#include <stdio.h>
#include "list.h"

int main()
{
    List* list = createList();
    add(list, 3);
    add(list, 100);
    add(list, 1);
    add(list, 2332);
    printList(list);
}