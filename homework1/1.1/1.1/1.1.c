#include <stdio.h>
#include <locale.h>

int main()
{
    setlocale(LC_ALL, "Rus");
    int array[20];
    printf("%s", "������� 20 �����:");
    for (int i = 0; i < 20; i++)
    {
        scanf("%d", &array[i]);
    }
    int count = 0;
    for (int i = 0; i < 20; i++)
    {
        if (array[i] == 0)
        {
            count += 1;
        }
    }

    printf("%s %d", "���������� ������� ��������� � �������:", count);
}