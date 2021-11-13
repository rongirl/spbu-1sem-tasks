#include "tree.h"
#include <stdio.h>

int main()
{
    Node* tree = createTree();
    tree = addValue(tree, 5, "hhh");
   // tree = addValue(tree, 1, "sss");
    tree = addValue(tree, 8, "ssss");
    tree = addValue(tree, 10, "qqq");
    printf("%s", getValue(&tree, 5));
    deleteValue(tree, 5);
    //printf("%s", getValue(&tree, 5));
}