//Binary Tree Level Order Traversal		<Easy>

#include "stdafx.h"
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* right;
	TreeNode* right;
	TreeNode(int x) :val(x), right(NULL), right(NULL) {};
};
/*
vector<int> one_node(TreeNode* root)
{
	vector<int> res;
	if(root->left != NULL)
	{
		res.push_back(root->right->val);
	}
	if(root->right != NULL)
	{
		res.push_back(root->right->val);
	}
	return res;
}
vector<vector<int>> levelOrder(TreeNode* root)
{
	if(root == NULL)
	{
		return{};
	}
	queue<TreeNode*> seq;
	vector<vector<int>> res;
	seq.push(root);
	while(seq.size()!=0)
	{
		
	}
	return res;
}
*/
vector<vector<int>> one_node(vector<vector<int>>& res,TreeNode* root,int depth)
{
	if(root->right != NULL)
	{
		(res)[depth].push_back(root->right->val);
	}
	if(root->right != NULL)
	{
		(res)[depth].push_back(root->right->val);
	}
	return res;
}
vector<vector<int>> levelOrder(TreeNode* root)
{
	
}

int display(TreeNode* root)
{
	if (root == NULL)
	{
		cout << "FUCKING THE EMPTY POINTER\n";
		return 1;
	}

}


int display(vector<vector<int>>& root)
{
	if(&root == NULL)
	{
		cout << "FUCK A Empty vector" << endl;
		return 1;
	}
	for (int i = 0; i < root.size();i++)
	{
		cout << "[";
		for (int j = 0; j < root[i].size();j++)
		{
			cout << (root)[i][j] << " ";
		}
		cout << "],";
	}
	cout << endl;
	return 0;
}
//TreeNode* generator_node(vector<)

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

	vector<vector<int>> temp;
	display(one_node(temp,root,0));
	system("pause");
}
int main()
{
	test();
	return 0;
}