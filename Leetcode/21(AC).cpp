//Merge Two Sorted Lists	<Easy>
#include "stdafx.h"
#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode * next;
	ListNode(int x) :val(x), next(NULL) {};
};

ListNode* mergeTwoLists(ListNode* l1,ListNode* l2)
{
	if(l1 == NULL)
	{
		return l2;
	}
	else if(l2 == NULL)
	{
		return l1;
	}
	ListNode* temp;
	ListNode* res;
	if(l1->val > l2->val)
	{
		temp = l2;
		l2 = l2->next;
	}
	else
	{
		temp = l1;
		l1 = l1->next;
	}
	res = temp;
	while(l1 != NULL && l2 != NULL)
	{
		if(l1->val > l2->val)
		{
			temp->next = l2;
			l2 = l2->next;
		}
		else
		{
			temp->next = l1;
			l1 = l1->next;
		}
		temp = temp->next;
	}
	if(l1 == NULL && l2 != NULL)
	{
		temp->next = l2;
	}
	else if(l1 != NULL && l2 == NULL)
	{
		temp->next = l1;
	}
	else
	{
	}
	
	return res;
}

int display(ListNode* list_node)
{
	if(list_node == NULL)
	{
		cout << "FUCK A NULL" << endl;
		return 1;
	}
	cout << list_node->val;
	list_node = list_node->next;
	while(list_node != NULL)
	{
		std::cout <<"-->"<< list_node->val;
		list_node = list_node->next;
	}
	cout << endl;
	return 0;
}
void test()
{
	ListNode* l1 = new ListNode(1);
	ListNode* l2 = new ListNode(3);
	ListNode* l3 = new ListNode(5);
	l1->next = l2;
	l2->next = l3;

	ListNode* r1 = new ListNode(2);
	ListNode* r2 = new ListNode(4);
	ListNode* r3 = new ListNode(6);
	r1->next = r2;
	r2->next = r3;
	display(l1);
	display(r1);
	//display(mergeTwoLists(l1, r1));

	display(NULL);
	display(mergeTwoLists(NULL, r1));
	system("pause");
}

int main()
{
	test();
}