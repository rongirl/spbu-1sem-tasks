#pragma once 

#include <stdbool.h>

// ��������� ������
typedef struct List List;

// ��������� ������� ���������
typedef struct Position Position;

// �������� �����
List* createList();

// �������� �����, ��������� ������
void deleteList(List* list);

// �������� �������� �� ��������
bool deleteValue(List* list, int value);

// ���������� �������� � ������, ��������� ������ � ��������
void add(List* list, int value);

// �������������� ������, ��������� ������ 
void printList(List* list);

// ���������� ������� ������� ��������
Position* first(List* list);

// ���������� ������� ���������� ��������
Position* next(Position* position);

// �������� �� ��������� �������
bool last(Position* position);

// ���������� �������� �������� �� ��� ������� � ������ 
int get(List* list, Position* position);

// �������� �� ������� ������
bool isEmpty(List* list);