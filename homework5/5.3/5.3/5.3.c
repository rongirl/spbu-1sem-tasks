#include "..\..\stack\stack\stack.h"
#include <string.h>
#include <stdio.h>
#include <locale.h>

int priority(char operator)
{   
    switch (operator)
    {
        case '/':
        case '*':
        {
            return 1;
        }
        case '+':
        case '-':
        {
            return 2;
        }
        case '(':
        {
            return 3;
        }
    }
    return 100;
}

void convertToPostfix(char postfix[], const char infix[])
{
    StackElement* head = NULL;
    int indexOfPostfix = 0;
    int length = strlen(infix);
    for (int i = 0; i < length; i++)
    {
        if (infix[i] != '\0' && infix[i] != ' ' && infix[i] != '\n')
        {
            if (infix[i] >= '0' && infix[i] <= '9')
            {
                postfix[indexOfPostfix] = infix[i];
                ++indexOfPostfix;
                postfix[indexOfPostfix] = ' ';
                ++indexOfPostfix;
            }
            else switch (infix[i])
            {
            case '+':
            case '-':
            case '*':
            case '/':
            {
                while (!isEmpty(head))
                {
                    char operatorInStack = pop(&head);
                    if (priority(infix[i]) >= priority(operatorInStack))
                    {
                        postfix[indexOfPostfix] = operatorInStack;
                        ++indexOfPostfix;
                        postfix[indexOfPostfix] = ' ';
                        ++indexOfPostfix;
                    }
                    else
                    {
                        push(&head, operatorInStack);
                        break;
                    }
                }
                push(&head, infix[i]);
                break;
            }
            case '(':
            {
                push(&head, infix[i]);
                break;
            }
            case ')':
            {
                char operatorInStack = pop(&head);
                while (operatorInStack != '(')
                {
                    postfix[indexOfPostfix] = operatorInStack;
                    ++indexOfPostfix;
                    postfix[indexOfPostfix] = ' ';
                    ++indexOfPostfix;
                    operatorInStack = pop(&head);
                }
                break;
            }
            }
        }
    }
    while (!isEmpty(head))
    {
        postfix[indexOfPostfix] = pop(&head);
        ++indexOfPostfix;
        postfix[indexOfPostfix] = ' ';
        ++indexOfPostfix;
    }
    deleteStack(&head);
}


bool isPassed()
{
    char resultTestOne[200] = { '\0' };
    convertToPostfix(resultTestOne, "(1 + 2 + 3 + 4 + 5) * 2 / 2");
    char resultTestTwo[200] = { '\0' };
    convertToPostfix(resultTestTwo, "2 * 2 + 1 + 3 - (5 + 5)");
    char resultTestThree[200] = { '\0' };
    convertToPostfix(resultTestThree, "5 * 7 + 1 + 2");
    return
        strcmp(resultTestOne, "1 2 + 3 + 4 + 5 + 2 * 2 / ") == 0 &&
        strcmp(resultTestTwo, "2 2 * 1 + 3 + 5 5 + - ") == 0 &&
        strcmp(resultTestThree, "5 7 * 1 + 2 + ") == 0;
}

int main()
{   
    setlocale(LC_ALL, "rus");
    if (!isPassed())
    {   
        printf("Tests failed");
        return -1;
    }
    char infix[200] = { '\0' };
    char postfix[400] = { '\0' };
    printf("¬ведите выражение в инфиксной форме: ");
    scanf("\n%[^\n]", &infix);
    convertToPostfix(postfix, infix);
    printf("\n¬веденное выражение в постфиксной форме: ");
    printf("%s", postfix);
}