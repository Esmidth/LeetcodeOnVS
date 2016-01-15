//	Delete Node in a Linked List	<Easy>
#include "stdafx.h"
#include <iostream>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;

	ListNode(int x) : val(x), next(nullptr) {
	}
};

void deleteNode1(ListNode* node) {
	node->val = node->next->val;
	node->next = node->next->next;
}
void deleteNode(ListNode* node) {
	*node = *(node->next);
}

void display(ListNode* root) {
	if (NULL == root)
		return;
	while (root != nullptr) {
		cout << root->val << " ";
		root = root->next;
	}
	cout << endl;
}

void test() {
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	display(n1);
	deleteNode(n2);
	display(n1);
}

int main() {
	test();
	system("pause");
}

