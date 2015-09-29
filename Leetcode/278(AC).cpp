//First Bad Version
//¶ş·Ö²éÕÒ
#include "stdafx.h"
#include <iostream>
#include <time.h>
bool isBadVersion(long long version)
{
	if(version <= 1702766718)
	{
		return false;
	}
	return true;
}

int first_bad_i(int n)
{
	int low = 1, high = n;
	while(low < high)
	{
		int mid = low + (high - low) / 2;
		if(isBadVersion(mid))
		{
			high = mid;
		}
		else
		{
			low = mid + 1;
		}
	}
	return low;
}
int firstBadVersion(int n)
{
	long long init = n / 2;
	for (int i = 0; i < 25;i++){
		if (isBadVersion(init - 1) == false && isBadVersion(init) == true)
		{
			break;
		}
		if (isBadVersion(init) == true)
		{
			init /= 2;
		}
		if(isBadVersion(init) == false)
		{
			init = init * 3 / 2;
		}
	}
	if (isBadVersion(init) == true)
	{
		while (isBadVersion(init) == true)
		{
			init--;
		}
		init++;
	}
	else if(isBadVersion(init) == false)
	{
		while(isBadVersion(init) == false)
		{
			init++;
		}

	}
	return init;
}
int main()
{
	using namespace std;
	time_t star_t, end_t;
	star_t = clock();
	cout << firstBadVersion(2126753390) << endl;
	end_t = clock();
	cout << end_t - star_t << endl;
	star_t = clock();
	cout << first_bad_i(2126753390) << endl;
	end_t = clock();
	cout << end_t - star_t;
	int t;
	cin >> t;
}