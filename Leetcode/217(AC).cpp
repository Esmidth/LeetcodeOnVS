//	Contains Duplicate <Easy>
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(int a,int b) {
	return a < b;
}

bool containDuplicate(vector<int> & nums) {
	if (nums.size() == 0)
		return false;
	sort(nums.begin(), nums.end());
	
	for (int i = 0; i < nums.size()-1;i++) {
		if(nums[i] == nums[i+1]) {
			return true;
		}
	}
	return false;
}

void display(vector<int> a ) {
	for (int i = 0; i < a.size();i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}


void test() {
	vector<int> input = { 1,8,3,1,4,4,9 };
	vector<int> input2 = {};
	cout << containDuplicate(input2) << endl;
}

int main() {
	test();
	system("pause");
}