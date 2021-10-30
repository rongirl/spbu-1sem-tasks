#pragma once

#include <stdbool.h>
#include "functionsOfPhoneBook.h"

// тестирование функции addNote
bool testAddNote(Entry* phoneBookTest);

// тестирование функции countOfNotesInPhoneBook
bool testSaveFirstData(Entry* phoneBookTest, const char filename[]);

// тестирование функции findName, findPhone
bool findFunctions(Entry* phoneBookTest);

// тестирование функции saveData
bool testSaveData(Entry* phoneBookTest);

// тестирование всех функций
bool test();