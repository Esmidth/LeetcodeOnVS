// Reverse Linked List	<Easy>
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(NULL) {};
};

ListNode* reverseList(ListNode* head) {
	if (head == nullptr)
		return nullptr;
	else if (head->next == nullptr)
		return head;
	vector<int> temp;
	ListNode* start = head;
	while(head != nullptr) {
		temp.push_back(head->val);
		head = head->next;
	}
	head = start;
	for (int i = temp.size() - 1; i != -1;i--) {
		head->val = temp[i];
		head = head->next;
	}
	return start;
}


void display(ListNode* head) {
	if (head == nullptr) {
		cout << "FUCKING A NULL POINTER\n";
		return;
	}
	while(head != nullptr) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

void test() {
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(2);
	ListNode* n3 = new ListNode(3);
	ListNode* n4 = new ListNode(4);
	ListNode* n5 = new ListNode(5);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;

	display(n1);
	display(reverseList(n1));

}


int main() {
	test();
	system("pause");
}