#include "tree.h"

typedef struct Node
{
    int operand;
    char operation;
    struct Node* leftSon;
    struct Node* rightSon;
    struct Node* parent;

} Node;

Node* createTree()
{
    return NULL;
}

void deleteTreeRecursive(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    deleteTreeRecursive(root->leftSon);
    deleteTreeRecursive(root->rightSon);
    free(root);
}

void deleteTree(Node** root)
{
    deleteTreeRecursive(*root);
    *root = NULL;
}