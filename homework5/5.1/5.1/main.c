#include <stdio.h>
#include <stdbool.h>
#include "..\..\stack\stack\stack.h"
#include <string.h>
#include <locale.h>

int calculate(const char string[])
{   
    StackElement* head = NULL;
    int length = strlen(string);
    for (int i = 0; i < length; i++)
    {
        if (string[i] != '\0' && string[i] != ' ' && string[i] != '\n')
        {
            if (string[i] >= '0' && string[i] <= '9')
            {
                push(&head, string[i] - '0');
            }
            else 
            {   
                if (isEmpty(head))
                {
                    return NULL;
                }
                const int operandOne = pop(&head);
                if (isEmpty(head))
                {
                    return NULL;
                }
                const int operandTwo = pop(&head);
                if (string[i] == '+')
                {
                    push(&head, operandOne + operandTwo);
                }
                else if (string[i] == '-')
                {
                    push(&head, operandTwo - operandOne);
                }
                else if (string[i] == '*')
                {
                    push(&head, operandOne * operandTwo);
                }
                else if (string[i] == '/')
                {   
                    if (operandOne == 0)
                    {   
                        deleteStack(&head);
                        return NULL;
                    }
                    push(&head, operandTwo / operandOne);
                }
            }
        }
    }
    int result = pop(&head);
    if (!isEmpty(head))
    {   
        deleteStack(&head);
        return NULL;
    }
    deleteStack(&head);
    return result;
}

bool isPassed()
{   
    return
        calculate("1 2 + 3 4 + *") == 21 &&
        calculate("3 4 * 5 6 - *") == -12 &&
        calculate("4 2 / 5 6 * *") == 60;
}

int main()
{   
    setlocale(LC_ALL, "rus");
    if (!isPassed())
    {
        printf("Tests failed");
        return -1;
    }
    char string[1000] = { '\0' };
    printf("Введите постфиксную запись выражения: ");
    scanf("\n%[^\n]", &string);
    int result = calculate(string);
    if (result == NULL)
    {
        printf("\nНекорректное выражение");
        return -1;
    }
    printf("\nПолученный результат: %d", result);
}