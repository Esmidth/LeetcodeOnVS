//Zigzag conversion		<Easy>
#include "stdafx.h"
#include <iostream>
#include <string>

using namespace std;

string convert(string s,int numRows)
{
	int len = 0;
	for (int i = 0; s[i] != '\0';i++)
	{
		len++;
	}
	if(numRows == 1)
	{
		return s;
	}
	string temp = "";
	//line 0
	for (int j = 0; j < len;j += 2*numRows-2)
	{
		temp += s[j];
	}
	//line k
	int i;
	for (int k = 1; k < numRows-1;k++)
	{
		i = 0;
		for (int j = k; j < len;)
		{
			temp += s[j];
			if (i == 0)
			{
				j += 2 * (numRows - k -1);
				i = 1;
			}
			else
			{
				j += 2 * k;
				i = 0;
			}
		}
	}
	//line n-1
	for (int j = numRows-1; j < len;j += 2*numRows-2)
	{
		temp += s[j];
	}
	return temp;
}

void test()
{
	cout << ("PAHNAPLSIIGYIR" == convert("PAYPALISHIRING", 3)) << endl;
	cout << ("A" == convert("A", 1));
	system("pause");
}

int main()
{
	test();
}