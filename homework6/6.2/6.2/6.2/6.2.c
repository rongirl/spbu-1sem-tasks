#include <stdio.h>
#include <locale.h>
#include "cyclicList.h"
#include "testCyclicList.h"

bool isPassed()
{
    return countPosition(10, 2) == 5 &&
        countPosition(9, 4) == 1 &&
        countPosition(13, 9) == 11 &&
        countPosition(4, 8) == 3;
}

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
    if (!areTestsPassed() || !isPassed())
    {
        printf(":(");
        return -1;
    }
    printf("Введите количество воинов и частоту убийства: ");
    int countOfWarriors = 0;
    int frequency = 0;
    scanf("%d %d", &countOfWarriors, &frequency);
    printf("Позиция последего воина: %d", countPosition(countOfWarriors, frequency));
}