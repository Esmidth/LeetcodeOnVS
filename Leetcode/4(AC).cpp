//Median of Two Sorted Arrays
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>

using namespace std;

bool cmp(int a,int b)
{
	return a < b;
}
double findMedianSortedArrays2(std::vector<int>& nums1, std::vector<int>& nums2) {
	vector<int> sum;
	for (int i = 0; i < nums1.size();i++)
	{
		sum.push_back(nums1[i]);
	}
	for (int i = 0; i < nums2.size(); i++)
	{
		sum.push_back(nums2[i]);
	}
	sort(sum.begin(), sum.end(), cmp);
	int length = nums1.size() + nums2.size();
	if(length % 2 == 0)
	{
		return static_cast<double>(sum[length / 2] + sum[length / 2 - 1])/2;
	}
	else if(length % 2 != 0)
	{
		return sum[length / 2];
	}

}
double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
	int length = nums1.size() + nums2.size();
	int medpos = length / 2;
	int j = 0, k = 0;
	//return medpos;
	int l = 3;
	for (int i = j+k; i < medpos;i = j+k)
	{
		if(nums1[j]>nums2[k])
		{
			k++;
			l = 1;
		}
		else if(nums1[j] < nums2[k])
		{
			j++;
			l = 0;
		}
		else
		{
			j++;
			k++;
			l = 2;
		}
	}
	if (l == 0)
	{
		return nums1[j];
	}
	else
	{
		return nums2[k];
	}
	
}

int main()
{
	time_t t11,t22;
	//vector<int> t1 = { 1,2,4,5,6,8,88 };//size 7
	//1.2.3.4.5.5.6.6.7.8.8.12.88.99
	//1.2.3.4.5
	//t11 = clock();
	//vector<int> t2 = { 3,5,6,7,8,12,99 };//size 7
	vector<int> t1;
	vector<int> t2 = { 2,3 };
	//t11 = clock();
	//cout << "Median: " << findMedianSortedArrays(t1, t2) << endl;
	//t22 = clock();
	//cout << t22 - t11 << endl;
	t11 = clock();
	cout << findMedianSortedArrays2(t1, t2) << endl;
	t22 = clock();
	cout << t22 - t11 << endl;
	int temp;
	cin >> temp;
	return 0;
}