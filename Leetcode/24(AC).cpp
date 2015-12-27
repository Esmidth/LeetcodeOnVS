// Swap Nodes in Pairs	<Medium>
#include "stdafx.h"
#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode *next;
	ListNode(int x) :val(x), next(nullptr) {};
};

ListNode * swapPairs(ListNode* head)
{
	if (head == nullptr || head->next == nullptr)
		return head;
	ListNode* start = head;
	int temp;
	while(head != nullptr && head->next != nullptr)
	{
		temp = head->val;
		head->val = head->next->val;
		head->next->val = temp;
		head = head->next->next;
	}
	return start;
}

int display(ListNode* root)
{
	if (root == nullptr)
	{
		cout << "FUCKING A EMPTY POINTER\n";
		return 1;
	}
	while(root != nullptr)
	{
		cout << root->val << " ";
		root = root->next;
	}
	cout << endl;
	return 0;
}
int test()
{
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;

	display(n1);
	n1 = swapPairs(n1);
	display(n1);
	
	system("pause");
	return 0;
}
int main()
{
	test();
}