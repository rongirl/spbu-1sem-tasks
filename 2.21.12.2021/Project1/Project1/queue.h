#pragma once

#include <stdbool.h>

// ��������� ������� � �����������
typedef struct QueuePriority QueuePriority;

// �������� ������� � �����������
QueuePriority* createQueue();

// ������� ��������� ������� �� �����, ��� ������� ����, ��� ���� ���������
void enqueue(QueuePriority* queue, int value, int key);

// ������� ���������� �������� �������� � ������� �������
int dequeue(QueuePriority* queue);

// �������� �������
void deleteQueue(QueuePriority* queue);

// �������� �� ������� �������
bool isEmpty(QueuePriority* queue);

// ������� ���������� �������� �������� �������� 
int getValueHead(QueuePriority* queue);

// ������� ���������� ���� �������� ��������
int getKeyHead(QueuePriority* queue);