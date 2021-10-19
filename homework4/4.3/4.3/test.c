#include <stdio.h>
#include "test.h"
#include "functionsOfPhoneBook.h"
#include <stdbool.h>

bool testAddNote()
{
    addNote(PhoneBookTest, "Andrey Ivanov", "+7987654321", 0);
    return
        strcmp(PhoneBookTest[0].name, "Andrey Ivanov") == 0 &&
        strcmp(PhoneBookTest[0].phone, "+7987654321") == 0;
}

bool test()
{
    Entry PhoneBookTest[3] = { 0 };
}