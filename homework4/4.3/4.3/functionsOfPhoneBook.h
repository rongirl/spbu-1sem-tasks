#pragma once 

typedef struct
{
    char name[50];
    char phone[50];
} Entry;

void begin();

int countOfNotesInPhoneBook(Entry* PhoneBook, const char filename[]);

void saveData(Entry* PhoneBook, const char filename[], int countOfNotes);

void addNote(Entry* PhoneBook, const char name[], const char phone[], int countOfNotes);

void printAllNotes(Entry* PhoneBook, int countOfNotes);

const char* findName(Entry* PhoneBook, const char phone[], int countOfNotes);

const char* findPhone(Entry* PhoneBook, const char name[], int countOfNotes);