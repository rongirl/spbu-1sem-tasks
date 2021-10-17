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
	printf("4 - ����� ��� �� �������� \n");
	printf("5 - ��������� ������� ������ � ���� \n");
}

void addNote(Entry* PhoneBook, const char name[], const char phone[], int countOfNotes)
{
	strcpy(PhoneBook[countOfNotes].name, name);
	strcpy(PhoneBook[countOfNotes].phone, phone);
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
	printf("%s %s", PhoneBook[0].name, PhoneBook[0].phone);
}