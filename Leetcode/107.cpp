//Binary Tree Level Order Traversal II	<Easy>
//Not using queue
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {};
};

vector<vector<int>> levelOrder(TreeNode* root)
{
	if (root == NULL) return{};
	vector<vector<int>> res;
	res.push_back({ root->val });
	int depth = 0;
	vector<vector<TreeNode*>> tree;
	tree.push_back({ root });
	int emptyCount;
	int i;
	while (true)
	{
		tree.push_back({});
		emptyCount = 0;
		for (i = 0; i < tree[depth].size(); i++)
		{
			if (tree[depth][i]->left != NULL)
				tree[depth + 1].push_back(tree[depth][i]->left);
			else
				emptyCount++;
			if (tree[depth][i]->right != NULL)
				tree[depth + 1].push_back(tree[depth][i]->right);
			else
				emptyCount++;
		}
		if (emptyCount == i * 2)
			break;
		depth++;
	}
	for (i = 0; i < tree.size() - 1; i++)
		res.push_back({});
	for (i = 1; i < res.size(); i++)
		for (int j = 0; j < tree[i].size(); j++)
			res[i].push_back(tree[i][j]->val);
	res.pop_back();
	vector<vector<int>> resv;
	for (int j = res.size() - 1; j != -1; j--)
	{
		resv.push_back(res[j]);
	}
	return resv;
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
	root->left = rl;
	root->right = rr;
	rr->left = rrl;
	rr->right = rrr;

	auto temp = levelOrder(root);
	vector<vector<int>> tests_ises = {
		{ 1,2,3,4,5 },
		{ 123,3,4,4 },
		{ 1234,5,2 }
	};
	//	display({});
	//	display(tests_ises);
	display(temp);
	system("pause");
}

int main()
{
	test();
	return 0;
}