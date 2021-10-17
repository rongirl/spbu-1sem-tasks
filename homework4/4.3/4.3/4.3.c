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
	printf("¬ведите: ");
	printf("0 - выйти \n");
	printf("1 - добавить запись (им€ и телефон) \n");
	printf("2 - распечатать все имеющиес€ записи \n");
	printf("3 - найти телефон по имени \n");
	printf("4 - найти им€ по телефону \n");
	printf("4 - найти им€ по телефону \n");
	printf("5 - сохранить текущие данные в файл \n");
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