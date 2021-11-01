#include <stdio.h>
#include "list.h"
#include <locale.h>

int main()
{   
    setlocale(LC_ALL, "rus");
    begin();
    List* list = createList();
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
                break;
            }
           case '1':
           {
               printf("Введите значение: \n");
               int value = 0;
               scanf("%d", &value);
               add(list, value);
               printf("Значение добавлено\n");
               break;
           }
           case '2':
           {
               printf("Введите значение: \n");
               int value = 0;
               scanf("%d", &value);
               if (deleteValue(list, value))
               {
                   printf("Значение было удалено\n");
               }
               else
               {
                   printf("Значение не было найдено\n");
               }
               break;
           }
           case '3':
           {
               printf("Значения в списке\n");
               printList(list);
               printf("\n");
               break;
           }
        }
    }
}