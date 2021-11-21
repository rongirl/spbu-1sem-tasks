#pragma once 

#include <stdbool.h>
#include <stdlib.h>

typedef struct Node Node;

Node* createTree();

bool isEmpty(Node* root);

int getHeight(Node* node);