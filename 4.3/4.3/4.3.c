#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <locale.h>

struct Entry
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

int main()
{
	setlocale(LC_ALL, "rus");
	begin();
}