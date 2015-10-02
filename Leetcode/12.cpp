//Integer to Roman <Medium>
// Don't try to make it hard.Just use simply solution.
#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

string intToRoman(int num)
{
	vector<vector<string>> nums = { { "","I","II","III","IV","V","VI","VII","VIII","IX","X"},{ "","X","XX","XXX","XL","L","LX","LXX","LXXX","XC","C"},{ "","C","CC","CCC","CD","D","DC","DCC","DCCC","CM","M"},{"","M","MM","MMM"} };
	string re = "";
	re += nums[3][num / 1000];
	num = num % 1000;
	re += nums[2][num / 100];
	num = num % 100;
	re += nums[1][num / 10];
	num = num % 10;
	re += nums[0][num];
	return re;
}

int main()
{
	
	cout << "1: I\t" << intToRoman(1) << endl;
	cout << "3: III\t" << intToRoman(3) << endl;
	cout << "4: IV\t" << intToRoman(4) << endl;
	cout << "5: V\t" << intToRoman(5) << endl;
	cout << "6: VI\t" << intToRoman(6) << endl;
	cout << "10: X\t" << intToRoman(10) << endl;
	int pause;
	cin >> pause;
}