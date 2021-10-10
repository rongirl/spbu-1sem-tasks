#include <stdio.h>
#include <locale.h>
#include <string.h>

int main()
{
    setlocale(LC_ALL, "Rus");

    char stringOne[100] = { '\0' };;
    char stringTwo[100] = { '\0' };

    printf("%s", "Введите строку: ");
    gets(stringOne);

    printf("%s", "Введите подстроку: ");
    gets(stringTwo);

    int answer = 0;
    int sizeStringOne = strlen(stringOne);
    for (int i = 0; i < sizeStringOne; i++)
    {
        if (stringOne[i] == stringTwo[0])
        {
            int j = i;
            int k = 0;
            int count = 1;
            int sizeStringTwo = strlen(stringTwo);
            while (k < sizeStringTwo - 1 && j < sizeStringOne - 1)
            {
                if (stringOne[j + 1] == stringTwo[k + 1])
                {
                    ++count;
                }
                else
                {
                    break;
                }

                ++k;
                ++j;
            }
            if (count == strlen(stringTwo))
            {
                ++answer;
            }
        }
    }
    printf("%s", "Количество вхождений подстроки в строку: ");
    printf("%d", answer);
}