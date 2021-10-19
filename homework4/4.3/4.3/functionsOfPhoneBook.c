#include "functionsOfPhoneBook.h"
#include <stdio.h>


void begin()
{
    printf("�������: ");
    printf("0 - ����� \n");
    printf("1 - �������� ������ (��� � �������) \n");
    printf("2 - ����������� ��� ��������� ������ \n");
    printf("3 - ����� ������� �� ����� \n");
    printf("4 - ����� ��� �� �������� \n");
    printf("5 - ��������� ������� ������ � ���� \n");
}

int countOfNotesInPhoneBook(Entry* PhoneBook, const char filename[])
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
    printf("����� ������� ��������.\n");
}

void printAllNotes(Entry* PhoneBook, int countOfNotes)
{
    if (countOfNotes == 0)
    {
        printf("��� �������\n");
        return;
    }
    for (int i = 0; i < countOfNotes; i++)
    {
        printf("%s ", PhoneBook[i].name);
        printf("%s\n", PhoneBook[i].phone);
    }
}

const char* findName(Entry* PhoneBook, const char phone[], int countOfNotes)
{
    if (countOfNotes == 0)
    {
        return "��� �������";
    }
    for (int i = 0; i < countOfNotes; i++)
    {
        if (strcmp(PhoneBook[i].phone, phone) == 0)
        {
            return PhoneBook[i].name;
        }
    }
    return "�� �������";
}

const char* findPhone(Entry* PhoneBook, const char name[], int countOfNotes)
{
    if (countOfNotes == 0)
    {
        return "��� �������";
    }
    for (int i = 0; i < countOfNotes; i++)
    {
        if (strcmp(PhoneBook[i].name, name) == 0)
        {
            return PhoneBook[i].phone;
        }
    }
    return "�� �������";
}
