#pragma once

#include <stdbool.h>

typedef struct Node Node;

// создание дерева
Node* createTree();

// проверка на пустоту дерева
bool isEmpty(Node* root);

// добавление ключа и значения в дерево, возвращает вершину дерева
Node* addValue(Node* root, int key, char* value);

// возвращение значения вершины по ключу
char* getValue(Node** root, int key);

// проверка на присутствие ключа в дереве
bool inTree(Node** root, int key);

// удаление значения
void deleteValue(Node** root, int key);

// удаление дерева
void deleteTree(Node* root);

