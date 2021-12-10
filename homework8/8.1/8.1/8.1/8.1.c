#include <stdio.h>
#include "avlTree.h"
#include <locale.h>

void begin()
{
    printf("0 - �����.\n");
    printf("1 - �������� �������� �� ��������� ����� � �������. ���� ����� ���� ��� ����, �������� ���������� �� �����.\n");
    printf("2 - �������� �������� �� ��������� ����� �� �������.\n");
    printf("3 - ��������� ������� ��������� �����.\n");
    printf("4 - ������� �������� ���� � ��������� � ��� �������� �� �������.\n");
}

bool areTestsPassed()
{
    Dictionary* tree = createTree();
    addValue(tree, "9", "a");
    addValue(tree, "7", "i");
    addValue(tree, "8", "p");
    addValue(tree, "1", "u");
    addValue(tree, "6", "q");
    addValue(tree, "4", "w");
    bool sevenInTree = inTree(&tree, "7");
    bool fiveInTree = inTree(&tree, "5");
    if (strcmp(getValue(&tree, "9"), "a") != 0)
    {
        deleteTree(&tree);
        return false;
    }
    addValue(tree, "9", "b");
    if (strcmp(getValue(&tree, "9"), "b") != 0)
    {
        deleteTree(&tree);
        return false;
    }
    deleteValue(&tree, "8");
    bool eightInTree = inTree(&tree, "8");
    deleteTree(&tree);
    return !eightInTree && sevenInTree && !fiveInTree;
}

int main()
{   
    setlocale(LC_ALL, "rus");
    if (!areTestsPassed())
    {
        printf(":(");
        return -1;
    }
    begin();
    Dictionary* tree = createTree();
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
            char key[30] = { '\0' };
            char value[30] = { '\0' };
            printf("������� ����: ");
            scanf("%s", &key);
            printf("������� ��������: ");
            scanf("%s", &value);
            addValue(tree, key, value);
            printf("�������� � ���� �������\n");
            break;
        }
        case '2':
        {
            char key[30] = { '\0' };
            printf("������� ����: ");
            scanf("%s", &key);
            if (!inTree(&tree, key))
            {
                printf("���� �� ������.\n");
                break;
            }
            printf("��������� ��������: ");
            printf("%s\n", getValue(&tree, key));
            break;
        }
        case '3':
        {
            char key[30] = { '\0' };
            printf("������� ����: ");
            scanf("%s", &key);
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
            char key[30] = { '\0' };
            printf("������� ����: ");
            scanf("%s", &key);
            if (!inTree(&tree, key))
            {
                printf("���� �� ������.\n");
                break;
            }
            deleteValue(&tree, key);
            printf("���� � �������� �������.\n");
            break;
        }
        }
    }
}