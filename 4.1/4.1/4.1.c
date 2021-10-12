#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <locale.h>

void convertToBinary(int* binaryNumber, int number, int size)
{
	int bit = 1;
	for (int i = size - 1; i >= 0; i--)
	{
		binaryNumber[i] = (number & bit) ? 1 : 0;
		bit = bit << 1;
	}
}

int convertToDecimal(int* binaryNumber, int size)
{
	int powerOfTwo = 1;
	int decimalNumber = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		decimalNumber += powerOfTwo * binaryNumber[i];
		powerOfTwo *= 2;
	}
	return decimalNumber;
}

void sumTwoBinaryNumbers(int* binaryOneNumber, int* binaryTwoNumber, int* sumBinaryNumbers, int size)
{
	int remainder = 0;
	for (int i = size - 1; i >= 0; i--)
	{
		sumBinaryNumbers[i] = (binaryOneNumber[i] + binaryTwoNumber[i] + remainder) % 2;
		remainder = (binaryOneNumber[i] + binaryTwoNumber[i] + remainder) / 2;
	}
}

void printArray(int* array, int size)
{  
	for (int i = 0; i < size; i++)
	{
		printf("%d", array[i]);
	}
	printf("\n");
}

int main()
{   
	setlocale(LC_ALL, "rus");
    int size = 32;
	int numberOne = 0;
	int numberTwo = 0;
	printf("Введите первое число: ");
	scanf("%d", &numberOne);
	printf("\n");
	printf("Введите второе число: ");
	scanf("%d", &numberTwo);
	printf("\n");
	int* binaryOneNumber = calloc(size, sizeof(int));
	int* binaryTwoNumber = calloc(size, sizeof(int));
	int* sumBinaryNumbers = calloc(size, sizeof(int));
	printf("Число %d в двоичном представлении в дополнительном коде: ", numberOne);
	convertToBinary(binaryOneNumber, numberOne, size);
	printArray(binaryOneNumber, size);
	printf("Число %d в двоичном представлении в дополнительном коде: ", numberTwo);
	convertToBinary(binaryTwoNumber, numberTwo, size);
	printArray(binaryTwoNumber, size);
	printf("Их сумма в двоичном представлении в дополнительном коде: ");
	sumTwoBinaryNumbers(binaryOneNumber, binaryTwoNumber, sumBinaryNumbers, size);
	printArray(sumBinaryNumbers, size);
	printf("Их сумма в десятичном представлении: ");
	printf("%d", convertToDecimal(sumBinaryNumbers, size));
	free(binaryOneNumber);
	free(binaryTwoNumber);
	free(sumBinaryNumbers);
}