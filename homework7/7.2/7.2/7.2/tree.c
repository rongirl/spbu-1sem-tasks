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

int getNumber(char* string, int* index)
{
    int number = 0;
    while (string[*index] >= '0' && string[*index] <= '9')
    {
        number = 10 * number + (string[*index] - ' 0');
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