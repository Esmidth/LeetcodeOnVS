//Maximum Depth of Binary Tree
#include "stdafx.h"
#include <iostream>

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {};
};

int maxDepth(TreeNode* root)
{
	if(root == nullptr)
	{
		return 0;
	}
	if(root->left == nullptr && root->right == nullptr)
	{
		return 1;
	}
	else if(root->left == nullptr && root->right != nullptr)
	{
		return maxDepth(root->right) + 1;
	}
	else if(root->right == nullptr && root->left != nullptr)
	{
		return maxDepth(root->left) + 1;
	}
	else if (root->left != nullptr && root->right != nullptr)
	{
		int ld = maxDepth((*root).left);
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
	root.left = &l1;
	root.right = &r1;
	l1.left = &l11;
	l1.right = &l12;
	std::cout << maxDepth(&root);
	std::cout << maxDepth(nullptr);
	int pause;
	std::cin >> pause;
}