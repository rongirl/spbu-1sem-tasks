#pragma once 


typedef struct ListElement ListElement;

typedef struct Position Position;

typedef struct List List;

List* createList();

void add(List* list, char* name, char* phone);
