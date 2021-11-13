#pragma once

#include <stdbool.h>

typedef struct Node Node;

Node* createTree();

bool isEmpty(Node* root);

Node* addValue(Node* root, int key, char* value);

char* getValue(Node** root, int key);

bool inTree(Node** root, int key);

void deleteNode(Node* root);

void deleteValue(Node* root, int key);