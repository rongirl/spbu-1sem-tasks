#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    printf("%s", "Введите два числа:");
    int numberOne = 0;
    int numberTwo = 0;
    scanf("%d %d", &numberOne, &numberTwo);
    numberTwo = numberTwo + numberOne;
    numberOne = numberTwo - numberOne;
    numberTwo = numberTwo - numberOne;
    printf("%s", "Выведенные числа: ");
    printf("%d %d", numberOne, numberTwo);
}