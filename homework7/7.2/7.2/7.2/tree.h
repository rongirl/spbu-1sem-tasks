#pragma once 

// структура вершины
typedef struct Node Node;

// создание дерева
Node* createTree();

// удаление дерева рекурсивно
void deleteTreeRecursive(Node* root);

// удаление дерева 
void deleteTree(Node** root);

// создание новой вершины
Node* createNewNode(const char* string, int* index);

// вычисление выражения в дереве
int calculate(Node* root);

// печать дерева
void printTree(Node* root);

// построение дерева
Node* makeTree(const char* string);
