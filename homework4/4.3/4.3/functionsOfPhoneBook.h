#pragma once 

// ��������� �����������
typedef struct
{
    char name[50];
    char phone[50];
} Entry;

// ������ ���������, ����� ������������
void begin();

// ������� ���������� ������ � ����� � ������ ���������
int loadFirstData(Entry* phoneBook, const char filename[]);

// ���������� ������ �� ����������� � ����
void saveData(Entry* phoneBook, const char filename[], int countOfNotes);

// ���������� ����� � �������� � ����������
void addNote(Entry* phoneBook, const char name[], const char phone[], int countOfNotes);

// �������������� ���� ������� � �����������
void printAllNotes(Entry* phoneBook, int countOfNotes);

// ���������� ����� �� ������ �������� � �����������
const char* findName(Entry* phoneBook, const char phone[], int countOfNotes);

// ���������� ������ �������� �� ����� � �����������
const char* findPhone(Entry* phoneBook, const char name[], int countOfNotes);