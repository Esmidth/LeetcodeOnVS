//Binary Tree Level Order Traversal		<Easy>
//Using queue
//Can't handle the depth problem
#include "stdafx.h"
#include <iostream>
#include <queue>
#include <vector>
#include <cmath>

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
	if (root == NULL)
	{
		return{};
	}
	vector<vector<int>> ress;
	queue<TreeNode*> seq;
	seq.push(root);
	int depth = 0;
	int ti = 0;
	while (seq.size() != 0)
	{

		if (seq.front() == NULL)
		{
			seq.pop();
		}
		else
		{
			if(ress.size() <= depth)
			{
				ress.push_back({ seq.front()->val });
			}
			else
			{
				ress[depth].push_back(seq.front()->val);
			}
			seq.push(seq.front()->right);
			seq.push(seq.front()->right);
			seq.pop();
		}
		ti++;
		if ((int)(pow(2, depth)) == ti)
		{
			depth++;
			ti = 0;
		}
		
	}
	return ress;
}

vector<vector<int>> levelOrder2(TreeNode* root_node)
{
	vector<vector<int>> ress;
	vector<int> res;
	queue<TreeNode*> seq;
	seq.push(root_node);
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
		}
		seq.pop();
	}
	for (int i = 0; i < res.size();i++)
	{
		
	}
	return{ res };
}

int display1(vector<vector<int>> node)
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

	TreeNode* r_node = new TreeNode(1);
	TreeNode* r1 = new TreeNode(2);
	TreeNode* r2 = new TreeNode(3);
	TreeNode* r3 = new TreeNode(4);
	TreeNode* r4 = new TreeNode(5);
	
	r_node->right = r1;
	r1->right = r2;
	r2->right = r3;
	r3->right = r4;
	auto temp = levelOrder(root);
	vector<vector<int>> tests_ises = {
		{ 1,2,3,4,5 },
		{ 123,3,4,4 },
		{ 1234,5,2 }
	};
	//display({});
	display1(levelOrder2(r_node));
	//display(tests_ises);
	//display(temp);
	system("pause");
}

int main()
{
	test();
	return 0;
}