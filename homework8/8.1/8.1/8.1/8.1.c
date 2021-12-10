#include <stdio.h>
#include "avlTree.h"
#include <locale.h>

void begin()
{
    printf("0 - выйти.\n");
    printf("1 - добавить значение по заданному ключу в словарь. Если такой ключ уже есть, значение заменяется на новое.\n");
    printf("2 - получить значение по заданному ключу из словаря.\n");
    printf("3 - проверить наличие заданного ключа.\n");
    printf("4 - удалить заданный ключ и связанное с ним значение из словаря.\n");
}

bool areTestsPassed()
{
    Node* tree = createTree();
    tree = addValue(tree, 9, "a");
    tree = addValue(tree, 7, "i");
    tree = addValue(tree, 8, "p");
    tree = addValue(tree, 1, "u");
    tree = addValue(tree, 6, "q");
    tree = addValue(tree, 4, "w");
    bool sevenInTree = inTree(&tree, 7);
    bool fifeInTree = inTree(&tree, 5);
    if (strcmp(getValue(&tree, 9), "a") != 0)
    {
        deleteTree(&tree);
        return false;
    }
    tree = addValue(tree, 9, "b");
    if (strcmp(getValue(&tree, 9), "b") != 0)
    {
        deleteTree(&tree);
        return false;
    }
    tree = deleteValue(tree, 8);
    bool eightInTree = inTree(&tree, 8);
    if (deleteValue(tree, 20) == 0)
    {
        deleteTree(&tree);
        return false;
    }
    return deleteValue(tree, 100);
}

int main()
{   
   /* setlocale(LC_ALL, "rus");
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
            printf("Введите ключ: ");
            scanf("%d", &key);
            printf("Введите значение: ");
            scanf("%s", &value);
            tree = addValue(tree, key, value);
            printf("Значение и ключ введены\n");
            break;
        }
        case '2':
        {
            int key = 0;
            printf("Введите ключ: ");
            scanf("%d", &key);
            if (!inTree(&tree, key))
            {
                printf("Ключ не найден.\n");
                break;
            }
            printf("Найденное значение: ");
            printf("%s\n", getValue(&tree, key));
            break;
        }
        case '3':
        {
            int key = 0;
            printf("Введите ключ: ");
            scanf("%d", &key);
            if (inTree(&tree, key))
            {
                printf("Ключ найден\n");
                break;
            }
            printf("Ключ не найден\n");
            break;
        }
        case '4':
        {
            int key = 0;
            printf("Введите ключ: ");
            scanf("%d", &key);
            if (!inTree(&tree, key))
            {
                printf("Ключ не найден.\n");
                break;
            }
            tree = deleteValue(tree, key);
            printf("Ключ и значение удалены.\n");
            break;
        }
        }
    }
    */
    Node* tree = createTree();
    tree = addValue(tree, 4, "q");
    tree = addValue(tree, 18, "a");
    tree = addValue(tree, 16, "b");
    tree = addValue(tree, 14, "c");
    tree = addValue(tree, 10, "d");
    tree = addValue(tree, 3, "e");
    tree = addValue(tree, 1, "s");
    tree = deleteValue(tree, 10);

    deleteTree(&tree);
}