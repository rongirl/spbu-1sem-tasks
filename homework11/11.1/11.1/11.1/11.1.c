#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

int hashFunction(const char* string)
{
    const int b = 10000;
    const int size = strlen(string);
    const int module = 1009;
    int hash = 0;
    for (int i = 0; i < size; i++)
    {
        hash = (hash * b + string[i]) % module;
    }
    return hash;
}

int rabinKarp(const char* string, const char* substring)
{   
    int lengthOfSubstring = strlen(substring);
    int lengthOfString = strlen(string);
    char currentString[100] = { '\0' };
    for (int i = 0; i < lengthOfSubstring; i++)
    {
        currentString[i] = string[i];
    }
    int hashSubstring = hashFunction(substring);
    int hashCurrentString = hashFunction(currentString);
    for (int i = 0; i < lengthOfString - lengthOfSubstring + 1; i++)
    {
        if (hashSubstring == hashCurrentString)
        {
            int index = 0; 
            while (index < lengthOfSubstring && substring[index] == currentString[index])
            {
                index++;
            }
            if (index == lengthOfSubstring)
            {
                return i;
            }
        }
        for (int i = 0; i < lengthOfSubstring; i++)
        {
            currentString[i] = '\0';
        }
        for (int j = i + 1; j < lengthOfSubstring + i + 1; j++)
        {
            currentString[j - i - 1] = string[j];
        }
        hashCurrentString = hashFunction(currentString);
    }
    return -1;
}

bool isTestTrue(char const* string, char const* substring, int answer)
{
    return rabinKarp(string, substring) == answer;
}

bool areTestsPassed()
{
    return
        isTestTrue("A middle of adventure,", " of ", 8) &&
        isTestTrue("aiaiaia dsid", "sid", 9) &&
        isTestTrue("ououoouoiii", "uou", 1) &&
        isTestTrue("ahahahah", "ahahahahahah", -1) &&
        isTestTrue("ararararas", "bb", -1);
}

int main()
{   
    setlocale(LC_ALL, "rus");
    if (!areTestsPassed())
    {
        printf(":(");
        return -1;
    }
    FILE* file = fopen("text.txt", "r"); 
    char string[200] = { '\0' };
    fgets(string, 200, file);
    fclose(file);
    char substring[200] = { '\0' };
    printf("Введите подстроку: ");
    scanf("%[^ \n]%*c", substring);
    int answer = rabinKarp(string, substring);
    if (answer == -1)
    {
        printf("Подстрока не найдена.");
        return 0;
    }
    printf("Индекс первого вхождения в строку: %d", answer);
}