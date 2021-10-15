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

void printArray(const int* array, int size)
{  
	for (int i = 0; i < size; i++)
	{
		printf("%d", array[i]);
	}
	printf("\n");
}

bool checkBinary(int* binaryNumber, int* answer, int size)
{
	for (int i = 0; i < size; i++)
	{
		if (binaryNumber[i] != answer[i])
		{
			return false;
		}
	}
	return true;
}

bool testConvertToBinary()
{
	int number999 = 999;
	int binaryNumber999[32] = { 0 };
	for (int i = 22; i <= 26; i++)
	{
		binaryNumber999[i] = 1;
	}
	binaryNumber999[29] = 1;
	binaryNumber999[30] = 1;
	binaryNumber999[31] = 1;
	int binaryNumberOne[32] = { 0 };
	convertToBinary(binaryNumberOne, number999, 32);
	int number189 = -189;
	int binaryNumber189[32] = { 0 };
	for (int i = 0; i <= 23; i++)
	{
		binaryNumber189[i] = 1;
	}
	binaryNumber189[24] = 0;
	binaryNumber189[25] = 1;
	for (int i = 26; i <= 29; i++)
	{
		binaryNumber189[i] = 0;
	}
	binaryNumber189[30] = 1;
	binaryNumber189[31] = 1;
	int binaryNumberTwo[32] = { 0 };
	convertToBinary(binaryNumberTwo, number189, 32);
	return
		checkBinary(binaryNumberOne, binaryNumber999, 32) &&
		checkBinary(binaryNumberTwo, binaryNumber189, 32);
}

bool checkDecimal()
{
	int binaryNumber358[32] = { 0 };
	binaryNumber358[30] = 1;
	binaryNumber358[29] = 1;
	binaryNumber358[26] = 1;
	binaryNumber358[25] = 1;
	binaryNumber358[23] = 1;
	int binaryNumber100[32] = { 0 };
	for (int i = 0; i <= 24; i++)
	{
		binaryNumber100[i] = 1;
	}
	for (int i = 27; i <= 29; i++)
	{
		binaryNumber100[i] = 1;
	}
	return
		convertToDecimal(binaryNumber358, 32) == 358 &&
		convertToDecimal(binaryNumber100, 32) == -100;

}

bool checkSum()
{
	int binaryNumber100[32] = { 0 };
	binaryNumber100[29] = 1;
	binaryNumber100[26] = 1;
	binaryNumber100[25] = 1;
	int binaryNumber17[32] = { 0 };
	binaryNumber17[31] = 1;
	binaryNumber17[27] = 1;
	int binaryNumber117[32] = { 0 };
	sumTwoBinaryNumbers(binaryNumber100, binaryNumber17, binaryNumber117, 32);
	int answer117[32] = { 0 };
	answer117[31] = 1;
	answer117[29] = 1;
	answer117[27] = 1;
	answer117[26] = 1;
	answer117[25] = 1;
	return checkBinary(binaryNumber117, answer117, 32);
}

bool test()
{
	return testConvertToBinary() && checkSum() && checkDecimal();
}

int main()
{   
	if (!test())
	{
		printf(":(");
		return 0;
	}
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
	if (binaryOneNumber == NULL)
	{
		printf("Все плохо :(");
		free(binaryOneNumber);
		return -1;
	}
	int* binaryTwoNumber = calloc(size, sizeof(int));
	if (binaryTwoNumber == NULL)
	{
		printf("Все плохо :(");
		free(binaryTwoNumber);
		return -1;
	}
	int* sumBinaryNumbers = calloc(size, sizeof(int));
	if (sumBinaryNumbers == NULL)
	{
		printf("Все плохо :(");
		free(sumBinaryNumbers);
		return -1;
	}
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