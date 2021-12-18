#include <stdio.h>
#include <stdbool.h>
#include <string.h>

int main()
{
    char string[100] = { '\0' };
    scanf("%s", &string);
    int index = 0;
    int state = 0;
    int length = strlen(string);
    while (index < length)
    {
        char input = string[index];
        switch (state)
        {
        case 0:
        {
            if (input <= '9' && input >= '0')
            {
                state = 1;
                index++;
                break;
            }
            else
            {
                state = 10;
                break;
            }
        }
        case 1:
        {
            if (input <= '9' && input >= '0')
            {
                state = 2;
                index++;
                break;
            }
            else
            {
                state = 10;
                break;
            }
        }
        case 2:
        {
            if (input == '.')
            {
                state = 3;
                index++;
                break;
            }
            else
            {
                state = 10;
                break;
            }
        }
        case 3:
        {
            if (input == 'B' || input == 'S' || input == 'M')
            {
                state = 4;
                index++;
                break;
            }
            else
            {
                state = 10;
                break;
            }
        }
        case 4:
        {
            if (input <= '9' && input >= '0')
            {
                state = 5;
                index++;
                break;
            }
            else
            {
                state = 10;
                break;
            }
        }
        case 5:
        {
            if (input <= '9' && input >= '0')
            {
                state = 6;
                index++;
                break;
            }
            else
            {
                state = 10;
                break;
            }
        }
        case 6:
        {
            if (input == '-')
            {
                state = 7;
                index++;
                break;
            }
            else
            {
                state = 10;
                break;
            }
        }
        case 7:
        {
            if (input == 'm')
            {
                state = 8;
                index++;
                break;
            }
            else
            {
                state = 10;
                break;
            }
        }
        case 8:
        {
            if (input == 'm')
            {
                state = 9;
                index++;
                break;
            }
            else
            {
                state = 10;
                break;
            }
        }
        case 10:
        {
            printf("Incorrect");
            return 0;
        }
        }
    }
    printf("Correct");
}