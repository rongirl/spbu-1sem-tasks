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

int main()
{   
    setlocale(LC_ALL, "rus");
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
            gets(value);
        }
        }
    }
}