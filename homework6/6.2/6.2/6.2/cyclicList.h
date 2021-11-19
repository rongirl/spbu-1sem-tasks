#pragma once 

#include <stdbool.h>

// структура цикличного списка
typedef struct List List;

// структура элемента в списке 
typedef struct ListElement ListElement;

// создание списка
List* createList();

// добавление элемента в хвост списка, принимает список и значение
void add(List* list, int value);

// удаление значения, принимает список и позицию элемента. Продвигает head на следующий за удалённым
void deleteValue(List* list, int position);

// проверка на один элемент в списке, принимает список
bool isInListOneElement(List* list);

// возвращает значение head, принимает список
int getValue(List* list);

// удаление списка, принимает список
void deleteList(List* list);