#pragma once 

//структуры справочника
typedef struct
{
    char name[50];
    char phone[50];
} Entry;
//начало программы, вывод пользователю
void begin();
//функция считывания данных с файла в начале программы
int countOfNotesInPhoneBook(Entry* PhoneBook, const char filename[]);
//сохранение данных со справочника в файл
void saveData(Entry* PhoneBook, const char filename[], int countOfNotes);
//добавление имени и телефона в справочник
void addNote(Entry* PhoneBook, const char name[], const char phone[], int countOfNotes);
//распечатывание всех записей в справочнике
void printAllNotes(Entry* PhoneBook, int countOfNotes);
//нахождение имени по номеру телефона в справочнике
const char* findName(Entry* PhoneBook, const char phone[], int countOfNotes);
//нахождение номера телефона по имени в справочнике
const char* findPhone(Entry* PhoneBook, const char name[], int countOfNotes);