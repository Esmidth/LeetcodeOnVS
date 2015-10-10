//Remove Linked List Elements	<Easy>
#include "stdafx.h"

struct ListNode
{
	int val;
	struct ListNode* next;
};

struct ListNode* removeElements(struct ListNode* head, int val) {
	if (head == NULL) return NULL;
	struct ListNode* tails = removeElements(head->next, val);
	if (head->val == val)
	{
		head = tails;
	}
	else
	{
		head->next = tails;
	}
	return head;
}