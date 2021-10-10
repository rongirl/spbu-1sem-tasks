#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <stdbool.h>

double exponentiationBinary(int number, int power)
{
    if (power == 0)
    {
        return 1;
    }
    else if (power % 2 == 0 && power > 0)
    {
        double temporary = exponentiationBinary(number, power / 2);
        return temporary * temporary;
    }
    else if (power % 2 == 1 && power > 0)
    {
        return exponentiationBinary(number, power - 1) * number;
    }
    else if (power < 0)
    {
        const int powerAbs = abs(power);
        return 1.0 / exponentiationBinary(number, powerAbs);
    }
}

double exponentiation(int number, int power)
{
    double answer = 1.0;
    const int powerAbs = abs(power);
    for (int i = 1; i <= powerAbs; i++)
    {
        answer *= number;
    }
    if (power < 0)
    {
        answer = 1.0 / answer;
    }
    return answer;
}

bool testExponentiation(int number, int power, double answer)
{
    return
        abs(exponentiationBinary(number, power) - answer) < 0.0001 &&
        abs(exponentiation(number, power) - answer) < 0.0001;
}

bool test()
{
    return
        testExponentiation(2, -1, 0.500000) &&
        testExponentiation(3, 4, 81.000000) &&
        testExponentiation(80, 0, 1.000000) &&
        testExponentiation(5, 9, 1953125.000000) &&
        testExponentiation(-5, -5, -0.000320);
}

int main()
{
    setlocale(LC_ALL, "Rus");
    int number = 0;
    int power = 0;
    if (!test())
    {
        printf("Tests failed");
        return 0;
    }
    printf("Введите число и степень, в которую хотите возвести: ");
    scanf("%d %d", &number, &power);
    printf("Полученное число: ");
    printf("%f", exponentiationBinary(number, power));
}