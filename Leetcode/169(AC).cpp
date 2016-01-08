// Majority Element	<Easy>

#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int majorityElement(vector<int>& nums)
{
	if (nums.size() == 0)
	{
		return 0;
	}
	else if (nums.size() == 1)
	{
		return nums[0];
	}
	vector<int> temp_nums;
	vector<int> times;

	int max = 0;
	int pos = 0;
	int j;
	for (int i = 0; i < nums.size(); i++)
	{
		for (j = 0; j < temp_nums.size(); j++)
		{
			if (temp_nums[j] == nums[i])
			{
				break;
			}
		}
		if (j == temp_nums.size())
		{
			temp_nums.push_back(nums[i]);
			times.push_back(1);
		}
		else
			times[j]++;
	}
	for (int i = 0; i < times.size(); i++)
	{
		if (times[i] > max)
		{
			max = times[i];
			pos = i;
		}
	}
	return temp_nums[pos];
}

void display(vector<int>* input)
{
	if (input == nullptr)
	{
		cout << "Fucking Empty Pointer\n";
		return;
	}
	for (int i = 0; i < input->size(); i++)
	{
		cout << (*input)[i] << " ";
	}
	cout << endl;
}

void test()
{
	vector<int> i1 = {1,2,3,4,4,4,4};
	vector<int> empty = {};
	vector<int> single = {1};

	display(&i1);
	display(&empty);
	cout << majorityElement(single);
}

int main()
{
	test();
	system("pause");
}

