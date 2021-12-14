#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdbool.h>
#include <stdlib.h>

int convertToDecimal(const char* binaryNumber)
{
    int size = strlen(binaryNumber);
    int powerOfTwo = 1;
    int decimalNumber = 0;
    for (int i = size - 1; i >= 0; i--)
    {
        decimalNumber += powerOfTwo * (binaryNumber[i] - '0');
        powerOfTwo *= 2;
    }
    return decimalNumber;
}

bool isPassed(const char* binaryNumber, const char* answer)
{
    char* result[100] = { '\0' };
    _itoa_s(convertToDecimal(binaryNumber), result, 100, 10);
    return strcmp(result, answer) == 0;
}

bool areTestsPassed()
{
    return
        isPassed("10111110011", "1523") &&
        isPassed("1", "1") &&
        isPassed("11011011011110101101", "898989") &&
        isPassed("100", "4") &&
        isPassed("1111111", "127") &&
        isPassed("0", "0");
}

int main()
{
    setlocale(LC_ALL, "rus");
    if (!areTestsPassed())
    {
        printf(":(");
        return -1;
    }
    char binaryNumber[100] = { '\0' };
    printf("Введите число в двоичном представлении: ");
    scanf("%s", &binaryNumber);
    printf("Число в десятичном представлении: ");
    char answer[100] = { '\0' };
    _itoa_s(convertToDecimal(binaryNumber), answer, 100, 10);
    printf("%s", answer);
}