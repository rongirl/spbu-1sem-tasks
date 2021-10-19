#pragma once
#include <stdbool.h>
#include "functionsOfPhoneBook.h"
//тестирование функции addNote
bool testAddNote(Entry* PhoneBookTest);
//тестирование функции countOfNotesInPhoneBook
bool testCountOfNotesInPhoneBook(Entry* PhoneBookTest, const char filename[]);
//тестирование функции findName, findPhone
bool findFunctions(Entry* PhoneBookTest);
//тестирование функции saveData
bool testSaveData(Entry* PhoneBookTest);
//тестирование всех функций
bool test();