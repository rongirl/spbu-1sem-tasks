#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

typedef struct
{
    char name[50];
    char phone[50];
} Entry;

void begin()
{
    printf("Введите: ");
    printf("0 - выйти \n");
    printf("1 - добавить запись (имя и телефон) \n");
    printf("2 - распечатать все имеющиеся записи \n");
    printf("3 - найти телефон по имени \n");
    printf("4 - найти имя по телефону \n");
    printf("5 - сохранить текущие данные в файл \n");
}

int countOfNotesInPhoneBook(Entry* PhoneBook, char const filename[])
{
    FILE* file = fopen(filename, "r");
    int countOfNotes = 0;
	if (file == NULL)
    {
        printf("File not found");
        return -1;
    }
    char* data[200] = { 0 };
    int linesRead = 0;
    while (!feof(file))
    {
        char* buffer = malloc(sizeof(char) * 100);
        if (buffer == NULL)
        {
            printf(":(");
            fclose(file);
            return -1;
        }
        const int readBytes = fscanf(file, "%s", buffer);
        if (readBytes < 0)
        {
            free(buffer);
            break;
        }
        data[linesRead] = buffer;
        ++linesRead;
    }
    fclose(file);
    for (int i = 0; i < linesRead - 1; i += 2)
    {
        strcpy(PhoneBook[countOfNotes].name, data[i]);
        strcpy(PhoneBook[countOfNotes].phone, data[i + 1]);
        ++countOfNotes;
    }
    for (int i = 0; i < linesRead; i++)
    {
        free(data[i]);
    }
    return countOfNotes;
}

void saveData(Entry* PhoneBook, const char filename[], int countOfNotes)
{
    FILE* file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("File not found");
        return -1;
    }
    for (int i = 0; i < countOfNotes; i++)
    {
        fprintf(file, "%s ", PhoneBook[i].name);
        fprintf(file, "%s\n", PhoneBook[i].phone);
    }
    fclose(file);
}

void addNote(Entry* PhoneBook, const char name[], const char phone[], int countOfNotes)
{
    if (countOfNotes < 100)
    {
        strcpy(PhoneBook[countOfNotes].name, name);
        strcpy(PhoneBook[countOfNotes].phone, phone);
        return;
    }
    printf("Лимит записей превышен.\n");
}

void printAllNotes(Entry* PhoneBook, int countOfNotes)
{
    if (countOfNotes == 0)
    {
		printf("Нет записей\n");
		return;
	}
	for (int i = 0; i < countOfNotes; i++)
	{
		printf("%s ", PhoneBook[i].name);
		printf("%s\n", PhoneBook[i].phone);
	}
}

const char *findName(Entry* PhoneBook, const char phone[], int countOfNotes)
{
	if (countOfNotes == 0)
	{
		return "Нет записей";
	}
	for (int i = 0; i < countOfNotes; i++)
	{
		if (strcmp(PhoneBook[i].phone, phone) == 0)
		{
			return PhoneBook[i].name;
		}
	}
	return "Не найдено";
}

const char *findPhone(Entry* PhoneBook, const char name[], int countOfNotes)
{
	if (countOfNotes == 0)
	{
		return "Нет записей";
	}
	for (int i = 0; i < countOfNotes; i++)
	{
		if (strcmp(PhoneBook[i].name, name) == 0)
		{
			return PhoneBook[i].phone;
		}
	}
	return "Не найдено";
}

int main()
{
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
            }
        }


    }



}