//Wildcard Matching		<Hard>
#include "stdafx.h"
#include <iostream>
#include <vector>
//扫描string b中的*

using namespace std;

struct Node
{
	int start;
	int end;
};

bool partMatch(string a, string b, int as, int ae, int bs, int be)
{
	while (as < ae && bs < be)
	{
		if (a[as] == b[bs] || b[bs] == '?')
		{
			as++;
			bs++;
		}
		else
			return false;
	}
	if (a[as] != b[bs])
		return false;
	return true;
}

vector<Node> search(string a, int lena, string b, int bs, int bend)
{
	vector<Node> res;
	Node temp;
	if (bs == bend)
	{
		for (int i = 0; i < lena; i++)
		{
			if (a[i] == b[bs] || b[bs] == '?')
			{
				temp.start = i;
				temp.end = i;
				return {temp};
			}
		}
		return {};
	}
	for (int i = 0; i < lena; i++)
		if (a[i] == b[bs] || b[bs] == '?')
		{
			temp.start = i;
			for (int j = bs; j < bend; j++)
				if (a[j + i - bs] == b[j] || b[j] == '?')
					temp.end = j;
				else
					break;
			if (temp.end == bend - 1)
			{
				temp.end += temp.start;
				res.push_back(temp);
			}
		}
	return res;
}

bool search2(string a, int lena, string b, int bs, int bend)
{
	vector<Node> res;
	Node temp;
	if (bs == bend)
	{
		for (int i = 0; i < lena; i++)
			if (a[i] == b[bs] || b[bs] == '?')
				return true;
		return false;
	}
	for (int i = 0; i < lena; i++)
	{
		if (a[i] == b[bs] || b[bs] == '?')
		{
			temp.start = i;
			for (int j = bs; bend > j; j++)
				if (a[j + i - bs] == b[j] || b[j] == '?')
					temp.end = j;
				else
					break;
			if (temp.end == bend - 1)
			{
				temp.end += temp.start;
				res.push_back(temp);
			}
		}
	}
	if (res.size() == 0)
		return false;
	else
		return true;
}

bool isMatch1(string a, string b)
{
	vector<int> seq;
	int con = 0;
	int i = 0;
	int j = 0;
	int lena = 0;
	int lenb = 0;
	for (int ii = 0; a[ii] != '\0'; ii++)
	{
		lena++;
	}
	for (int ii = 0; b[ii] != '\0'; ii++)
	{
		lenb++;
	}
	while (i < lena && j < lenb)
	{
		if (a[i] == b[j] || b[j] == '?')
		{
			i++;
			j++;
		}
		else if (b[j] == '*')
		{
			j++;
			if (b[j] == '\0')
			{
				return true;
			}
			int temp = i;
			while (a[temp] != '\0')
			{
				if (a[temp] == b[j])
				{
					seq.push_back(temp);
				}
				temp++;
			}
			for (int ii = 0; ii < seq.size(); ii++)
			{
				if (partMatch(a, b, seq[ii], lena, j, lenb))
				{
					con == seq[ii];
				}
			}
			if (con == 0)
			{
				return false;
			}
			else
			{
				i = con;
			}
			if (a[i] == '\0')
			{
				return false;
			}
		}
		else
		{
			return false;
		}
	}
	if (a[i] != b[j])
	{
		return false;
	}
	return true;
}

bool isMatch3(string a, string b)
{
	vector<vector<Node>> res;
	vector<vector<Node>> res2;
	int lena, lenb = 0;
	vector<int> b_seq;
	for (lena = 0; a[lena] != '\0'; lena++)
	{
	}
	for (; b[lenb] != '\0'; lenb++)
	{
		if (b[lenb] == '*')
		{
			b_seq.push_back(lenb);
		}
	}
	if (b_seq.size() == 0)
	{
		if (lena != lenb)
			return false;
		for (int j = 0; j < lena; j++)
		{
			if (a[j] == b[j] || b[j] == '?')
			{
			}
			else
			{
				return false;
			}
		}
		return true;
	}
	else
	{
		/*
		{
			if (lenb == 1 && b_seq.size() == 1)
			{
				return true;
			}
			if (b_seq[0] > 0 && b_seq[0] < lenb)
			{
				res.push_back(search(a, lena, b, 0, b_seq[0]));
			}
			for (int i = 1; i < b_seq.size(); i++)
			{
				if (b_seq[i] > 0 && b_seq[i] < lenb)
				{
					res.push_back(search(a, lena, b, b_seq[i - 1] + 1, b_seq[i] - 1));
				}
			}
			for (int i = 0; i < res.size(); i++)
			{
				if (res[i].size() == 0)
				{
					return false;
				}
			}
		}
		*/
		if (b_seq.size() == 1 && lenb == 1)
		{
			return true;
		}
		if (lenb > lena && b_seq.size() == 1)
		{
			return true;
		}
		if (b_seq[0] > 0)
		{
			auto t1 = search2(a, lena, b, 0, b_seq[0] - 1);
			if (t1 == false)
			{
				return false;
			}
		}
		for (int i = 1; i < b_seq.size(); i++)
		{
			if (b_seq[i] > 0 && b_seq[i] < lenb)
			{
				auto temp = search2(a, lena, b, b_seq[i - 1] + 1, b_seq[i] - 1);
				if (temp == false)
				{
					return false;
				}
			}
		}
	}
	return true;
}

bool isMatch4(const char* s, const char* p)
{
	const char* star = NULL;
	const char* ss = s;
	while (*s)
	{
		if (*p == '?' || (*p == *s))
		{
			s++;
			p++;
			continue;
		}
		if (*p == '*')
		{
			star = p;
			p++;
			ss = s;
			continue;
		}
		if (star)
		{
			p = star + 1;
			s = ++ss;
			continue;
		}
		return false;
	}
	while (*p == '*')
		p++;
	return !*p;
}

bool isMatch(string a, string b)
{
	char* i = &a[0];
	char* j = &b[0];
	char* jj = nullptr;
	char* ii = i;
	while (*i != '\0')
	{
		if (*i == *j || *j == '?')
		{
			i++;
			j++;
			continue;
		}
		if (*j == '*')
		{
			ii = i;
			jj = j;
			j++;
			continue;
		}
		if (jj)
		{
			j = jj + 1;
			i = ++ii;
			continue;
		}
		return false;
	}
	while (*j == '*')
		j++;
	return !*j;
}

int test()
{
	cout << "0" << isMatch("aa", "a") << endl;
	cout << "1" << isMatch("aa", "aa") << endl;
	cout << "0" << isMatch("aaa", "aa") << endl;
	cout << "1" << isMatch("aa", "*") << endl;
	cout << "1" << isMatch("aa", "a*") << endl;
	cout << "1" << isMatch("ab", "?*") << endl;
	cout << "0" << isMatch("aab", "c*a*b") << endl;
	cout << "1" << isMatch("abefcdgiescdfimde", "ab*cd?i*de") << endl;
	cout << "1" << isMatch("a", "a*") << endl;
	cout << "1" << isMatch("abefcdggescdfimde", "ab*cd?i*de") << endl;
	return 0;
}

int test3()
{
	auto temp = search("abefcdgiescdfimde", 17, "cd?i", 0, 4);
	for (int i = 0; i < temp.size(); i++)
	{
		cout << temp[i].start << ":" << temp[i].end << endl;
	}
	return 0;
}

int test2()
{
	cout << partMatch("abefcdgiescdfimde", "ab*cd?i*de", 15, 17, 8, 10);
	return 0;
}

int main()
{
	test();
	system("pause");
}

