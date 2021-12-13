#pragma once

#include <stdbool.h>

typedef struct List List;

List* createList();

bool addInList(List* list, const char* word, int count);

void deleteHead(List* list);

void deleteList(List* list);

bool isEmpty(List* list);

char const* getWordHead(List* list);

void deleteHead(List* list);

int getCountHead(List* list);