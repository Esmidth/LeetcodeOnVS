//Valid Anagram		<Easy>
#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>

using namespace std;

bool isAnagram(string a,string b)
{
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	return a == b;
}

int main()
{
	string a = "rat";
	string b = "car";
	string c = "anagram";
	string d = "nagaram";

	cout << isAnagram(c, d);
	cin >> a;
}