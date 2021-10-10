#include <stdio.h>
#include <locale.h>
#include <stdbool.h>

long int fibonacciRecursive(long int number)
{
    if (number == 0)
    {
        return 0;
    }
    else if (number == 1)
    {
        return 1;
    }
    else if (number < 0)
    {
        return -1;
    }
    else
    {
        return fibonacciRecursive(number - 2) + fibonacciRecursive(number - 1);
    }
}

long int fibonacciIterative(long int number)
{
    if (number == 1)
    {
        return 1;
    }
    if (number < 0)
    {
        return -1;
    }
    long int firstTemporary = 0;
    long int secondTemporary = 1;
    long int answer = 0;
    for (long int i = 2; i <= number; i++)
    {
        answer = firstTemporary + secondTemporary;
        firstTemporary = secondTemporary;
        secondTemporary = answer;
    }
    return answer;
}

bool test()
{
    return
        fibonacciRecursive(0) == 0 &&
        fibonacciRecursive(13) == 233 &&
        fibonacciRecursive(2) == 1 &&
        fibonacciRecursive(1) == 1 &&
        fibonacciIterative(0) == 0 &&
        fibonacciIterative(13) == 233 &&
        fibonacciIterative(40) == 102334155 &&
        fibonacciIterative(65) == 695895453;
}

int main()
{
    if (!test())
    {
        printf("Tests failed");
        return 0;
    }
    setlocale(LC_ALL, "Rus");
    for (int i = 0; i < 50; i++)
    {
        printf("Индекс элемента: %d\n", i);
        printf("Результат итеративного алгоритма: %lu\n ", fibonacciIterative(i));
        printf("Результат рекурсивного алгоритма: %lu\n ", fibonacciRecursive(i));
        printf("\n\n");
    }
    long int number = 0;
    printf("Введите число: ");
    scanf("%li", &number);
    if (fibonacciIterative(number) == -1)
    {
        printf("Введите другое число.");
        return 0;
    }
    printf("Полученное число в ряду Фибоначчи: ");
    printf("%li", fibonacciIterative(number));
}
