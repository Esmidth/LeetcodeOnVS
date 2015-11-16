//Remove Nth Node From End of List <Easy>
#include "stdafx.h"

#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;

	explicit ListNode(int x) :val(x), next(nullptr) {};
};


ListNode* removeNthFromEnd(ListNode* head,int n)
{
	if(head->next == NULL && n == 1)
	{
		return NULL;
	}
	if(n == 0)
	{
		return head;
	}
	ListNode* start = head;
	int len = 0;
	while(head->next != NULL)
	{
		len++;
		head = head->next;
	}
	len++;
	int pos = 1;
	len = len - n + 1;
	if(pos == len)
	{
		return start->next;
	}
	head = start;
	while(pos != len-1)
	{
		head = head->next;
		pos++;
	}
	head->next = head->next->next;
	return start;
}

void display(ListNode* seq)
{
	if(seq == NULL)
	{
		cout << "[]" << endl;
	}
	else
	{
		while (seq->next != NULL)
		{
			cout << seq->val << "->";
			seq = seq->next;
		}
		cout << seq->val << endl;
	}
}
int main()
{
	ListNode* start = new ListNode(3);
	ListNode* l2 = new ListNode(2);
	ListNode* l3 = new ListNode(3);
	ListNode* l4 = new ListNode(4);
	ListNode* l5 = new ListNode(5);
	start->next = l2;
	l2->next = l3;
	l3->next = l4;
	l4->next = l5;
	ListNode* t21 = new ListNode(1);
	ListNode* t22 = new ListNode(2);
	t21->next = t22;
	display(t21);
	display(removeNthFromEnd(t22, 1));
	//display(start);
	//display(removeNthFromEnd(start, 0));
	//display(removeNthFromEnd(start, 1));
	int pause;
	cin >> pause;
}