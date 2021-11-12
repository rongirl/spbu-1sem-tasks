#pragma once

#include<stdbool.h>

// структура элемента стека
typedef struct StackElement StackElement;

// добавление элемента на вершину стека
void push(StackElement** head, int number);

// удаление элемента с вершины стека
int pop(StackElement** head);

// проверка на пустоту стека
bool isEmpty(StackElement* head);

// удаление стека
void deleteStack(StackElement** head);