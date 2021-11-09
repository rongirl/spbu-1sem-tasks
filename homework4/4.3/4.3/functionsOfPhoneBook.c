#include "functionsOfPhoneBook.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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

int loadFirstData(Entry* phoneBook, const char filename[])
{
    FILE* file = fopen(filename, "r");
    int countOfNotes = 0;
    if (file == NULL)
    {
        printf("File not found");
        return -1;
    }
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
        if (linesRead % 2 == 0)
        {
            strcpy(phoneBook[countOfNotes].name, buffer);
        }
        else
        {
            strcpy(phoneBook[countOfNotes].phone, buffer);
            ++countOfNotes;
        }
        ++linesRead;
    }
    fclose(file);
    return countOfNotes;
}

void saveData(Entry* phoneBook, const char filename[], int countOfNotes)
{
    FILE* file = fopen(filename, "w");
    if (file == NULL)
    {
        printf("File not found");
        return;
    }
    for (int i = 0; i < countOfNotes; i++)
    {
        fprintf(file, "%s ", phoneBook[i].name);
        fprintf(file, "%s\n", phoneBook[i].phone);
    }
    fclose(file);
}

void addNote(Entry* phoneBook, const char name[], const char phone[], int countOfNotes)
{
    if (countOfNotes < 100)
    {   
        strcpy(phoneBook[countOfNotes].name, name);
        strcpy(phoneBook[countOfNotes].phone, phone);
        return;
    }
    printf("Лимит записей превышен.\n");
}

void printAllNotes(Entry* phoneBook, int countOfNotes)
{
    if (countOfNotes == 0)
    {
        printf("Нет записей\n");
        return;
    }
    for (int i = 0; i < countOfNotes; i++)
    {
        printf("%s ", phoneBook[i].name);
        printf("%s\n", phoneBook[i].phone);
    }
}

const char* findName(Entry* phoneBook, const char phone[], int countOfNotes)
{
    if (countOfNotes == 0)
    {
        return "Нет записей";
    }
    for (int i = 0; i < countOfNotes; i++)
    {
        if (strcmp(phoneBook[i].phone, phone) == 0)
        {
            return phoneBook[i].name;
        }
    }
    return NULL;
}

const char* findPhone(Entry* phoneBook, const char name[], int countOfNotes)
{
    if (countOfNotes == 0)
    {
        return "Нет записей";
    }
    for (int i = 0; i < countOfNotes; i++)
    {
        if (strcmp(phoneBook[i].name, name) == 0)
        {
            return phoneBook[i].phone;
        }
    }
    return NULL;
}
