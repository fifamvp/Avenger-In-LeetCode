#pragma once
#include <stdio.h>
using namespace std;
//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class RemoveNthNodeFromEndOfList
{
public:
	RemoveNthNodeFromEndOfList();
	~RemoveNthNodeFromEndOfList();

private:
	ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode *p1 = head, *p2 = head;
		for (int i = 0; i < n; i++)
			p1 = p1->next;
		if (p1 == NULL) 
			return head->next;

		while (p1->next != NULL)
		{
			p1 = p1->next;
			p2 = p2->next;
		}
		//p1 points to the last node, and p2 points to the previous node of what is to be removed

		ListNode *target = p2->next;
		p2->next = target->next;
		target->next = NULL;

		delete(p1);
		delete(p2);
		delete(target);

		return head;
	}
};

RemoveNthNodeFromEndOfList::RemoveNthNodeFromEndOfList()
{
}

RemoveNthNodeFromEndOfList::~RemoveNthNodeFromEndOfList()
{
}