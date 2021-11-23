#pragma once 

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

// структура списка
typedef struct List List;

// структура позиций элементов
typedef struct Position Position;

// создание листа
List* createList();

// удаление листа, принимает список
void deleteList(List* list);

// добавление значения в список, принимает список и значение
void add(List* list, int value);

// распечатывание списка, принимает список 
void printList(List* list);

// переворачивание списка
List* reverseList(List* list);

bool isEmpty(List* list);

bool checkReverse(List* list, int* array);