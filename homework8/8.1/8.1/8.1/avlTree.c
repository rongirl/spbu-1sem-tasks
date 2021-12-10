#include "avlTree.h"
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    const char* key;
    const char* value;
    struct Node* leftSon;
    struct Node* rightSon;
    int balance;
} Node;

typedef struct Dictionary
{
    Node* root;
} Dictionary;

Dictionary* createTree()
{
    return calloc(1, sizeof(Dictionary));;
}

bool isEmpty(Dictionary* tree)
{
    return tree->root == NULL;
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

int getHeight(Node* node)
{
    if (node == NULL)
    {
        return 0;
    }
    return getHeightRecursive(node);
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
    free(root->value);
    free(root);
}

void deleteTree(Dictionary** tree)
{
    deleteTreeRecursive((*tree)->root);
    free(*tree);
    (*tree) = NULL;
}

Node* search(Node* root, const char* key)
{
    Node* i = root;
    while (i != NULL)
    {
        if (strcmp(key, i->key) > 0)
        {
            i = i->rightSon;
        }
        else if (strcmp(key, i->key) < 0)
        {
            i = i->leftSon;
        }
        else
        {
            return i;
        }
    }
    return NULL;
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

bool inTree(Dictionary** tree, const char* key)
{
    return search((*tree)->root, key) != NULL;
}

const char* getValue(Dictionary** tree, const char* key)
{
    Node* searchNode = search((*tree)->root, key);
    if (searchNode == NULL)
    {
        return NULL;
    }
    return searchNode->value;
}

Node* insert(Node* node, const char* key, const char* value)
{
    if (node == NULL)
    {
        Node* newNode = calloc(1, sizeof(Node));
        if (newNode == NULL)
        {
            return NULL;
        }
        newNode->balance = 0;
        const char* newValue = calloc(strlen(value) + 1, sizeof(char));
        strcpy(newValue, value);
        const char* newKey = calloc(strlen(value) + 1, sizeof(char));
        strcpy(newKey, key);
        newNode->value = newValue;
        newNode->key = newKey;
        newNode->leftSon = NULL;
        newNode->rightSon = NULL;
        return newNode;
    }
    if (strcmp(node->key, key) == 0)
    {
        free(node->value);
        node->value = value;
        return;
    }
    if (strcmp(key, node->key) > 0)
    {
        node->rightSon = insert(node->rightSon, key, value);
    }
    if (strcmp(key, node->key) < 0)
    {
        node->leftSon = insert(node->leftSon, key, value);
    }
    return balance(node);
}

void addValue(Dictionary* tree, const char* key, const char* value)
{
    const char* newValue = calloc(strlen(value) + 1, sizeof(char));
    const char* newKey = calloc(strlen(key) + 1, sizeof(char));
    if (newValue == NULL || newKey == NULL)
    {
        return NULL;
    }
    strcpy(newValue, value);
    strcpy(newKey, key);
    if (isEmpty(tree))
    {
        Node* newRoot = calloc(1, sizeof(Node));
        newRoot->key = newKey;
        newRoot->value = newValue;
        newRoot->balance = 0;
        newRoot->leftSon = NULL;
        newRoot->rightSon = NULL;
        tree->root = newRoot;
        return newRoot;
    }
    tree->root = insert(tree->root, key, newValue);
    tree->root = balance(tree->root);
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

Node* deleteNode(Node* root, const char* key)
{
    if (root == NULL)
    {
        return 0;
    }
    if (strcmp(key, root->key) < 0)
    {
        root->leftSon = deleteNode(root->leftSon, key);
    }
    else if (strcmp(key, root->key) > 0)
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

void deleteValue(Dictionary** tree, const char* key)
{
    if (isEmpty(*tree))
    {
        return;
    }
    if (!inTree(tree, key))
    {
        return;
    }
    (*tree)->root = deleteNode((*tree)->root, key);
}