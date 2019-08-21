#pragma once
#include <stdio.h>
struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class Solution
{
public:
	Solution();
	~Solution();

private:
	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		ListNode *r = new ListNode(-1);
		ListNode *p = r;
		while (l1 && l2)
		{
			if (l1->val <= l2->val)
			{
				p->next = l1;
				l1 = l1->next;
			}
			else
			{
				p->next = l2;
				l2 = l2->next;
			}
			p = p->next;
		}
		p->next = l1 ? l1 : l2;

		return r->next;
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}