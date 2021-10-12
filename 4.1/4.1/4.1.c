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

int main()
{   
    int size = 32;
	int* binaryNumber = calloc(size, sizeof(int));
	
	free(binaryNumber);
}