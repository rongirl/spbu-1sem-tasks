#include <stdio.h>
#include <stdbool.h>
#include "..\..\stack\stack\stack.h"
#include <string.h>
#include <locale.h>ы

int calculate(char string[])
{   
    StackElement* head = NULL;
    for (int i = 0; i < 200; i++)
    {
        if (string[i] != '\0' && string[i] != ' ' && string[i] != '\n')
        {
            if (string[i] - '0' >= 0 && string[i] - '0' <= 9)
            {
                push(&head, string[i] - '0');
            }
            else 
            { 
                int operandOne = pop(&head);
                int operandTwo = pop(&head);
                int current = 0;
                if (string[i] == '+')
                {
                    current = operandOne + operandTwo;
                    push(&head, current);
                }
                else if (string[i] == '-')
                {
                    current = operandTwo - operandOne;
                    push(&head, current);
                }
                else if (string[i] == '*')
                {
                    current = operandOne * operandTwo;
                    push(&head, current);
                }
                else if (string[i] == '/')
                {   
                    if (operandOne == 0)
                    {
                        return -1000000;
                    }
                    current = operandTwo / operandOne;
                    push(&head, current);
                }
            }
        }
    }
    return pop(&head);
}

bool isPassed()
{   
    char stringTestOne[200] = { '\0' };
    char stringTestTwo[200] = { '\0' };
    char stringTestThree[200] = { '\0' };
    strcpy(stringTestOne, "1 2 + 3 4 + *");
    strcpy(stringTestTwo, "3 4 * 5 6 - *");
    strcpy(stringTestThree, "4 2 / 5 6 * *");\
    return
        calculate(stringTestOne) == 21 &&
        calculate(stringTestTwo) == -12 &&
        calculate(stringTestThree) == 60;
}
int main()
{   
    setlocale(LC_ALL, "rus");
    if (!isPassed())
    {
        printf("Tests failed");
        return -1;
    }
    char string[200] = { '\0' };
    printf("Введите постфиксную запись выражения: ");
    scanf("\n%[^\n]", &string);
    if (calculate(string) == -1000000)
    {
        printf("\nПроизошло деление на ноль");
        return -1;
    }
    printf("\nПолученный результат: %d", calculate(string));
}