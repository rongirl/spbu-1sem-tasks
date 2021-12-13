#pragma once 

// ��������� �������
typedef struct Node Node;

// �������� ������
Node* createTree();

// �������� ������ ����������
void deleteTreeRecursive(Node* root);

// �������� ������ 
void deleteTree(Node** root);

// �������� ����� �������
Node* createNewNode(const char* string, int* index);

// ���������� ��������� � ������
int calculate(Node* root);

// ������ ������
void printTree(Node* root);

// ���������� ������
Node* makeTree(const char* string);
