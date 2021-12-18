#include "lexicalAnalyzer.h"
#include "test.h"
#include <stdio.h>
#include <locale.h>

int main()
{   
    setlocale(LC_ALL, "rus");
    if (!areTestsPassed())
    {
        printf(":(");
        return -1;
    }
    char string[50] = { '\0' };
    printf("������� ������: ");
    scanf("%s", &string);
    if (lexicalAnalyzer(string))
    {
        printf("������ �������� ������������ ������.");
        return 0;
    }
    printf("������ �� �������� ������������ ������.");
}
