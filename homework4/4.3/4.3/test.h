#pragma once
#include <stdbool.h>
#include "functionsOfPhoneBook.h"
//������������ ������� addNote
bool testAddNote(Entry* PhoneBookTest);
//������������ ������� countOfNotesInPhoneBook
bool testCountOfNotesInPhoneBook(Entry* PhoneBookTest, const char filename[]);
//������������ ������� findName, findPhone
bool findFunctions(Entry* PhoneBookTest);
//������������ ������� saveData
bool testSaveData(Entry* PhoneBookTest);
//������������ ���� �������
bool test();