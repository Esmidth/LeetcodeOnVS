// Container With Most Water	<Medium>
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

int maxArea(vector<int> & height)
{
	return 0;
}

void display(vector<int> * input)
{
	if (input == nullptr)
		return;
	for (int i = 0; i < input->size(); i++)
	{
		cout << (*input)[i] << " ";
	}
	cout << endl;
}

void test()
{
	vector<int> o1 = { 1,2,3,4,5 };

}
int main()
{
	test();
	system("pause");
}