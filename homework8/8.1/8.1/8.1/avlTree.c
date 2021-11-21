#include "avlTree.h"

typedef struct Node
{
    int key;
    char* value;
    struct Node* leftSon;
    struct Node* rightSon;
    int balance;
} Node;

Node* createTree()
{
    return NULL;
}

bool isEmpty(Node* root)
{
    return root == NULL;
}

int getHeightRecursive(Node* node)
{
    if (node->rightSon == NULL && node->leftSon == NULL)
    { 
        return 1;
    }
    int heightLeft = 0;
    int heightRight = 0;
    if (node->rightSon != NULL)
    {
        heightRight = getHeightRecursive(node->rightSon) + 1;
    }
    if (node->leftSon != NULL)
    {
        heightLeft = getHeightRecursive(node->leftSon) + 1;
    }
    if (heightLeft > heightRight)
    {
        return heightLeft;
    }
    return heightRight;
}

int getHeight(Node* root)
{
    if (root == NULL)
    {
        return 0;
    }
    return getHeightRecursive(root);
}

int calculateBalance(Node* node)
{
    int heightLeft = 0;
    int heightRight = 0;
    if (node->rightSon != NULL)
    {
        heightRight = getHeight(node->rightSon);
    }
    if (node->leftSon != NULL)
    {
        heightLeft = getHeight(node->leftSon);
    }
    return heightRight - heightLeft;
}

Node* leftRotate(Node* root)
{
    Node* pivot = root->rightSon;
    root->rightSon = pivot->leftSon;
    pivot->leftSon = root;
    root->balance = calculateBalance(root);
    pivot->balance = calculateBalance(pivot);
    return pivot;
}

