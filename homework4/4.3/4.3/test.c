#include <stdio.h>
#include "test.h"
#include "functionsOfPhoneBook.h"
#include <stdbool.h>
#include <string.h>

bool testAddNote(Entry* phoneBookTest)
{
    addNote(phoneBookTest, "Andrey", "+7987654321", 2);
    return
        strcmp(phoneBookTest[2].name, "Andrey") == 0 &&
        strcmp(phoneBookTest[2].phone, "+7987654321") == 0;
}

bool testSaveFirstData(Entry* phoneBookTest, const char filename[])
{
    return
        saveFirstData(phoneBookTest, "test.txt") == 2;
        strcmp(phoneBookTest[0].name, "Kolya") == 0 &&
        strcmp(phoneBookTest[0].phone, "123456") == 0 &&
        strcmp(phoneBookTest[1].name, "Vasya") == 0 &&
        strcmp(phoneBookTest[1].phone, "424234-434234") == 0; 
}

bool testFindFunctions(Entry* phoneBookTest)
{   
    const char* name = findName(phoneBookTest, "123456", 3);
    const char* phone = findPhone(phoneBookTest, "Vasya", 3);
    return
        strcmp(findName(phoneBookTest, "123456", 3), "Kolya") == 0 &&
        strcmp(findPhone(phoneBookTest, "Vasya", 3), "424234-434234") == 0;
}

bool testSaveData(Entry* phoneBookTest)
{
    saveData(phoneBookTest, "test.txt", 3);
    Entry dataFromFile[10] = { '\0' };
    int ni = saveFirstData(dataFromFile, "test.txt");
    char* data[6] = { "Kolya", "123456", "Vasya", "424234-434234", "Andrey", "+7987654321" };
    for (int i = 0; i < 5; i += 2)
    {
        if (strcmp(dataFromFile[i / 2].name, data[i]) != 0)
        {
            return false;
        }
    }
    for (int i = 1; i < 6; i += 2)
    {
        if (strcmp(dataFromFile[i / 2].phone, data[i]) != 0)
        {
            return false;
        }
    }
   return true;
}

bool test()
{
    Entry phoneBookTest[10] = { 0 };
    return
        testSaveFirstData(phoneBookTest, "test.txt") &&
        testFindFunctions(phoneBookTest) && 
        testAddNote(phoneBookTest) && 
        testSaveData(phoneBookTest);
}