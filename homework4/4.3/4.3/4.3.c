#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <locale.h>

typedef struct
{
	char name[50];
	char phone[50];
}Entry;

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

void addNote(Entry* PhoneBook, const char name[], const char phone[], int countOfNotes)
{
	strcpy(PhoneBook[countOfNotes].name, name);
	strcpy(PhoneBook[countOfNotes].phone, phone);
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
		printf("%s - %s\n", PhoneBook[i].name, PhoneBook[i].phone);
	}
}

const char *findName(Entry* PhoneBook, const char phone[], int countOfNotes)
{
	if (countOfNotes == 0)
	{
		return "��� �������\n";
	}
	for (int i = 0; i < countOfNotes; i++)
	{
		if (strcmp(PhoneBook[i].phone, phone) == 0)
		{
			return PhoneBook[i].name;
		}
	}
	return "�� �������\n";
}

const char* findPhone(Entry* PhoneBook, const char name[], int countOfNotes)
{
	if (countOfNotes == 0)
	{
		return "��� �������\n";
	}
	for (int i = 0; i < countOfNotes; i++)
	{
		if (strcmp(PhoneBook[i].name, name) == 0)
		{
			return PhoneBook[i].phone;
		}
	}
	return "�� �������\n";
}

int main()
{
	setlocale(LC_ALL, "rus");
	Entry PhoneBook[100] = { '\0' };
	begin();
	const char* name = "Ivan Ivanov";
	const char* phone = "895959595";
	int countOfNotes = 0;
	addNote(PhoneBook, name, phone, countOfNotes);
	++countOfNotes;
	addNote(PhoneBook, name, phone, countOfNotes);
	++countOfNotes;
	printAllNotes(PhoneBook, countOfNotes);
	printf("%s", findName(PhoneBook, "89595955", countOfNotes));
	//printf("%s %s", PhoneBook[0].name, PhoneBook[0].phone);
}