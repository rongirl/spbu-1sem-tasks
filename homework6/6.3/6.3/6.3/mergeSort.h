#pragma once

#include "list.h"

// сортировка слиянием, функция удаляет переданный список, 
// возвращает указатель на отсортированный список
List* mergeSort(List* list, int command);