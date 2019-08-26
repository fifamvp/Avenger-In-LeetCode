#pragma once
#include <stdlib.h>
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
	//20 ms	9.6 MB
	ListNode* reverseKGroup(ListNode* head, int k) {
		if (k <= 1 || !head)return head;
		ListNode **pp = &head, *s, *e, *tmp;
		while ((s = *pp) != NULL && (e = forwardK(*pp, k)) != NULL)
		{
			tmp = e->next;
			e->next = NULL;
			s = reverseList(s);
			e = forwardK(s, k);
			e->next = tmp;
			*pp = s;
			pp = &(e->next);
		}
		return head;
	}

	ListNode* forwardK(ListNode* end, int k) {
		for (size_t i = 1; i < k && end != NULL; i++)
			end = end->next;
		return end;
	}

	ListNode* reverseList(ListNode* head) {
		if (head == NULL || head->next == NULL)
			return head;
		else
		{
			ListNode* newHead = reverseList(head->next);
			head->next->next = head;
			head->next = NULL;
			return newHead;
		}
	}

	//20 ms	9.8 MB

	//ListNode* reverseKGroup(ListNode* head, int k) {
	//	if (k <= 1 || !head)return head;
	//	ListNode **pp = &head, *s, *e, *tmp;
	//	while ((s = *pp) != NULL && (forwardK(&(e = *pp), k)) != NULL)
	//	{
	//		tmp = e->next;
	//		e->next = NULL;
	//		e = reverseList2(&s);
	//		//e is start, s is end
	//		s->next = tmp;
	//		*pp = e;
	//		pp = &(s->next);
	//	}
	//	return head;
	//}

	//ListNode* forwardK(ListNode** end, int k) {
	//	for (size_t i = 1; i < k && *end != NULL; i++)
	//	{
	//		*end = (*end)->next;
	//	}
	//	return *end;
	//}

	//ListNode* reverseList2(ListNode** head) {
	//	//head becomes the last
	//	if (*head == NULL || (*head)->next == NULL)
	//		return *head;
	//	ListNode* a = (*head), *b = (*head)->next, *c;
	//	while (b)
	//	{
	//		c = b->next;
	//		b->next = a;
	//		a = b;
	//		b = c;
	//	}
	//	(*head)->next = NULL;
	//	return a;
	//}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}