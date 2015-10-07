//Roman to Integer <Easy>
/*
I	1
V	5
X	10
L	50
C	100
D	500
M	1000
*/
#include "stdafx.h"
#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

int romanToInt(string s)
{
	int sum = 0;
	/*
	for (int i = 0; i < s.length(); i++)
	{
		switch (s[i])
		{
		case 'I':
			sum++;
			break;
		case 'V':
			sum += 5;
			break;
		case 'X':
			sum += 10;
			break;

		}
	}
	*/
	stack<int> I;
	auto temp = 0;
	for (auto i = 0; i < s.length();i++)
	{
		switch(s[i])
		{
		case 'I':
			I.push(1);
			break;
		case 'V':
			temp = 0;
			while(!I.empty())
			{
				temp = temp + I.top();
				I.pop();
			}
			if(s[i+1] == 'V' || s[i+1] == 'I')
			{
				sum += 5 - temp;
			}
			else
			{
				I.push(5 - temp);
			}
			break;
		case 'X':
			temp = 0;
			while (!I.empty())
			{
				temp = temp + I.top();
				I.pop();
			}
			if (s[i + 1] == 'X' || s[i + 1] == 'V' || s[i + 1] == 'I')
			{
				sum += 10 - temp;
			}
			else
			{
				I.push(10 - temp);
			}
			break;
		case 'L':
			temp = 0;
			while (!I.empty())
			{
				temp = temp + I.top();
				I.pop();
			}

			if (s[i + 1] == 'X' || s[i + 1] == 'V' || s[i + 1] == 'I'|| s[i + 1] == 'L')
			{
				sum += 50 - temp;
			}
			else
			{
				I.push(50 - temp);
			}
			break;
		case 'C':
			temp = 0;
			while (!I.empty())
			{
				temp = temp + I.top();
				I.pop();
			}

			if (s[i + 1] == 'X' || s[i + 1] == 'V' || s[i + 1] == 'I' || s[i + 1] == 'L'|| s[i + 1] == 'C')
			{
				sum += 100 - temp;
			}
			else
			{
				I.push(100 - temp);
			}
			break;
		case 'D':
			temp = 0;
			while (!I.empty())
			{
				temp = temp + I.top();
				I.pop();
			}

			if (s[i + 1] == 'X' || s[i + 1] == 'V' || s[i + 1] == 'I' || s[i + 1] == 'L' || s[i + 1] == 'C'|| s[i + 1] == 'D')
			{
				sum += 500 - temp;
			}
			else
			{
				I.push(500 - temp);
			}
			break;
		case 'M':
			temp = 0;
			while (!I.empty())
			{
				temp = temp + I.top();
				I.pop();
			}

			if (s[i + 1] == 'X' || s[i + 1] == 'V' || s[i + 1] == 'I' || s[i + 1] == 'L' || s[i + 1] == 'C'|| s[i + 1] == 'M'||s[i+1] == 'D')
			{
				sum += 1000 - temp;
			}
			else
			{
				I.push(1000 - temp);
			}
			break;
		}
		
	}
	while(!I.empty())
	{
		sum += I.top();
		I.pop();
	}
	return sum;
}

void testCase()
{
	cout << "I: 1 " << romanToInt("I") << endl;
	cout << "III: 3 " << romanToInt("III") << endl;
	cout << "IV: 4 " << romanToInt("IV") << endl;
	cout << "V: 5 " << romanToInt("V") << endl;
	cout << "VI: 6 " << romanToInt("VI") << endl;
	cout << "X: 10 " << romanToInt("X") << endl;
	cout << "XI: 11 " << romanToInt("XI") << endl;
	cout << "XV: 15 " << romanToInt("XV") << endl;
	cout << "XVI: 16 " << romanToInt("XVI") << endl;
	cout << "IX: 9 " << romanToInt("IX") << endl;
	cout << "IVX: 6 " << romanToInt("IVX") << endl;
	cout << "L: 50 " << romanToInt("L") << endl;
	cout << "LXI: 61 " << romanToInt("LXI") << endl;
	cout << "LIVX: 56 " << romanToInt("LIVX") << endl;
	cout << "C: 100 " << romanToInt("C") << endl;
	cout << "D: 500 " << romanToInt("D") << endl;
	cout << "M: 1000 " << romanToInt("M") << endl;
	cout << "MCMIV: 1904 " << romanToInt("MCMIV") << endl;
	cout << "MDCCCLXXXIV: 1884 " << romanToInt("MDCCCLXXXIV") << endl;
}


int test(vector<string> input,vector<int> result)
{
	if(input.size() != result.size())
	{
		cout << "Error: size don't match";
		return 1;
	}
	for (auto i = 0; i < input.size();i++)
	{
		cout << input[i] << ":\t\t";
		if (romanToInt(input[i]) == result[i])
		{
			cout << "Pass" << endl;
		}
		else
		{
			cout << "Fail" << endl;
		}

	}
	return 0;

}
int main()
{
	int pause;
	//testCase();
	vector<int> result = { 1,3,4,5,6,10,11,15,16,9,6,50,61,56,100,500,1000,1904,1884 ,123};
	vector<string> input = { "I","III","IV","V","VI","X","XI","XV","XVI","IX","IVX","L","LXI","LIVX","C","D","M","MCMIV","MDCCCLXXXIV" ,"C"};
	test(input, result);
	cin >> pause;
}