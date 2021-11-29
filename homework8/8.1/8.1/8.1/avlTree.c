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

Node* rightRotate(Node* root)
{
    Node* pivot = root->leftSon;
    root->leftSon = pivot->rightSon;
    pivot->rightSon = root;
    root->balance = calculateBalance(root);
    pivot->balance = calculateBalance(pivot);
    return pivot;
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

Node* search(Node* root, int key)
{
    Node* i = root;
    while (i != NULL)
    {
        if (key > i->key)
        {
            i = i->rightSon;
        }
        else if (key < i->key)
        {
            i = i->leftSon;
        }
        else
        {
            return i;
        }
    }
    return i;
}

Node* balance(Node* node)
{   
    node->balance = calculateBalance(node);
    if (node->balance == 2)
    {
        if (calculateBalance(node->rightSon) < 0)
        {
            node->rightSon = rightRotate(node->rightSon);
        }
        return leftRotate(node);
    }
    if (node->balance == -2)
    {
        if (calculateBalance(node->leftSon) > 0)
        {
            node->leftSon = leftRotate(node->leftSon);
        }
        return rightRotate(node);
    }
    return node;
}

bool inTree(Node** root, int key)
{
    Node* searchNode = search(*root, key);
    return searchNode != NULL;
}

char* getValue(Node** root, int key)
{
    Node* searchNode = search(*root, key);
    if (searchNode == NULL)
    {
        return NULL;
    }
    return searchNode->value;
}

Node* insert(Node* node, int key, char* value)
{
    if (node == NULL)
    {
        Node* newNode = calloc(1, sizeof(Node));
        newNode->balance = 0;
        newNode->key = key;
        newNode->value = value;
        newNode->leftSon = NULL;
        newNode->rightSon = NULL;
        return newNode;
    }
    if (node->key == key)
    {
        free(node->value);
        node->value = value;
        return;
    }
    if (node->key < key)
    {
        node->rightSon = insert(node->rightSon, key, value);
        node->rightSon = balance(node->rightSon);
    }
    if (node->key > key)
    {
        node->leftSon = insert(node->leftSon, key, value);
        node->leftSon = balance(node->leftSon);
    }
    return balance(node);
}

Node* addValue(Node* root, int key, char* value)
{
    char* newValue = calloc(strlen(value) + 1, sizeof(char));
    strcpy(newValue, value);
    if (isEmpty(root))
    {
        Node* newRoot = calloc(1, sizeof(Node));
        newRoot->key = key;
        newRoot->value = newValue;
        newRoot->balance = 0;
        newRoot->leftSon = NULL;
        newRoot->rightSon = NULL;
        return newRoot;
    }
    root = insert(root, key, newValue);
    root = balance(root);
}

Node* searchMin(Node* node)
{
    if (node->leftSon != NULL)
    {
        return searchMin(node->leftSon);
    }
    return node;
}

Node* deleteMin(Node* node)
{
    if (node->leftSon == NULL)
    {
        return node->rightSon;
    }
    node->leftSon = deleteMin(node->leftSon);
    return balance(node);
}

Node* deleteNode(Node* root, int key)
{
    if (root == NULL)
    {
        return 0;
    }
    if (key < root->key)
    {
        root->leftSon = deleteNode(root->leftSon, key);
    }
    else if (key > root->key)
    {
        root->rightSon = deleteNode(root->rightSon, key);
    }
    else
    {
        Node* leftSon = root->leftSon;
        Node* rightSon = root->rightSon;
        free(root->value);
        free(root);
        if (rightSon == NULL)
        {
            return leftSon;
        }
        Node* minimum = searchMin(rightSon);
        minimum->rightSon = deleteMin(rightSon);
        minimum->leftSon = leftSon;
        return balance(minimum);
    }
    return balance(root);
}

