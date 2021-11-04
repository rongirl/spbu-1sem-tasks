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

// удаление листа, принимает список
void deleteList(List* list);

// удаление элемента по значению
bool deleteValue(List* list, int value);

// добавление значения в список, принимает список и значение
void add(List* list, int value);

// распечатывание списка, принимает список 
void printList(List* list);

// начальный вывод
void begin();

// возвращает позицию первого элемента
Position* first(List* list);

// возвращает позицию следующего элемента
Position* next(Position* position);

// проверка на последний элемент
bool last(Position* position);

// возвращает значение элемента по его позиции в списке 
int get(List* list, Position* position);

// проверка на пустоту списка
bool isEmpty(List* list);