#include "tree.h"
#include <stdlib.h>

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

Node* addValue(Node* root, int key, char* value)
{
    if (isEmpty(root))
    {
        Node* newRoot = calloc(1, sizeof(Node));
        newRoot->key = key;
        newRoot->value = value;
        return newRoot;
    }
    Node* i = root;
    while (i != NULL)
    {
        if (key > i->key)
        {
            if (i->rightSon == NULL)
            {
                Node* newRoot = calloc(1, sizeof(Node));
                newRoot->key = key;
                newRoot->value = value;
                i->rightSon = newRoot;
                newRoot->parent = i;
                return root;
            }
            i = i->rightSon;
        }
        else if (key == i->key)
        {
            i->value = value;
            return root;
        }
        else
        {
            if (i->leftSon == NULL)
            {
                Node* newRoot = calloc(1, sizeof(Node));
                newRoot->key = key;
                newRoot->value = value;
                i->leftSon = newRoot;
                newRoot->parent = i;
                return root;
            }
            i = i->leftSon;
        }
    }
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
