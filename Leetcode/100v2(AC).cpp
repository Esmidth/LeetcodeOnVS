//Same Tree		<Easy>
//V2

#include "stdafx.h"
#include <vector>
#include <iostream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(NULL), right(NULL) {};
};

bool isSame(TreeNode* p,TreeNode* q)
{
	if(p == NULL && q == NULL)
	{
		return true;
	}
	if((p == NULL && q != NULL)||(p != NULL && q == NULL))
	{
		return false;
	}
	if(p->val != q->val)
	{
		return false;
	}
	if(p->left != NULL && q->left != NULL)
	{
		if(p->left->val != q->left->val)
		{
			return false;
		}
	}
	if(p->right != NULL && q->right != NULL)
	{
		if (p->right->val != q->right->val)
		{
			return false;
		}
	}
	return true;
}
bool isSameTree(TreeNode* p,TreeNode* q)
{
	if(p == NULL && q == NULL)
	{
		return true;
	}
	if((p == NULL && q != NULL) || (p != NULL && q == NULL))
	{
		return false;
	}
	if(isSame(p,q))
	{
		if (isSameTree(p->left, q->left) == true && isSameTree(p->right, q->right) == true)
			return true;
	}
	return false;
	
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

	TreeNode* l1 = new TreeNode(1);
	TreeNode* r1 = new TreeNode(1);
	TreeNode* l2 = new	TreeNode(2);
	TreeNode* r2 = new TreeNode(2);
	TreeNode* l3 = new TreeNode(3);
	TreeNode* r3 = new	TreeNode(3);

	//l1->left = l2;
	l1->right = l3;
	//r1->left = r2;
	r1->right = r3;

	//display(levelOrder(root));
	//cout << isSameTree(NULL, NULL);
	cout << isSameTree(l1, r1);
	system("pause");
}

int main()
{
	test();
}