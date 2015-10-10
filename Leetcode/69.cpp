//Sqrt(x)	<Medium>
#include "stdafx.h"
#include <iostream>
#include <cmath>
#include <time.h>
int mySqrt(int x)
{
	float xhalf = 0.5f * x;
	int i = *(int*)&x;
	i = 0x5f3759df - (i >> 1);
	x = *(float*)&i;
	x = x*(1.5f - xhalf*x*x);
	return (int)x;
}
int InvSqrt(int temp)
{
	float x = temp;
	float xhalf = 0.5f*x;
	int i = *(int*)&x;
	i = 0x5f375a86 - (i >> 1);
	x = *(float*)&i;
	x = x*(1.5f - xhalf*x*x);
	return 1/x;
}
int mySqrt2(int x_i) //TLE
{
	int i = 1;
	while(true)
	{
		if(pow(i,2)<= x_i && pow(i+1,2)>x_i)
		{
			break;
		}
		i++;
	}
	return i;
}
int main()
{
	time_t start_t, end_t;
	int x = 2165136135156;
	start_t = clock();
	using namespace std;
	cout << (int)sqrt(x) << endl;
	end_t = clock();
	cout << end_t - start_t << endl;
	start_t = clock();
	cout << mySqrt2(x) << endl;
	end_t = clock();
	cout << end_t - start_t << endl;
	int pause;
	cin >> pause;
}