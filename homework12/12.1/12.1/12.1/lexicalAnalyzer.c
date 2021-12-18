#include "lexicalAnalyzer.h"
#include <stdbool.h>
#include <string.h>

bool isDigit(char symbol)
{
    return symbol <= '9' && symbol >= '0';
}

bool lexicalAnalyzer(const char* string)
{
    int length = strlen(string);
    int state = 0;
    for (int i = 0; i <= length; i++)
    {
        switch (state) 
        {
        case 0:
        {
            if (isDigit(string[i]))
            {
                state = 1;
                break;
            }
            return false;
        }
        case 1:
        {
            if (isDigit(string[i]))
            {
                state = 1;
                break;
            }
            if (string[i] == '.')
            {
                state = 2;
                break;
            }
            if (string[i] == 'E')
            {
                state = 4;
                break;
            }
            return string[i] == '\0';
        }
        case 2:
        {
            if (isDigit(string[i]))
            {
                state = 3;
                break;
            }
            return false;
        }  
        case 3:
        {
            if (isDigit(string[i]))
            {
                state = 3;
                break;
            }
            if (string[i] == 'E')
            {
                state = 4;
                break;
            }
            return string[i] == '\0';
        }
        case 4:
        {   
            if (string[i] == '+' || string[i] == '-')
            {
                state = 5;
                break;
            }
            if (isDigit(string[i]))
            {
                state = 6;
                break;
            }
            return false;
        }
        case 5:
        {
            if (isDigit(string[i]))
            {
                state = 6;
                break;
            }
            return false;
        }
        case 6:
        {
            if (isDigit(string[i]))
            {
                state = 6;
                break;
            }
            return string[i] == '\0';
        }
        }
    }
}