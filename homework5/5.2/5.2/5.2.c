#include "..\..\stack\stack\stack.h"
#include <stdio.h>


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
    return isEmpty(&head);
}

int main()
{
    char string[200] = { '\0' };
    scanf("%s", &string);
    printf("%d", isCorrectSequence(string));
}