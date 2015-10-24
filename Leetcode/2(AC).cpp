//Add Two Numbers	<Medium>
#include "stdafx.h"
#include <iostream>

using namespace std;

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x):val(x),next(nullptr){}
};

ListNode* addTwoNumbers(ListNode * l1,ListNode* l2)
{
	if(l1 == nullptr)
	{
		return l2;
	}
	else if(l2 == nullptr)
	{
		return l1;
	}
	ListNode* ori = l1;
	while(true)
	{
		int i = 0;
		// 0 len equals
		// 1 l1 longer
		// 2 l2 longer
		l1->val += l2->val;
		if (l1->next == nullptr || l2->next == nullptr)
		{
			break;
		}
		l1 = l1->next;
		l2 = l2->next;
	}
	//l1->val += l2->val;
	if(l1->next == NULL && l2->next != NULL)
	{
		l1->next = l2->next;
	}
	else if(l1->next == NULL && l2->next == NULL)
	{
	}
	else
	{
	}
	l1 = ori;
	while(l1 != nullptr)
	{
		if(l1->val > 9)
		{
			if(l1->next == NULL)
			{
				l1->next = new ListNode(l1->val / 10);
			}
			else
			{
				l1->next->val += l1->val / 10;
			}
			l1->val = l1->val % 10;
		}
		l1 = l1->next;
	}
	return ori;
}

int display(ListNode * list_node)
{
	if(list_node == NULL)
	{
		cout << "FUCK" << endl;
		return 1;
	}
	int out[1000] = { '\0' };
	int i = 0;
	while(list_node != nullptr)
	{
		out[i] = list_node->val;
		i++;
		list_node = list_node->next;
	}
	for (int j = i-1; j != -1;j--)
	{
		cout << out[j];
	}
	cout << endl;
	return 0;
}

void testout()
{
	ListNode* l1 = new ListNode(2);
	ListNode* l2 = new ListNode(4);
	ListNode* l3 = new ListNode(3);
	l1->next = l2;
	l2->next = l3;
	display(l1);
}
void testAdd()
{
	ListNode* l1 = new ListNode(2);
	ListNode* l2 = new ListNode(4);
	ListNode* l3 = new ListNode(3);
	ListNode* r1 = new ListNode(5);
	ListNode* r2 = new ListNode(6);
	ListNode* r3 = new ListNode(5);
	ListNode* r4 = new ListNode(5);
	l1->next = l2;
	l2->next = l3;
	r1->next = r2;
	r2->next = r3;

	//display(l2);
	display(r4);
	display(r3);
	display(addTwoNumbers(r3, r4));

}
int main()
{
	//testout();
	testAdd();
	system("pause");
}