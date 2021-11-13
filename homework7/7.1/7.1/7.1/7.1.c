#include "tree.h"
#include <stdio.h>

int main()
{
    Node* tree = createTree();
    tree = addValue(tree, 5, "hhh");
    printf("%d", inTree(&tree, 6));
    printf("%s", getValue(&tree, 5));
    tree = addValue(tree, 5, "hhhff");
    printf("%d", inTree(&tree, 6));
    printf("%s", getValue(&tree, 5));
}