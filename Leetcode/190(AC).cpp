//Reverse Bits	<Easy>

#include "stdafx.h"
#include <stdint.h>

void int2bin(uint32_t n, uint32_t *temp) {
	if (n < 2) {
		*temp = n;
	}
	else {
		*(temp) = n % 2;
		int2bin(n / 2, temp + 1);
	}
};
uint32_t pow(uint32_t a, uint32_t b)
{
	uint32_t sum = 1;
	for (int i = 0; i < b; i++)
	{
		sum = sum * a;
	}
	return sum;
}

uint32_t reverseBits(uint32_t n) {
	uint32_t temp[32] = { 0 };
	int2bin(n, temp);
	n = 0;
	for (int i = 0; i < 32; i++) {
		n += pow(2, i) * temp[31 - i];
	}
	return n;
}
int main()
{
	return 0;
}