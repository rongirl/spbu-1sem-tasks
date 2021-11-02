#pragma once 

#include <stdbool.h>

// структура списка
typedef struct List List;

// структура позиций элементов
typedef struct Position Position;

// структура элемента из списка
typedef struct ListElement ListElement;

// создание листа
List* createList();

void deleteList(List* list);

bool deleteValue(List* list, int value);

void add(List* list, int value);

void printList(List* list);

void begin();

Position* first(List* list);

Position* next(Position* position);

bool last(Position* position);

int get(List* list, Position* position);

bool isEmpty(List* list);