//Basic Calculator II	<Medium>
#include "stdafx.h"
#include <string>

using namespace std;

int cal(int *num, int start, int end) {
	int sum = num[start];
	for (int i = start; i <= end; i++) {
		if (num[i + 1] == 999999 + 42) {
			i += 2;
			sum *= num[i];
			i--;
		}
		else if (num[i + 1] == 999999 + 47) {
			i += 2;
			sum /= num[i];
			i--;
		}
	}
	return sum;
}

int calculate(string s) {
	int num[1000000] = { '\0' };
	int k = 0;
	for (int i = 0; i < s.length(); i++) {
		int temp = 0;
		int j = 0;
		if (s[i] < 65 && s[i] >= 48) {
			while (s[i + j] < 65 && s[i + j] >= 48) {
				j++;
			}
			j--;
			for (int zz = 0; zz < j + 1; zz++) {
				temp += pow(10, j - zz) * (s[i + zz] - 48);
			}
			num[k] = temp;
			k++;
			i += j;
		}
		else if (s[i] == 43) {
			num[k] = 999999 + 43;
			k++;
		}
		else if (s[i] == 45) {
			num[k] = 999999 + 45;
			k++;
		}
		else if (s[i] == 42) {
			num[k] = 999999 + 42;
			k++;
		}
		else if (s[i] == 47) {
			num[k] = 999999 + 47;
			k++;
		}
	}
	if (k == 1) {
		return num[0];
	}
	int i = 0;
	int j = 1;
	while (num[i + j] != 999999 + 43 && num[i + j] != 999999 + 45 && j < k) {
		j += 1;
	}
	j--;
	int sum = cal(num, i, i + j);
	i += j - 1;
	for (; i < k; i++) {
		if (num[i + 1] == 999999 + 43) {
			i += 2;
			j = 1;
			while (num[i + j] != 999999 + 43 && num[i + j] != 999999 + 45 && j < k)
				j++;
			j--;
			sum += cal(num, i, i + j);
			i += j - 1;
		}
		else if (num[i + 1] == 999999 + 45)
		{
			i += 2;
			j = 1;
			while (num[i + j] != 999999 + 43 && num[i + j] != 999999 + 45 && j < k)
			{
				j++;
			}
			j--;
			sum -= cal(num, i, i + j);
			i += j - 1;
		}
	}

	return sum;

}