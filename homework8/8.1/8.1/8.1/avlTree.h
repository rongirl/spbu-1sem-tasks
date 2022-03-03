#pragma once 

#include <stdbool.h>

// структура дерева
typedef struct Dictionary Dictionary;

// создание дерева 
Dictionary* createTree();

// проверка на пустоту дерева
bool isEmpty(Dictionary* tree);

// удаление дерева
void deleteTree(Dictionary** tree);

// взятие значения элемента по ключу 
const char* getValue(Dictionary** tree, const char* key);

// добавление элемента в дерево
void addValue(Dictionary* tree, const char* key, const char* value);

// удаление элемента по ключу 
void deleteValue(Dictionary** tree, const char* key);

// проверка на присутствие элемента в дереве по ключу
bool inTree(Dictionary** tree, const char* key);