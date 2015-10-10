//Minimum Size Subarray Sum		<Medium>
#include "stdafx.h"
#include <vector>

using namespace std;

int minSubArrayLen(int s, std::vector<int>& nums) {
	if (nums.size() == 0)
	{
		return 0;
	}
	int min = 10000000;
	for (int i = 0; i < nums.size(); i++)
	{
		int sum = 0;
		int length = 0;
		for (int j = i; sum < s && j < nums.size(); j++)
		{
			sum += nums[j];
			length++;
		}
		if (sum < s)
		{
			length = 0;
		}
		if (length < min && length != 0) {
			min = length;
		}
		if (i == 0 && length == 0)
		{
			return 0;
		}
	}
	return min;

}