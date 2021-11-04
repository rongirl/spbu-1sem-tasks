#include "list.h"

typedef struct ListElement
{
    char* name;
    char* phone;
    struct ListElement* next;
} ListElement;

typedef struct List
{
    ListElement* head;
    int length = 0;
} List;

void add(List* list, char* name, char* phone)
{
    
}