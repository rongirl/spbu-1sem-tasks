#pragma once 

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

// ��������� ������
typedef struct List List;

// ��������� ������� ���������
typedef struct Position Position;

// �������� �����
List* createList();

// �������� �����, ��������� ������
void deleteList(List* list);

// ���������� �������� � ������, ��������� ������ � ��������
void add(List* list, int value);

// �������������� ������, ��������� ������ 
void printList(List* list);

// ��������������� ������
List* reverseList(List* list);

bool isEmpty(List* list);

bool checkReverse(List* list, int* array);