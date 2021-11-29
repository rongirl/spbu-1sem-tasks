#include <stdio.h>
#include "avlTree.h"



int main()
{
    Node* tree = createTree();
    tree = addValue(tree, 5, "opopo");
    tree = addValue(tree, 4, "aaa");
    tree = addValue(tree, 3, "sss");
    tree = addValue(tree, 2, "ppp");
    tree = addValue(tree, 1, "ddd");
    tree = addValue(tree, 0, "qqq");
    tree = deleteNode(tree, 7);
    tree = deleteNode(tree, 7);

    deleteTree(&tree);
}