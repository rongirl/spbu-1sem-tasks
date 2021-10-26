#include "..\..\stack\stack\stack.h"
#include <stdio.h>
#include <locale.h>
#include <string.h>

bool isCorrectSequence(const char string[])
{
    StackElement* head = NULL;
    for (int i = 0; i < 200; i++)
    {   
        if (string[i] != '\0' && string[i] != '\n')
        {
            if (string[i] == '(' || string[i] == '{' || string[i] == '[')
            {
                push(&head, string[i]);
            }
            else if (!isEmpty(head))
            {
                if (string[i] == ')' && pop(&head) != '(')
                {
                    return false;
                }
                else if (string[i] == '}' && pop(&head) != '{')
                {
                    return false;
                }
                else if (string[i] == ']' && pop(&head) != '[')
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        } 
    }
    return isEmpty(head);
}

bool isPassed()
{
    char stringTestOne[200] = { '\0' };
    char stringTestTwo[200] = { '\0' } ;
    char stringTestThree[200] = { '\0' };
    char stringTestFour[200] = { '\0' };
    strcpy(stringTestOne, "([{}])([])");
    strcpy(stringTestTwo, "(([[}}))");
    strcpy(stringTestThree, "(((]]]");
    strcpy(stringTestFour, "[](){}()");
    return
        isCorrectSequence(stringTestOne) &&
        !isCorrectSequence(stringTestTwo) &&
        !isCorrectSequence(stringTestThree) &&
        isCorrectSequence(stringTestFour);
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
    printf("Введите скобочную последовательность: ");
    scanf("%s", &string);
    if (isCorrectSequence(string))
    {
        printf("Была введена правильная последовательность.");
        return 0;
    }
    printf("Была введена неправильная последовательность.");
}