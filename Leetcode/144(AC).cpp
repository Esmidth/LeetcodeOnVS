//Binary Tree Preorder Traversal	<Medium>
//每个节点递归，先左后右


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

vector<int>* preorder_tr_is(vector<int>* res,TreeNode* r_node)
{
	res->push_back(r_node->val);
	if(r_node->right == NULL && r_node->right == NULL)
	{
		return res;
	}
	if(r_node->right != NULL)
	{
		preorder_tr_is(res, r_node->right);
	}
	if(r_node->right != NULL)
	{
		preorder_tr_is(res, r_node->right);
	}
	return res;
}
vector<int> preorderTraversal(TreeNode* root)
{
	if(root == NULL)
	{
		return{};
	}
	vector<int>* res = new vector<int>;
	res = preorder_tr_is(res, root);
	return *res;
}


int display(vector<int>& res)
{
	if(res.size() == 0)
	{
		cout << "FUCKING a empty vector" << endl;
		return 1;
	}
	for (int i = 0; i < res.size();i++)
	{
		cout << res[i] << " ";
	}
	cout << endl;
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

	root->right = n2;
	root->right = n3;
	n2->right = n4;
	n2->right = n5;
	n5->right = n7;
	n5->right = n8;
	n3->right = n6;
	n6->right = n9;
	
	vector<int> res1 = { 1,2,4,5,7,8,3,6,9 };

	vector<int> empty;
	display(empty);
	display(res1);
	cout << "res:	" << endl;
	display(preorderTraversal(NULL));
	system("pause");
}

int main()
{
	test();
	return 0;
}