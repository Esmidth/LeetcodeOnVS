// Excel Sheet Column Title	<Easy>
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

int convertToTitle1(int n) {
	n--;
	int temp[5000] = {0};
	int len;
	for (len = 0; n > 0; len++) {
		temp[len] = n % 26;
		n = n / 26;
	}
	string temp1[5000];
	for (int i = 0; i < len; i++) {
		temp1[i] = temp[i] + 'A';
		cout << temp1[i] << " ";
	}
	return 0;
}


string convertToTitle(int n) {
	if (n <= 0) return "";
	if (n <= 26) return string(1, 'A' + n - 1);
	return convertToTitle(n % 26 ? n / 26 : n / 26 - 1) + convertToTitle(n % 26 ? n % 26 : 26);
}
void test() {
	cout << convertToTitle(1) << " A\n";
	cout << convertToTitle(26) << " Z\n";
	cout << convertToTitle(27) << " AA\n";
	cout << convertToTitle(28) << " AB\n";
	cout << convertToTitle(57) << endl;
	cout << convertToTitle(729) << endl;

}

int main() {
	test();
	system("pause");
}

