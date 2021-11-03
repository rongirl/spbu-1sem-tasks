#pragma once 

#include <stdbool.h>

// �������� ���������� ������
typedef struct List List;

// ��������� �������� � ������ 
typedef struct ListElement ListElement;

// �������� ������
List* createList();

// ���������� �������� � ������, ��������� ������ � ��������
void add(List* list, int value);

// �������� ��������, ��������� ������ � ������� ��������
void deleteValue(List* list, int position);

// �������� �� ���� ������� � ������, ��������� ������
bool isInListOneElement(List* list);

// ���������� �������� head, ��������� ������
int getValue(List* list);

// �������� ������, ��������� ������
void deleteList(List* list);