//Binary Tree Postorder Traversal	<Hard>
//先将二叉树的右端入栈，再将二叉树的左端入栈
//以测试用例为例，入栈顺序为1,3,6,9,2,5,8,7,4

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <stack>

using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {};
};

void post_is(TreeNode* root_node, stack<TreeNode*>* rs_stack)
{
	if (root_node->left == nullptr && root_node->right == nullptr)
	{
		rs_stack->push(root_node);
	}
	else
	{
		rs_stack->push(root_node);
		if (root_node->right != nullptr)
		{
			post_is(root_node->right, rs_stack);
		}
		if (root_node->left != nullptr)
		{
			post_is(root_node->left, rs_stack);
		}
	}
}
vector<int> postorderTraversal(TreeNode* root)
{
	if (root == nullptr)
	{
		return{};
	}
	vector<int>* res = new vector<int>;
	stack<TreeNode*>* rs_stack = new stack<TreeNode*>;
	post_is(root, rs_stack);
	while (rs_stack->size() != 0)
	{
		res->push_back(rs_stack->top()->val);
		rs_stack->pop();
	}
	return *res;
}
int display1(vector<int>& res)
{
	if (res.size() == 0)
	{
		cout << "FUCKING a empty vector" << endl;
		return 1;
	}
	for (int i = 0; i < res.size(); i++)
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

	vector<int> res1 = { 4,7,8,5,2,9,6,3,1 };

	vector<int> empty;
	display1(empty);
	display1(res1);
	cout << "res:	" << endl;
	display1(postorderTraversal(root));
	display1(postorderTraversal(nullptr));
	system("pause");
	return 0;
}

int main()
{
	test();
	return 0;
}