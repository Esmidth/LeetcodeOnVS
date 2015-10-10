//Invert Binary Tree	<Easy>
#include "stdafx.h"

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
	
};

TreeNode* invertTree(TreeNode* root) {
	if (root == NULL)
	{
		return root;
	}
	if (!((*root).left == NULL && (*root).right == NULL))
	{
		//return root;
		TreeNode * temp = (*root).left;
		(*root).left = (*root).right;
		(*root).right = temp;
		invertTree((*root).left);
		invertTree((*root).right);
		return root;
	}
	else
		return root;
}