#include "tree.h"
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    struct Node* leftSon;
    struct Node* rightSon;
    struct Node* parent;
    int key;
    char* value; 
} Node;

Node* createTree()
{
    return NULL;
}

bool isEmpty(Node* root)
{
    return root == NULL;
}

Node* createNode(int key, char* value)
{
    Node* newNode = calloc(1, sizeof(Node));
    if (newNode == NULL)
    {
        return NULL;
    }
    newNode->key = key;
    char* newValue = calloc(strlen(value) + 1, sizeof(char));
    strcpy(newValue, value);
    newNode->value = newValue;
    return newNode;
}

Node* addValue(Node* root, int key, char* value)
{
    if (isEmpty(root))
    {
        return createNode(key, value);
    }
    Node* i = root;
    while (i != NULL)
    {
        if (key > i->key)
        {
            if (i->rightSon == NULL)
            {
                Node* newNode = createNode(key, value);
                i->rightSon = newNode;
                newNode->parent = i;
                return root;
            }
            i = i->rightSon;
        }
        else if (key == i->key)
        {
            char* newValue = calloc(strlen(value) + 1, sizeof(char));
            strcpy(newValue, value);
            free(i->value);
            i->value = newValue;
            free(newValue);
            return root;
        }
        else
        {
            if (i->leftSon == NULL)
            {
                Node* newNode = createNode(key, value);
                i->leftSon = newNode;
                newNode->parent = i;
                return root;
            }
            i = i->leftSon;
        }
    }
    return NULL;
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
    return NULL;
}

bool inTree(Node** root, int key)
{   
    return search(*root, key) != NULL;
}

char* getValue(Node* root, int key)
{   
    Node* searchNode = search(root, key);
    if (searchNode == NULL)
    {
        return NULL;
    }
    return searchNode->value;
}

Node* findMaximum(Node* node)
{
    Node* maximum = node->leftSon;
    while (maximum->rightSon != NULL)
    {
        maximum = maximum->rightSon;
    }
    return maximum;
}

void deleteNode(Node* node)
{
    if (node->leftSon != NULL && node->rightSon != NULL)
    {
        Node* maximum = findMaximum(node);
        node->key = maximum->key;
        char* newValue = calloc(strlen(maximum->value) + 1, sizeof(char));
        strcpy(newValue, maximum->value);
        free(node->value);
        node->value = newValue;
        deleteNode(maximum);
        return;
    }
    else if (node->leftSon != NULL)
    {   
        if (node == node->parent->leftSon) 
        {
            node->parent->leftSon = node->leftSon;
        }
        else 
        {
            node->parent->rightSon = node->leftSon;
        }
    }
    else if (node->rightSon != NULL)
    {   
        if (node == node->parent->rightSon) 
        {
            node->parent->rightSon = node->rightSon;
        }
        else 
        {
            node->parent->leftSon = node->rightSon;
        }
    }
    else 
    {
        if (node == node->parent->leftSon) 
        {
            node->parent->leftSon = NULL;
        }
        else 
        {
            node->parent->rightSon = NULL;
        }
    }
    free(node->value);
    free(node);
}

Node* deleteRoot(Node* root)
{   
    Node* newRoot = calloc(1, sizeof(Node));
    if (root->leftSon != NULL && root->rightSon != NULL)
    {
        Node* maximum = findMaximum(root);
        newRoot->key = maximum->key;
        char* newValue = calloc(strlen(maximum->value) + 1, sizeof(char));
        strcpy(newValue, maximum->value);
        newRoot->value = newValue;
        deleteNode(maximum);
        newRoot->leftSon = root->leftSon;
        newRoot->rightSon = root->rightSon;
        if (root->leftSon != NULL)
        {
            root->leftSon->parent = newRoot;
        }
        if (root->rightSon != NULL)
        {
            root->rightSon->parent = newRoot;
        }
    }
    else if (root->rightSon == NULL)
    {
        newRoot = root->leftSon;
    }
    else
    {
        newRoot = root->rightSon;
    }
    free(root->value);
    free(root);
    return newRoot;
}

void deleteValue(Node** root, int key)
{   
    if (isEmpty(*root))
    {
        return;
    }
    Node* current = search(*root, key);
    if (current == NULL)
    {
        return;
    }
    if (current->parent == NULL)
    {
        (*root) = deleteRoot(current);
        return;
    }
    deleteNode(current);
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