//Candy		<Hard>	
#include "stdafx.h"

int candy(int ratings[], int n) {
	int sum = 0;
	int candies[100000] = { '\0'};
	for (int i = 0; i < n; i++) {
		candies[i] = 1;
	}
	for (int i = 1; i < n; i++) {
		if (ratings[i] > ratings[i - 1]) {
			if (candies[i] > candies[i - 1]) {
				continue;
			}
			else candies[i] = candies[i - 1] + 1;
		}
	}
	for (int i = n - 2; i >= 0; i--) {
		if (ratings[i] > ratings[i + 1]) {
			if (candies[i] > candies[i + 1]) {
				continue;
			}
			else candies[i] = candies[i + 1] + 1;
		}
	}
	for (int i = 0; i < n; i++) {
		//printf("%d ",candies[i]);
		sum += candies[i];
	}
	return sum;
}

int main()
{
	return 0;
}