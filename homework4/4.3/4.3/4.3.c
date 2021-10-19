#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <locale.h>
#include <stdbool.h>
#include "functionsOfPhoneBook.h"
#include "test.h"

int main()
{   
    if (!test())
    {
        printf(":(");
        return -1;
    }
    setlocale(LC_ALL, "rus");
    Entry PhoneBook[100] = { '\0' };
    begin();
    bool flag = true;
    int countOfNotes = countOfNotesInPhoneBook(PhoneBook, "base.txt");
    while (flag)
    {
        char input = '\0';
        scanf("%c", &input);
        switch (input)
        {
            case '0':
            {
                flag = false;
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
                addNote(PhoneBook, name, phone, countOfNotes);
                ++countOfNotes;
                break;
            }
            case '2':
            {
                printf("Все имеющиеся записи: \n");
                printAllNotes(PhoneBook, countOfNotes);
                break;
            }
            case '3':
            {   
                char name[50] = { '\0 ' };
                printf("Введите имя:\n");
                scanf("\n%[^\n]", name);
                printf("%s\n", findPhone(PhoneBook, name, countOfNotes));
                break;
            }
            case '4':
            {
                char phone[50] = { '\0 ' };
                printf("Введите номер телефона:\n");
                scanf("\n%[^\n]", phone);
                printf("%s\n", findName(PhoneBook, phone, countOfNotes));
                break;
            } 
            case '5':
            {
                saveData(PhoneBook, "base.txt", countOfNotes);
                printf("Данные сохранены\n");
                break;
            }
        }
    }
}