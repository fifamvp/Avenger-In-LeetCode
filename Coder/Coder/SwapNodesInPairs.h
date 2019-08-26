#pragma once
#include <stdlib.h>
using namespace std;
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
	//0 ms	8.6 MB
	ListNode* swapPairs(ListNode* head) {
		ListNode *r = new ListNode(-1);
		r->next = head;
		ListNode *p = r, *q = r->next, *tmp = NULL;
		while (p != NULL && q != NULL && q->next != NULL)
		{
			tmp = q->next->next;
			q->next->next = p->next;
			p->next = q->next;
			q->next = tmp;
			p = p->next->next;
			q = p->next;
		}

		return r->next;
	}

	//4 ms	8.5 MB
	ListNode* swapPairs2(ListNode* head) {
		ListNode **pp = &head, *a, *b;
		while ((a = *pp) && (b = a->next))
		{
			a->next = b->next;
			b->next = a;
			*pp = b;
			pp = &(a->next);
		}

		return head;
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}