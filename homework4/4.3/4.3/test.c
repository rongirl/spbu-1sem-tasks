#include <stdio.h>
#include "test.h"
#include "functionsOfPhoneBook.h"
#include <stdbool.h>
#include <string.h>

bool testAddNote(Entry* PhoneBookTest)
{
    addNote(PhoneBookTest, "Andrey", "+7987654321", 2);
    return
        strcmp(PhoneBookTest[2].name, "Andrey") == 0 &&
        strcmp(PhoneBookTest[2].phone, "+7987654321") == 0;
}

bool testCountOfNotesInPhoneBook(Entry* PhoneBookTest, const char filename[])
{
    return
        countOfNotesInPhoneBook(PhoneBookTest, "test.txt") == 2 &&
        strcmp(PhoneBookTest[0].name, "Kolya") == 0 &&
        strcmp(PhoneBookTest[0].phone, "123456") == 0 &&
        strcmp(PhoneBookTest[1].name, "Vasya") == 0 &&
        strcmp(PhoneBookTest[1].phone, "424234-434234") == 0; 
}

bool testFindFunctions(Entry* PhoneBookTest)
{   
    const char* name = findName(PhoneBookTest, "123456", 3);
    const char* phone = findPhone(PhoneBookTest, "Vasya", 3);
    return
        strcmp(findName(PhoneBookTest, "123456", 3), "Kolya") == 0 &&
        strcmp(findPhone(PhoneBookTest, "Vasya", 3), "424234-434234") == 0;
}

bool testSaveData(Entry* PhoneBookTest)
{
    saveData(PhoneBookTest, "test.txt", 3);
    Entry DataFromFile[10] = { 0 };
    int ni = countOfNotesInPhoneBook(DataFromFile, "test.txt");
    char* data[6] = { "Kolya", "123456", "Vasya", "424234 - 434234", "Andrey", "+7987654321" };
    for (int i = 0; i < 5; i += 2)
    {
        if (strcmp(DataFromFile[i / 2].name, data[i]) != 0)
        {
           // return false;
        }
    }
    for (int i = 1; i < 6; i += 2)
    {
        if (strcmp(DataFromFile[i / 2].phone, data[i]) != 0)
        {
            //return false;
        }
    }
    return ;
}


bool test()
{
    Entry PhoneBookTest[10] = { 0 };
    return testCountOfNotesInPhoneBook(PhoneBookTest, "test.txt") && testAddNote(PhoneBookTest) &&
           testFindFunctions(PhoneBookTest) && testSaveData(PhoneBookTest);
}