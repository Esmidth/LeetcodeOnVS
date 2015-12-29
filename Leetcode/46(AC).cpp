// Permutations	<Medium>
#include "stdafx.h"
#include <iostream>
#include <vector>
using namespace std;

void permu(vector<int>& num, vector<int>& mediRes, vector<vector<int>>& ret)
{
	int N = num.size();
	if (N == 1)
	{
		mediRes.push_back(num[0]);
		ret.push_back(mediRes);
		mediRes.pop_back();
		return;
	}

	for (int i = 0; i < N; i++)
	{
		mediRes.push_back(num[i]);
		vector<int> cur = num;
		cur.erase(cur.begin() + i);
		permu(cur, mediRes, ret);
		mediRes.pop_back();//注意：别忘记了这里需要弹出，不要等到循环结束  
	}
}

vector<vector<int>> permute(vector<int>& num)
{
	vector<int> mediRes;
	vector<vector<int>> res;
	permu(num, mediRes, res);
	return res;
}

int display(vector<vector<int>>* a)
{
	if (a == nullptr || (*a).size() == 0)
	{
		cout << "FUCK a empty vector\n";
		return 1;
	}
	for (int i = 0; i < (*a).size(); i++)
	{
		cout << "[";
		for (int j = 0; j < (*a)[i].size(); j++)
		{
			cout << (*a)[i][j] << " ";
		}
		cout << "]\n";
	}
	return 0;
}

int display1(vector<int>* a)
{
	if (a == nullptr)
	{
		cout << "FUCK a empty vector\n";
		return 1;
	}
	cout << "[";
	for (int i = 0; i < a->size(); i++)
	{
		cout << (*a)[i] << " ";
	}
	cout << "]\n";
	return 0;
}

void test()
{
	vector<vector<int>> out = {{1,2,3},{1,3,2},{2,1,3},{2,3,1},{3,1,2},{3,2,1}};
	vector<int> input = {1,2,3};
	vector<int> a = {};
	auto out2 = permute(input);
	display(&out2);
}

int main()
{
	test();
	system("pause");
}

