#include "tree.h"
#include <stdio.h>

int main()
{
    char string[200] = { '\0' };
    gets(string);
    
    Node* tree = makeTree(string);
    printTree(tree);
    printf("%d", calculate(tree));
    deleteTree(&tree);
}