//Remove Duplicates from Sorted List	<Easy>
#include "stdafx.h"
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct ListNode {
	int val;
	ListNode* next;

	ListNode(int x) : val(x), next(NULL) {
	};
};

ListNode* deleteDuplicates(ListNode* head) {
	if (head == nullptr)
		return nullptr;
	else if (head->next == nullptr)
		return head;
	auto start = head;
	vector<int> res;
	while (head != nullptr) {
		res.push_back(head->val);
		head = head->next;
	}
	head = start;
	sort(res.begin(), res.end());
	for (int i = 0; i < res.size() - 1;i++) {
		if (res[i] == res[i + 1]) {
			res[i] = -9999;
		}
		
	}
	for (int i = 0; i < res.size();i++) {
		if (res[i] != -9999) {
			head->val = res[i];
			if (i != res.size() - 1)
				head = head->next;
		}
	}
	head->next = nullptr;
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
	ListNode* n1 = new ListNode(1);
	ListNode* n2 = new ListNode(1);
	ListNode* n3 = new ListNode(2);
	ListNode* n4 = new ListNode(3);
	ListNode* n5 = new ListNode(3);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	display(n1);
	display(deleteDuplicates(n1));
}

int main() {
	test();
	system("pause");
}

