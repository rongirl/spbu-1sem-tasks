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
	printf("�������: ");
	printf("0 - ����� \n");
	printf("1 - �������� ������ (��� � �������) \n");
	printf("2 - ����������� ��� ��������� ������ \n");
	printf("3 - ����� ������� �� ����� \n");
	printf("4 - ����� ��� �� �������� \n");
	printf("4 - ����� ��� �� �������� \n");
	printf("5 - ��������� ������� ������ � ���� \n");
}

int main()
{
	setlocale(LC_ALL, "rus");
	begin();
}