#include "tree.h"
#include <stdio.h>
#include <locale.h>

void begin()
{   
    printf("������� �����:\n");
    printf("0 - �����.\n");
    printf("1 - �������� �������� �� ��������� ����� � �������.\n");
    printf("2 - �������� �������� �� ��������� ����� �� �������.\n");
    printf("3 - ��������� ������� ��������� ����� � �������.\n");
    printf("4 - ������� �������� ���� � ��������� � ��� �������� �� �������.\n");
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
            printf("������� ����:");
            scanf("%d", &key);
            printf("������� ��������:");
            gets(value);
        }
        }
    }
}