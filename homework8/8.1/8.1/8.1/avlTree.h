#pragma once 

#include <stdbool.h>

typedef struct Dictionary Dictionary;

Dictionary* createTree();

bool isEmpty(Dictionary* tree);

void deleteTree(Dictionary** tree);

const char* getValue(Dictionary** tree, const char* key);

void addValue(Dictionary* tree, const char* key, const char* value);

void deleteValue(Dictionary** tree, const char* key);

bool inTree(Dictionary** tree, const char* key);