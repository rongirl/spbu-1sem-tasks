#include "..\..\stack\stack\stack.h"
#include <string.h>

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
}

int convertToPostfix(char postfix[], char infix[])
{
    StackElement* head = NULL;
    int indexOfPostfix = 0;
    for (int i = 0; i < 200; i++)
    {
        if (infix[i] != '\0' && infix[i] != ' ' && infix[i] != '\n')
        {
            if (infix[i] - '0' >= 0 && infix[i] - '0' <= 9)
            {
                postfix[indexOfPostfix] = infix[i];
                ++indexOfPostfix;
            }
            else switch (infix[i])
            {
                case '+':
                case '-':
                case '*':
                case '/':
                {
                    while (true && !isEmpty(head))
                    {   
                        char operatorInStack = pop(&head);
                        if (priority(infix[i]) >= priority(operatorInStack))
                        {
                            postfix[indexOfPostfix] = operatorInStack;
                            ++indexOfPostfix;
                        }
                        else
                        {
                            push(&head, operatorInStack);
                            break;
                        }
                    }
                    push(&head, infix[i]);
                }
                case '(':
                {
                    push(&head, infix[i]);
                }
                case ')':
                {
                    char operatorInStack = pop(&head);
                    while (operatorInStack != '(')
                    { 
                        postfix[indexOfPostfix] = operatorInStack;
                        ++indexOfPostfix;
                        operatorInStack = pop(&head);
                    }
                    break;
                }
            }

        }
    }
}

int main()
{

}