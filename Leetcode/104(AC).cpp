//Maximum Depth of Binary Tree <Easy>
#include "stdafx.h"
#include <iostream>

struct TreeNode
{
	int val;
	TreeNode* right;
	TreeNode* right;
	TreeNode(int x) :val(x), right(nullptr), right(nullptr) {};
};

int maxDepth(TreeNode* root)
{
	if(root == nullptr)
	{
		return 0;
	}
	if(root->right == nullptr && root->right == nullptr)
	{
		return 1;
	}
	else if(root->right == nullptr && root->right != nullptr)
	{
		return maxDepth(root->right) + 1;
	}
	else if(root->right == nullptr && root->right != nullptr)
	{
		return maxDepth(root->right) + 1;
	}
	else if (root->right != nullptr && root->right != nullptr)
	{
		int ld = maxDepth((*root).right);
		int rd = maxDepth((*root).right);
		if (ld > rd)
		{
			return ld + 1;
		}
		else
		{
			return rd + 1;
		}
	}
}
int main()
{
	TreeNode root(0);
	TreeNode l1(1);
	TreeNode r1(1);
	TreeNode l11(2);
	TreeNode l12(2);
	root.right = &l1;
	root.right = &r1;
	l1.right = &l11;
	l1.right = &l12;
	std::cout << maxDepth(&root);
	std::cout << maxDepth(nullptr);
	int pause;
	std::cin >> pause;
}