//Ugly Number II <Medium>
#include "stdafx.h"
#include <vector>
#include <algorithm>
using namespace std;

int nthUglyNumber(int n) {
	std::vector<int> nums(n, 1);
	int pos2 = 0, pos3 = 0, pos5 = 0;
	for (int i = 1; i < n; ++i) {
		nums[i] = min(min(nums[pos2] * 2, nums[pos3] * 3), nums[pos5] * 5);
		if (nums[i] == nums[pos2] * 2) {
			++pos2;
		}
		if (nums[i] == nums[pos3] * 3) {
			++pos3;
		}
		if (nums[i] == nums[pos5] * 5) {
			++pos5;
		}
	}
	return nums[n - 1];

}