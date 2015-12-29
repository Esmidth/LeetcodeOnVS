//	Longest Substring Without Repeating Characters	<Medium>
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;


int lengthOfLongestSubString3(string s)
{
	if (s[0] == '\0')
		return 0;
	else if (s[1] == '\0')
		return 1;
	int len = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		len++;
	}
	vector<char> a;
	int i = 0;
	int j;
	int maxLength = 0;
	while (i < len)
	{
		for (j = 0; j < a.size(); j++)
		{
			if (a[j] == s[i])
				break;
		}
		if (j < a.size())
		{
			if (a.size() > maxLength)
				maxLength = a.size();
			a.clear();
			a.push_back(s[i]);
		}
		else
			a.push_back(s[i]);
		i++;
	}
	return a.size() > maxLength ? a.size() : maxLength;
}

int lengthOfLongestSubString2(string s)
{
	return 0;
	if (s[0] == '\0')
		return 0;
	else if (s[1] == '\0')
		return 1;
	int len = 0;
	for (int i = 0; s[i] != '\0'; i++)
	{
		len++;
	}
	vector<char> a;
	int j;
	for (int i = 0; i < len; i++)
	{
		for (j = 0; j < a.size(); j++)
			if (s[i] == a[j])
				break;
		if(j < a.size())
		{
			
		}
	}

}


int lengthOfLongestSubString(string s)
{
	if (s[0] == '\0')
		return 0;
	else if (s[1] == '\0')
		return 1;
	int len = 0;
	for (int i = 0; s[i] != '\0';i++)
		len++;
	int start = 0;
	int end = 1;
	int i = 1;
	int j;
	int max = 0;
	while (i < len)
	{
		for (j = start; j < end; j++)
		{
			if (s[j] == s[i])
				break;
		}
		if (j != end)
		{
			if (max < end - start)
				max = end - start;
			start = j + 1;
		}
		i++;
		end++;
	}

	return max > end - start ? max : end - start;
}

int test()
{
	string a = "abcabc";
	string b = "bbbbb";
	string c = "abcabcabc";
	string d = "au";
	string e = "aab";
	string f = "cdd";
	string g = "pwwkew";
	string h = "vdxdf";

	cout << 3<<lengthOfLongestSubString(a) << endl;
	cout << 1<<lengthOfLongestSubString(b) << endl;
	cout << 3<<lengthOfLongestSubString(c) << endl;
	cout << 2<<lengthOfLongestSubString(d) << endl;
	cout << 2 << lengthOfLongestSubString(e) << endl;
	cout << 2 << lengthOfLongestSubString(f) << endl;
	cout << 3 << lengthOfLongestSubString(g) << endl;
	cout << 3 << lengthOfLongestSubString(h) << endl;
	system("pause");
	return 0;
}

int main()
{
	test();
}

