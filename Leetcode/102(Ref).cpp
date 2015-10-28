#include "stdafx.h"
#include <vector>
#include <queue>
#include <iostream>
using namespace std;

struct TreeNode
{
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x_i) :val(x_i), left(NULL), right(NULL) {};
};

vector<vector<int> > levelOrder(TreeNode *root) {
	if (!root)   return vector<vector<int> >();
	queue<TreeNode *> que;
	que.push(root);
	int push_num = 1;
	int pop_num = 0;
	vector<vector<int> > result;
	vector<int> temp;
	int last = 1;
	while (!que.empty()) {
		TreeNode *pop_node = que.front();
		temp.push_back(pop_node->val);
		que.pop();
		++pop_num;
		if (pop_node->left) {
			que.push(pop_node->left);
			++push_num;
		}
		if (pop_node->right) {
			que.push(pop_node->right);
			++push_num;
		}
		if (pop_num == last) {
			result.push_back(temp);
			temp.clear();
			last = push_num;
		}
	}
	return result;
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

	TreeNode* r_node = new TreeNode(1);
	TreeNode* r1 = new TreeNode(2);
	TreeNode* r2 = new TreeNode(3);
	TreeNode* r3 = new TreeNode(4);
	TreeNode* r4 = new TreeNode(5);

	r_node->left = r1;
	r1->right = r2;
	r2->right = r3;
	r3->right = r4;
	//auto temp = levelOrder(root);
	vector<vector<int>> tests_ises = {
		{ 1,2,3,4,5 },
		{ 123,3,4,4 },
		{ 1234,5,2 }
	};
	//display({});
	display(levelOrder(r_node));
	//display(tests_ises);
	//display(temp);
	system("pause");
}

int main()
{
	test();
	return 0;
}