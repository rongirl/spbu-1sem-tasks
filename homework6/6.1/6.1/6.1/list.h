#pragma once 

typedef struct List List;

typedef struct Position Position;

List* createList();

void deleteList(List* list);

void add(List* list, int value);

void printList(List* list);