//Happy Number <Easy>
#include "stdafx.h"
#include <cmath>

int t2s(int in)
{
	int sum = 0;
	int length = 1;
	int temp = in;
	while (temp / 10 != 0)
	{
		temp = temp / 10;
		length++;
	}
	for (int i = 0; i < length; ++i) {
		temp = in % 10;
		in = in / 10;
		sum += pow(temp, 2);
	}
	return sum;
}
bool isHappy(int n)
{
	int ti = 0;
	while (true)
	{
		n = t2s(n);
		if (n == t2s(n))
		{
			if (n == 1)
			{
				return true;
			}
			else
				return false;
		}
		if (ti == 50)
		{
			return false;
		}
		ti++;
	}
}

