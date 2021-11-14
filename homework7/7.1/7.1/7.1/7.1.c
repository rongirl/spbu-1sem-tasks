#include "tree.h"
#include <stdio.h>
#include <locale.h>

void begin()
{   
    printf("¬ведите число:\n");
    printf("0 - выйти.\n");
    printf("1 - добавить значение по заданному ключу в словарь.\n");
    printf("2 - получить значение по заданному ключу из словар€.\n");
    printf("3 - проверить наличие заданного ключа в словаре.\n");
    printf("4 - удалить заданный ключ и св€занное с ним значение из словар€.\n");
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
    bool fifeInTree = inTree(&tree, 5);
    deleteValue(tree, 8);
    bool eightInTree = inTree(&tree, 8);
    if (strcmp(getValue(&tree, 9), "arara") != 0 || strcmp(getValue(&tree, 7), "iii") != 0)
    {
        deleteTree(&tree);
        return false;
    }
    deleteTree(&tree);
    return sevenInTree && !fifeInTree && !eightInTree;
}

int main()
{   
    setlocale(LC_ALL, "rus");
    if (!areTestsPassed())
    {
        printf(":(");
    }
    begin();
    Node* tree = createTree();
    bool isNotNull = true;
    while (isNotNull)
    {
        char input = '\0';
        scanf("%c", &input);
        switch (input)
        {
            case '0':
            {
                isNotNull = false;
                deleteTree(&tree);
                break;
            }
            case '1':
            {
                int key = 0;
                char value[30] = { '\0' };
                printf("¬ведите ключ:");
                scanf("%d", &key);
                printf("¬ведите значение:");
                scanf("%s", &value);
                tree = addValue(tree, key, value);
                printf("«начение добавлено\n");
                break;
            }
            case '2':
            {
                int key = 0;
                printf("¬ведите ключ:");
                scanf("%d", &key);
                if (!inTree(&tree, key))
                {
                    printf(" люч отсутствует\n");
                    break;
                }
                printf("«начение по ключу найдено:");
                printf("%s\n", getValue(&tree, key));
                break;
            }
            case '3':
            {
                int key = 0;
                printf("¬ведите ключ:");
                scanf("%d", &key);
                if (inTree(&tree, key))
                {
                    printf(" люч найден\n");
                    break;
                }
                printf(" люч не найден\n");
                break;
            }
            case '4':
            {
                int key = 0;
                printf("¬ведите ключ:");
                scanf("%d", &key);
                if (!inTree(&tree, key))
                {
                    printf(" люч не найден\n");
                    break;
                }
                deleteValue(tree, key);
                printf(" люч и значение удалены\n");
                break;
            }
        }
    }
}