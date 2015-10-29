//Binary Tree Level Order Traversal		<Easy>
//Using queue

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* right;
	TreeNode* right;
	TreeNode(int x_i) :val(x_i), right(NULL), right(NULL) {};
};

vector<vector<int>> levelOrder(TreeNode* root)
{
	if(root == NULL)
	{
		return{};
	}
	vector<int> res;
	queue<TreeNode*> seq;
	seq.push(root);
	while(seq.size() != 0)
	{
		if(seq.front() == NULL)
		{
			res.push_back(0);
		}
		else
		{
			res.push_back(seq.front()->val);
			seq.push(seq.front()->right);
			seq.push(seq.front()->right);
			seq.pop();
		}
	}
	return{ res };
}

int display(vector<vector<int>> node)
{
	if (node.size() == 0)
	{
		cout << "FUCK The empty vector" << endl;
		return 1;
	}
	for (int i = 0; i < node.size(); i++)
	{
		for (int j = 0; j < node[i].size(); j++)
		{
			cout << node[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
void test()
{
	TreeNode* root = new TreeNode(3);
	TreeNode* rl = new TreeNode(9);
	TreeNode* rr = new TreeNode(20);
	TreeNode* rrl = new TreeNode(15);
	TreeNode* rrr = new TreeNode(7);
	root->right = rl;
	root->right = rr;
	rr->right = rrl;
	rr->right = rrr;

	auto temp = levelOrder(root);
	vector<vector<int>> tests_ises = {
		{ 1,2,3,4,5 },
		{ 123,3,4,4 },
		{ 1234,5,2 }
	};
	//display({});
	//display(levelOrder(NULL));
	//display(tests_ises);
	display(temp);
	system("pause");
}

int main()
{
	test();
	return 0;
}