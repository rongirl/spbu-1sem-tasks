#pragma once

#include <stdbool.h>

// структура очереди с приоритетом
typedef struct QueuePriority QueuePriority;

// создание очереди с приоритетом
QueuePriority* createQueue();

// функция добавляет элемент по ключу, чем большем ключ, тем выше приоритет
void enqueue(QueuePriority* queue, int value, int key);

// функция возвращает значение элемента и удаляет элемент
int dequeue(QueuePriority* queue);

// удаление очереди
void deleteQueue(QueuePriority* queue);

// проверка на пустоту очереди
bool isEmpty(QueuePriority* queue);

// функция возвращает значение верхнего элемента 
int getValueHead(QueuePriority* queue);

// функция возвращает ключ верхнего элемента
int getKeyHead(QueuePriority* queue);