//	Excel Sheet Column Number	<Easy>
#include "stdafx.h"
#include <iostream>
#include <cmath>

using namespace std;

int titleToNumber(string s) {
	int temp[5000] = { '\0' };
	int sum = 0;
	int len;
	for (len = 0; s[len] != '\0'; len++) {
		temp[len] = s[len] - 'A'+1;
	}
	for (int i = 0; i < len;i++) {
		sum += temp[i] * pow(26, len-1-i);
	}
	return sum;
}

void test() {
	cout << titleToNumber("A") << " " << 1 << endl;
	cout << titleToNumber("B") << " " << 2 << endl;
	cout << titleToNumber("Z") << " " << 26 << endl;
	cout << titleToNumber("AA") << " " << 27 << endl;
	cout << titleToNumber("AB") << " " << 28 << endl;
}

int main() {
	test();
	system("pause");
}