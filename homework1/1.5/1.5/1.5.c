#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    char sequence[200] = { '\0' };
    printf("%s", "Введите последовательность из скобок: ");
    scanf("%s", &sequence);
    int count = 0;
    int i = 0;
    while (sequence[i] != '\0')
    {
        if (sequence[i] == '(')
        {
            ++count;
        }
        else if (sequence[i] == ')')
        {
            --count;
        }
        if (count < 0)
        {
            break;
        }
        ++i;
    }
    if (count == 0)
    {
        printf("%s", "Правильная последовательность");
    }
    else
    {
        printf("%s", "Неправильная последовательность");
    }
}