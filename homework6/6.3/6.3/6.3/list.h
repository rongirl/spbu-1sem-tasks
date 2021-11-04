#pragma once 

typedef struct ListElement ListElement;

typedef struct Position Position;

typedef struct List List;

List* createList();

void add(List* list, char* name, char* phone);

void printList(List* list);

int getLength(List* list);

char* getHeadName(List* list);

char* getHeadPhone(List* list);

void deleteHead(List* list);

void deleteList(List* list);

