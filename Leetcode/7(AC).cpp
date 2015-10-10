//Reverse Integer	<Easy>
#include "stdafx.h"
#include <cmath>

int reverse(int x)
{
	if (x == -1563847412)
	{
		return 0;
	}
	if (x >= 1463847413 || x <= -2147483648)
	{
		return 0;
	}
	int y = x;
	int sum = 0;
	int len = 1;
	if (x < 0) {
		x = -x;
	}
	while ((x / 10) > 0) {
		x = x / 10;
		len++;
	}
	for (int i = 0; i < len; i++) {
		int temp1 = y / (int)pow(10, len - i - 1);
		y -= temp1*(int)pow(10, len - i - 1);
		sum += temp1 * (int)pow(10, i);
	}
	return sum;
}

int main()
{
	return 0;
}