//Wildcard Matching		<Hard>
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
//扫描string b中的*

using namespace std;

bool isMatch2(string a,string b,int as,int ae,int bs,int be)
{
	while (as < ae && bs < be)
	{
		if(a[as]==b[bs] || b[bs] == '?')
		{
			as++;
			bs++;
		}
		else
		{
			return false;
		}
	}
	if (a[as] != b[bs])
	{
		return false;
	}
	return true;
}

bool isMatch(string a,string b)
{
	vector<int> seq;
	int con = 0;
	int i = 0;
	int j = 0;
	int lena = 0;
	int lenb = 0;
	for (int ii = 0; a[ii] != '\0';ii++)
	{
		lena++;
	}
	for (int ii = 0; b[ii] != '\0';ii++)
	{
		lenb++;
	}
	while(i < lena && j < lenb)
	{
		if(a[i] == b[j] || b[j] == '?')
		{
			i++;
			j++;
		}
		else if(b[j]=='*')
		{
			j++;
			if(b[j] =='\0')
			{
				return true;
			}
			int temp = i;
			while(a[temp] != '\0')
			{
				if(a[temp] == b[j])
				{
					seq.push_back(temp);
				}
				temp++;
			}
			for (int ii = 0; ii < seq.size();ii++)
			{
				if(isMatch2(a,b,seq[ii],lena,j,lenb))
				{
					con == seq[ii];
				}
			}
			if(con == 0)
			{
				return false;
			}
			else
			{
				i = con;
			}
			if(a[i] =='\0')
			{
				return false;
			}
		}
		else 
		{
			return false;
		}
	}
	if(a[i] != b[j])
	{
		return false;
	}
	return true;
}
int test()
{
	cout << "0"<<isMatch("aa", "a") << endl;
	cout << "1"<<isMatch("aa", "aa") << endl;
	cout << "0" << isMatch("aaa", "aa") << endl;
	cout << "1" << isMatch("aa", "*") << endl;
	cout << "1" << isMatch("aa", "a*") << endl;
	cout << "1" << isMatch("ab", "?*") << endl;
	cout << "0" << isMatch("aab", "c*a*b") << endl;
	cout << "1" << isMatch("abefcdgiescdfimde",
		"ab*cd?i*de") << endl;
	system("pause");
}
int test2()
{
	cout << isMatch2("abefcdgiescdfimde", "ab*cd?i*de", 15, 17, 8, 10);
	system("pause");
}
int main()
{
	test();
}


