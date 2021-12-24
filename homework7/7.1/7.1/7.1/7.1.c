#include "tree.h"
#include <stdio.h>
#include <locale.h>
#include <string.h>

void begin()
{   
    printf("������� �����:\n");
    printf("0 - �����.\n");
    printf("1 - �������� �������� �� ��������� ����� � �������.\n");
    printf("2 - �������� �������� �� ��������� ����� �� �������.\n");
    printf("3 - ��������� ������� ��������� ����� � �������.\n");
    printf("4 - ������� �������� ���� � ��������� � ��� �������� �� �������.\n");
}
 
bool isTrue()
{
    Node* tree = createTree();
    tree = addValue(tree, 4, "4");
    tree = addValue(tree, 5, "5");
    tree = addValue(tree, 2, "2");
    tree = addValue(tree, 8, "8");
    deleteValue(&tree, 5);
    deleteValue(&tree, 8);
    deleteValue(&tree, 4);
    deleteTree(&tree);
    return true;
}

bool areTestsPassed()
{
    Node* tree = createTree();
    tree = addValue(tree, 9, "arara");
    tree = addValue(tree, 7, "iii");
    tree = addValue(tree, 8, "ppp");
    tree = addValue(tree, 1, "uuu");
    tree = addValue(tree, 6, "qqq");
    tree = addValue(tree, 4, "www");
    bool sevenInTree = inTree(&tree, 7);
    bool fiveInTree = inTree(&tree, 5);
    deleteValue(&tree, 8);
    deleteValue(&tree, 10);
    bool tenInTree = inTree(&tree, 10);
    bool eightInTree = inTree(&tree, 8);
    if (strcmp(getValue(tree, 9), "arara") != 0 || strcmp(getValue(tree, 7), "iii") != 0)
    {
        deleteTree(&tree);
        return false;
    }
    deleteTree(&tree);
    return sevenInTree && !fiveInTree && !eightInTree && !tenInTree;
}

int main()
{   
    setlocale(LC_ALL, "rus");
    if (!areTestsPassed() || !isTrue())
    {
        printf(":(");
        return -1;
    }
    begin();
    Node* tree = createTree();
    bool shallContinue = true;
    while (shallContinue)
    {
        char input = '\0';
        scanf("%c", &input);
        switch (input)
        {
        case '0':
        {
            shallContinue = false;
            deleteTree(&tree);
            break;
        }
        case '1':
        {
            int key = 0;
            char value[30] = { '\0' };
            printf("������� ����:");
            scanf("%d", &key);
            printf("������� ��������:");
            scanf("%s", &value);
            tree = addValue(tree, key, value);
            printf("�������� ���������\n");
            break;
        }
        case '2':
        {
            int key = 0;
            printf("������� ����:");
            scanf("%d", &key);
            if (!inTree(&tree, key))
            {
                printf("���� �����������\n");
                break;
            }
            printf("�������� �� ����� �������:");
            printf("%s\n", getValue(tree, key));
            break;
        }
        case '3':
        {
            int key = 0;
            printf("������� ����:");
            scanf("%d", &key);
            if (inTree(&tree, key))
            {
                printf("���� ������\n");
                break;
            }
            printf("���� �� ������\n");
            break;
        }
        case '4':
        {
            int key = 0;
            printf("������� ����:");
            scanf("%d", &key);
            if (!inTree(&tree, key))
            {
                printf("���� �� ������\n");
                break;
            }
            deleteValue(&tree, key);
            printf("���� � �������� �������\n");
            break;
        }
        }
    }
}