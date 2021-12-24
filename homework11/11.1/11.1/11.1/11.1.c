#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>
#include <math.h>

int hashFunction(const char* string, const int startIndex, const int endIndex)
{
    const int base = 3;
    const int size = strlen(string);
    const int module = 10009;
    int hash = 0;
    for (int i = startIndex; i < endIndex; i++)
    {
        hash = (hash * base + string[i]) % module;
    }
    if (hash < 0)
    {
        hash += module;
    }
    return hash;
}

bool isEqual(const char* string, const char* substring, const int startIndex, const int endIndex)
{
    for (int i = startIndex; i < endIndex; i++)
    {
        if (string[i] != substring[i - startIndex])
        {
            return false;
        }
    }
    return true;
} 

int exponentiation(int number, int power, int moduleNumber)
{
    int result = 1;
    while (power)
    {
        if (power & 1)
        {
            result *= number % moduleNumber;
            --power;
        }
        else
        {
            number *= number % moduleNumber;
            power >>= 1;
        }
    }
    return result;
}

int rollingHash(const char* string, const int base, const int baseInPower, const int moduleNumber, 
    const int indexOfPreviousSymbol, const int previousHash, const int lengthOfSubstring)
{
    return 
        ((previousHash - (string[indexOfPreviousSymbol - 1]) * baseInPower) * base + string[indexOfPreviousSymbol - 1 + lengthOfSubstring]) % moduleNumber;
}

int rabinKarp(const char* string, const char* substring)
{   
    const int lengthOfSubstring = strlen(substring);
    const int lengthOfString = strlen(string);
    const int hashSubstring = hashFunction(substring, 0, lengthOfSubstring);
    int hashCurrentString = hashFunction(string, 0, lengthOfSubstring);
    const int base = 3;
    const int module = 10009;
    const int baseInPower = exponentiation(base, lengthOfSubstring - 1, module);
    for (int i = 1; i < lengthOfString - lengthOfSubstring + 2; i++)
    {
        if (hashSubstring == hashCurrentString)
        {
            if (isEqual(string, substring, i - 1, i + lengthOfSubstring - 1))
            {
                return i - 1;
            }
        }
        hashCurrentString = rollingHash(string, base, baseInPower, module, i, hashCurrentString, lengthOfSubstring);
        if (hashCurrentString < 0)
        {
            hashCurrentString += module;
        }
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
        isTestTrue("ai dsid", "sid", 4) &&
        isTestTrue("A middle of adventure,", " of ", 8) &&
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