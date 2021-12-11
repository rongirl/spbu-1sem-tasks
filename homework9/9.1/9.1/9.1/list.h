#pragma once

#include <stdbool.h>

typedef struct List List;

List* createList();

bool addInList(List* list, char const* word, int count);

void deleteHead(List* list);

void deleteList(List* list);