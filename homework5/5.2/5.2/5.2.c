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
    //return isEmpty(head);
    return true;
}

bool isPassed()
{
    char stringTestOne[30] = "([{}])([])";
    char stringTestTwo[30] = "(([[}}))";
    char stringTestThree[30] = "(((]]]";
    char stringTestFour[30] = "[](){}()";
    return
        isCorrectSequence(stringTestOne); //&&
       // !isCorrectSequence(stringTestTwo) &&
      //  !isCorrectSequence(stringTestThree) &&
      //  isCorrectSequence(stringTestFour);
}

int main()
{   
    setlocale(LC_ALL, "rus");
    if (!isPassed())
    {
        printf("Tests failed");
        //return -1;
    }
    char string[200] = { '\0' };
    char stringTestOne[30] = "([{}])([])";
    scanf("%s", &string);
    printf("%d", isCorrectSequence(stringTestOne));
    printf("%d", isCorrectSequence(string));
}