//Same Tree		<Easy>
//Use #102's method to compare
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
			if(tree[depth][i] == NULL)
			{ }
			else
			{
				if (tree[depth][i]->left != NULL)
					tree[depth + 1].push_back(tree[depth][i]->left);
				else
				{
					tree[depth + 1].push_back(NULL);
					emptyCount++;
				}
				if (tree[depth][i]->right != NULL)
					tree[depth + 1].push_back(tree[depth][i]->right);
				else
				{
					tree[depth + 1].push_back(NULL);
					emptyCount++;
				}
			}
		}
		if (emptyCount == i * 2)
			break;
		depth++;
	}
	for (i = 0; i < tree.size() - 1; i++)
		res.push_back({});
	for (i = 1; i < res.size(); i++)
		for (int j = 0; j < tree[i].size(); j++)
		{
			if(tree[i][j] == NULL)
			{
				res[i].push_back(65532);
			}
			else
			{
				res[i].push_back(tree[i][j]->val);
			}
		}
	res.pop_back();
	return res;
}


bool isSameTree(TreeNode* p,TreeNode* q)
{
	vector<vector<int>> res1 = levelOrder(p);
	vector<vector<int>> res2 = levelOrder(q);
	return res1 == res2;
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

int test()
{
	TreeNode* root = new TreeNode(1);
	TreeNode* n2 = new TreeNode(2);
	TreeNode* n3 = new TreeNode(3);
	TreeNode* n4 = new TreeNode(4);
	TreeNode* n5 = new TreeNode(5);
	TreeNode* n6 = new TreeNode(6);
	TreeNode* n7 = new TreeNode(7);
	TreeNode* n8 = new TreeNode(8);
	TreeNode* n9 = new TreeNode(9);

	root->left = n2;
	root->right = n3;
	n2->left = n4;
	n2->right = n5;
	n5->left = n7;
	n5->right = n8;
	n3->right = n6;
	n6->left = n9;

	vector<int> res1 = { 4,7,8,5,2,9,6,3,1 };

	vector<int> empty;
	//display(levelOrder(root));
	cout << isSameTree(NULL, NULL);
	system("pause");
}

int main()
{
	test();
}