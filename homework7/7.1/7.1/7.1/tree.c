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

void deleteNode(Node* root)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->leftSon != NULL && root->rightSon != NULL)
    {
        Node* maximum = root->leftSon;
        while (maximum->rightSon != NULL)
        {
            maximum = maximum->rightSon;
        }
        root->key = maximum->key;
        root->value = maximum->value;
        deleteNode(maximum);
        return;
    }
    else if (root->leftSon != NULL)
    {   
        if (root->parent == NULL)
        {
            root->key = root->leftSon->key;
            root->value = root->leftSon->value;
            root->leftSon->parent = NULL;
        }
        else if (root == root->parent->leftSon) 
        {
            root->parent->leftSon = root->leftSon;
        }
        else 
        {
            root->parent->rightSon = root->leftSon;
        }
    }
    else if (root->rightSon != NULL)
    {   
        if (root->parent == NULL)
        {
            root->key = root->rightSon->key;
            root->value = root->rightSon->value;
            root->rightSon->parent = NULL;
        } 
        else if (root == root->parent->rightSon) 
        {
            root->parent->rightSon = root->rightSon;
        }
        else 
        {
            root->parent->leftSon = root->rightSon;
        }
    }
    else 
    {
        if (root == root->parent->leftSon) 
        {
            root->parent->leftSon = NULL;
        }
        else 
        {
            root->parent->rightSon = NULL;
        }
    }
    free(root);
}

void deleteValue(Node* root, int key)
{
    Node* current = search(root, key);
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