#include <stdio.h>
#include <stdlib.h>

void convertToBinary(int* binaryNumber, int number, int size)
{
	int bit = 1;
	for (int i = size - 1; i >= 0; i--)
	{
		binaryNumber[i] = (number & bit) ? 1 : 0;
		bit = bit << 1;
	}
}

int convertToDecimal(int* binaryNumber, int number, int size)
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

int main()
{   
    int size = 32;
	int numberOne = 0;
	int numberTwo = 0;
	printf("¬ведите два числа: ");
	scanf("%d %d", &numberOne, &numberTwo);
	int* binaryOneNumber = calloc(size, sizeof(int));
	int* binaryTwoNumber = calloc(size, sizeof(int));
	int* sumBinaryNumbers = calloc(size, sizeof(int));
	convertToBinary(binaryOneNumber, numberOne, size);
	convertToBinary(binaryTwoNumber, numberTwo, size);
	sumTwoBinaryNumbers(binaryOneNumber, binaryTwoNumber, sumBinaryNumbers, size);
	free(binaryOneNumber);
	free(binaryTwoNumber);
	free(sumBinaryNumbers);
}