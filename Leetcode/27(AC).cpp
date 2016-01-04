//	Remove Element	<Easy>
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val)
{
	vector<int> temp;
	for (auto a : nums)
		if (a != val)
			temp.push_back(a);
	for (int i = 0; i != temp.size(); i++)
		nums[i] = temp[i];
	return temp.size();

}

void display(vector<int>* nums)
{
	if (nums == NULL)
		return;
	else
	{
		for (int i = 0; i < nums->size();i++)
		{
			cout << (*nums)[i] << " ";
		}
		cout << "\nlength: " << nums->size() << endl;
	}
}
void test()
{
	vector<int> ori = { 1,2,3,4,5,5,6,7,8,8,9 };
	vector<int> o2 = { 4,5 };
	display(&ori);
	cout << removeElement(ori, 8);
	cout << endl;
	display(&o2);
	cout << removeElement(o2, 4);
	cout << endl;
	display(&o2);

}
int main()
{
	test();
	system("pause");
}
