//Power of Two	<Easy>
#include "stdafx.h"

bool isPowerOfTwo(int n) {
	int i;
	while (true)
	{
		if (n == 1)
		{
			return true;
		}
		else if (n == 0)
		{
			return false;
		}
		if (n % 2 == 0)
		{
			n = n / 2;
		}
		else
		{
			return false;
		}
	}
}