#pragma once 

typedef struct Node Node;

Node* createTree();

void deleteTreeRecursive(Node* root);

void deleteTree(Node** root);