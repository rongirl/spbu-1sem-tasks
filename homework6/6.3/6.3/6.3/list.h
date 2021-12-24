#pragma once 

#include <stdbool.h>
 
// структура позиции
typedef struct Position Position;

// структура списка
typedef struct List List;

// создание списка 
List* createList();

// добавление в хвост списка, функция копирует значения в список
void add(List* list, char* name, char* phone);

// распечатывание списка
void printList(List* list);

// взятие длины списка
int getLength(List* list);

// взятие первого имени в списке
char* getHeadName(List* list);

// взятие первого номера телефона в списке
char* getHeadPhone(List* list);
 
// удаление первого элемента в списке
void deleteHead(List* list);

// удаление списка
void deleteList(List* list);

// проверка на пустоту
bool isEmpty(List* list);

// проверка на отсортированность 
bool checkSort(List* list);
