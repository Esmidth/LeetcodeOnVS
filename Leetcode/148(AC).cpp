//Sort List	<Medium>
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
struct ListNode {
	int val;
	ListNode * next;
	ListNode(int x) :val(x), next(NULL) {};
};

ListNode* sortList(ListNode* head) {
	if (head == nullptr)
		return nullptr;
	else if (head->next == nullptr)
		return head;
	vector<int> res;
	ListNode* start = head;
	while(head!=nullptr) {
		res.push_back(head->val);
		head = head->next;
	}
	sort(res.begin(), res.end());
	head = start;
	for (int i = 0; i < res.size(); i++) {
		head->val = res[i];
		head = head->next;
	}
	return start;

}

void display(ListNode* head) {
	if (head == nullptr) {
		cout << "FUCKING A NULL POINTER\n";
		return;
	}
	while (head != nullptr) {
		cout << head->val << " ";
		head = head->next;
	}
	cout << endl;
}

void test() {
	ListNode* n1 = new ListNode(8);
	ListNode* n2 = new ListNode(3);
	ListNode* n3 = new ListNode(2);
	ListNode* n4 = new ListNode(1);
	ListNode* n5 = new ListNode(4);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	display(n1);
	display(sortList(n1));
}

int main() {
	test();
	system("pause");
}
