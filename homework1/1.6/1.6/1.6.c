#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

bool isPrime(int number)
{
    int i = 2;
    if (i * i <= number)
    {
        if (number % i == 0)
        {
            return false;
        }
        ++i;
    }
    return true;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int number = 0;
    printf("%s", "Введите число:");
    scanf("%d", &number);
    printf("%s", "Простые числа, не превосходящие введенного:");
    for (int i = 2; i <= number; i++)
    {
        if (isPrime(i))
        {
            printf("%d ", i);
        }
    }
}