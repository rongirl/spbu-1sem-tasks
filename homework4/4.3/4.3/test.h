#pragma once

#include <stdbool.h>
#include "functionsOfPhoneBook.h"

// ������������ ������� addNote
bool testAddNote(Entry* phoneBookTest);

// ������������ ������� countOfNotesInPhoneBook
bool testSaveFirstData(Entry* phoneBookTest, const char filename[]);

// ������������ ������� findName, findPhone
bool findFunctions(Entry* phoneBookTest);

// ������������ ������� saveData
bool testSaveData(Entry* phoneBookTest);

// ������������ ���� �������
bool test();