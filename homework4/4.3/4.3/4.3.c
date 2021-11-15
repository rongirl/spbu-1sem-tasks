#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include "functionsOfPhoneBook.h"
#include "test.h"

int main()
{   
    setlocale(LC_ALL, "rus");
    if (!test())
    {   
        printf("Все плохо :(");
        return -1;
    }
    Entry phoneBook[100] = { 0 };
    begin();
    bool isNotNull = true;
    int countOfNotes = loadFirstData(phoneBook, "base.txt");
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
                char name[50] = { '\0' };
                printf("Введите имя:\n");
                scanf("\n%[^\n]", name);
                char phone[50] = { '\0' };
                printf("Введите номер телефона:\n");
                scanf("\n%[^\n]", phone);
                addNote(phoneBook, name, phone, countOfNotes);
                ++countOfNotes;
                break;
            }
            case '2':
            {
                printf("Все имеющиеся записи: \n");
                printAllNotes(phoneBook, countOfNotes);
                break;
            }
            case '3':
            {   
                char name[50] = { '\0 ' };
                printf("Введите имя:\n");
                scanf("\n%[^\n]", name);
                if (findPhone(phoneBook, name, countOfNotes) == NULL)
                {
                    printf("Запись не найдена.\n");
                    break;
                }
                printf("%s\n", findPhone(phoneBook, name, countOfNotes));
                break;
            }
            case '4':
            {
                char phone[50] = { '\0 ' };
                printf("Введите номер телефона:\n");
                scanf("\n%[^\n]", phone);
                if (findName(phoneBook, phone, countOfNotes) == NULL)
                {
                    printf("Запись не найдена.\n");
                    break;
                }
                printf("%s\n", findName(phoneBook, phone, countOfNotes));
                break;
            } 
            case '5':
            {
                saveData(phoneBook, "base.txt", countOfNotes);
                printf("Данные сохранены\n");
                break;
            }
        }
    }
}