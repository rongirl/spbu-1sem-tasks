#pragma once

#include <stdbool.h>

// структура списка
typedef struct List List;

// создание списка
List* createList();

// добавление элемента в список
bool addInList(List* list, const char* word, int count);

// удаление вершины списка
void deleteHead(List* list);

// удаление списка
void deleteList(List* list);

// проверка на пустоту списка
bool isEmpty(List* list);

// взятие значения элемента списка
char const* getWordHead(List* list);

// удаление вершины списка
void deleteHead(List* list);

// взятие количества элементов в вершине списка
int getCountHead(List* list);

// взятие длины
int getLengthOfList(List* list);