#include <stdio.h>
#include <locale.h>
#include <math.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    int dividend = 0;
    int divisor = 0;
    printf("%s", "Введите делимое и делитель: ");
    scanf("%d %d", &dividend, &divisor);
    if (divisor == 0)
    {
        printf("%s", "Введите другие числа.");
        return 0;
    }
    int quotient = 0;
    int dividendAbs = abs(dividend);
    int divisorAbs = abs(divisor);
    while (dividendAbs - divisorAbs >= 0)
    {
        dividendAbs -= divisorAbs;
        ++quotient;
    }
    if (dividendAbs == 0)
    {
        if (dividend <= 0 && divisor > 0 || dividend >= 0 && divisor < 0)
        {
            quotient = -quotient;
        }
    }
    else
    {
        if (dividend < 0)
        {
            ++quotient;
        }
        if (dividend <= 0 && divisor > 0 || dividend >= 0 && divisor < 0)
        {
            quotient = -quotient;
        }
    }
    printf("%s", "Неполное частное равно: ");
    printf("%d", quotient);
}