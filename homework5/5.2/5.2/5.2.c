#include "..\..\stack\stack\stack.h"
#include <stdio.h>
#include <locale.h>
#include <string.h>

bool isCorrectSequence(const char string[])
{
    StackElement* head = NULL;
    int length = strlen(string);
    for (int i = 0; i < length; i++)
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
                    deleteStack(&head);
                    return false;
                }
                else if (string[i] == '}' && pop(&head) != '{')
                {   
                    deleteStack(&head);
                    return false;
                }
                else if (string[i] == ']' && pop(&head) != '[')
                {   
                    deleteStack(&head);
                    return false;
                }
            }
            else
            {   
                deleteStack(&head);
                return false;
            }
        } 
    }
    bool isStackEmpty = isEmpty(head);
    deleteStack(&head);
    return isStackEmpty;
}

bool isPassed()
{
    return
        isCorrectSequence("([{}])([])") &&
        !isCorrectSequence("(([[}}))") &&
        !isCorrectSequence("(((]]]") &&
        isCorrectSequence("[](){}()");
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