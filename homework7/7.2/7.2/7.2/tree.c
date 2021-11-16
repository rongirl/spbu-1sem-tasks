#include "tree.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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

int getNumber(char* string, int* index)
{
    int number = 0;
    int length = strlen(string);
    while (string[*index] >= '0' && string[*index] <= '9' && (*index) < length)
    {
        int current = string[*index] - '0';
        number = number * 10 + current;
        ++(*index);
    }
    return number;
}

Node* createNewNode(char* string, int* index)
{
    ++(*index);
    while (string[*index] == '(' || string[*index] == ')' || string[*index] == ' ')
    {
        ++(*index);
    }
    Node* newNode = calloc(1, sizeof(Node));
    if (string[*index] == '+' || string[*index] == '-' || string[*index] == '/' || string[*index] == '*')
    {
        newNode->operation = string[*index];
        newNode->leftSon = createNewNode(string, index);
        newNode->rightSon = createNewNode(string, index);
    }
    else
    {
        newNode->operand = getNumber(string, index);
    }
    return newNode;
}

Node* makeTree(char* string)
{
    int index = -1;
    Node* tree = createTree();
    tree = createNewNode(string, &index);
    return tree;
}

int calculateRecursive(Node* node)
{
    if (node->leftSon == NULL && node->rightSon == NULL)
    {
        return node->operand;
    }
    const int operandOne = calculateRecursive(node->leftSon);
    const int operandTwo = calculateRecursive(node->rightSon);
    char operation = node->operation;
    switch (operation)
    {
        case '+':
        {
            return operandOne + operandTwo;
        }
        case '-':
        {
            return operandOne - operandTwo;
        }
        case '*':
        {
            return operandOne * operandTwo;
        }
        case '/':
        {
            return operandOne / operandTwo;
        }
    }
}

int calculate(Node* root)
{
    return calculateRecursive(root);
}

void printTreeRecursive(Node* root)
{
    if (root->leftSon == NULL && root->rightSon == NULL)
    {
        printf("%d ", root->operand);
        return;
    }
    printf("( %c ", root->operation);
    printTreeRecursive(root->leftSon);
    printf(" ");
    printTreeRecursive(root->rightSon);
    printf(" )");
    return;
}

void printTree(Node* root)
{
    if (root == NULL)
    {
        return;
    }
    printTreeRecursive(root);
}