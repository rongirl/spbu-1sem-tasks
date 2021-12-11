#include "list.h"

int main()
{
    List* list = createList();
    addInList(list, "aaaa", 1);
    addInList(list, "bbbb", 1);
   // deleteHead(list);
    deleteList(list);
}