#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    int countSum[28] = { 0 };
    for (int i = 0; i < 10; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            for (int k = 0; k < 10; k++)
            {
                int sum = i + j + k;
                countSum[sum] += 1;
            }
        }
    }
    int countTickets = 0;
    for (int i = 0; i <= 27; i++)
    {
        countTickets += countSum[i] * countSum[i];
    }
    printf("%s", "Количество счастливых билетов: ");
    printf("%d", countTickets);
}