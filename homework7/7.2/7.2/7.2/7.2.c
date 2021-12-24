#include "tree.h"
#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

bool isPassed(Node* tree, int answer)
{
    return calculate(tree) == answer;
}

bool areTestsPassed()
{
    Node* treeTestOne = createTree();
    Node* treeTestTwo = createTree();
    Node* treeTestThree = createTree();
    treeTestOne = makeTree("* (- -1 -10 ) ( + -100  90 ) ");
    treeTestTwo = makeTree("/ (* 500  2) ( - 6  7)");
    treeTestThree = makeTree("(* ( - 5 10 ) (/ ( * ( 2 9 ) 3)))");
    bool isPassedOne = isPassed(treeTestOne, -90);
    bool isPassedTwo = isPassed(treeTestTwo, -1000);
    bool isPassedThree = isPassed(treeTestThree, -30);
    deleteTree(&treeTestOne);
    deleteTree(&treeTestTwo);
    deleteTree(&treeTestThree);
    return
        isPassedOne &&
        isPassedTwo && 
        isPassedThree;
}

int main()
{   
    setlocale(LC_ALL, "rus");
    if (!areTestsPassed())
    {
        printf(":(");
        return -1;
    }
    char string[200] = { '\0' };
    FILE* file = fopen("text.txt", "r");
    if (file == NULL)
    {
        printf(":(");
        return -1;
    }
    fgets(string, 200, file);      
    fclose(file);
    Node* tree = makeTree(string);
    printf("Дерево:\n");
    printTree(tree);
    printf("\nРезультат вычисления:");
    printf("\n%d", calculate(tree));
    deleteTree(&tree);
}