#pragma once 

#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node Node;

Node* createTree();

bool isEmpty(Node* root);

int getHeight(Node* node);

void deleteTreeRecursive(Node* root);

void deleteTree(Node** root);

char* getValue(Node** root, int key);

Node* addValue(Node* root, int key, char* value);

Node* deleteNode(Node* root, int key);

bool inTree(Node** root, int key);