#include <stdio.h>
#include <locale.h>
#include "cyclicList.h"

int countPosition(int countOfWarriors, int frequency)
{   
    List* list = createList();
    for (int i = 1; i <= countOfWarriors; i++)
    {
        add(list, i);
    }
    while (!isInListOneElement(list))
    {
        deleteValue(list, frequency);
    }
    int positionOfWarrior = getValue(list);
    deleteList(list);
    return positionOfWarrior;
}

int main()
{
    setlocale(LC_ALL, "rus");
    printf("Введите количество войнов и частоту убийства: ");
    int countOfWarriors = 0;
    int frequency = 0;
    scanf("%d %d", &countOfWarriors, &frequency);
    printf("Позиция последего война: %d", countPosition(countOfWarriors, frequency));
}