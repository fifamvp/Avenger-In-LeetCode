#pragma once
#include <stdint.h>
#include "ListNode.h"
using namespace std;
#define S3 1
class Solution
{
public:
	Solution();
	~Solution();

private:
#if S1
	// 44 ms	14.5 MB
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		int lenA = 0, lenB = 0;
		ListNode *pA = headA;
		while (pA)
		{
			lenA++;
			pA = pA->next;
		}
		ListNode *pB = headB;
		while (pB)
		{
			lenB++;
			pB = pB->next;
		}
		int dist = lenA - lenB;
		pA = headA;
		pB = headB;
		if (dist > 0)
		{
			for (int i = 0; i < dist; i++)
			{
				pA = pA->next;
			}
		}
		else
		{
			for (int i = 0; i < -dist; i++)
			{
				pB = pB->next;
			}
		}

		while (pA && pB)
		{
			if (pA == pB)
				return pA;
			pA = pA->next;
			pB = pB->next;
		}
		return nullptr;
	}
#elif S2
	// 44 ms	14.4 MB
	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		if (!headA || !headB) return nullptr;
		ListNode *pA = headA, *pB = headB;
		while (pA != pB)
		{
			pA = pA ? pA->next : headB;
			pB = pB ? pB->next : headA;
		}
		return pA;
	}
#elif S3
	// 36 ms	14.4 MB
	uintptr_t acc = 0;
	ListNode *reverse(ListNode *head){
		ListNode *pre = nullptr;
		while (head)
		{
			acc ^= reinterpret_cast<uintptr_t>(head);
			ListNode *tmp = head->next;
			head->next = pre;
			pre = head;
			head = tmp;
		}
		return pre;
	}

	ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
		ListNode *a = headA, *b = headB;
		a = reverse(a);
		b = reverse(b);
		a = reverse(a);
		if (a != headB)
			b = reverse(b);
		return reinterpret_cast<ListNode*>(acc);
	}

#endif
};

Solution::Solution()
{
}

Solution::~Solution()
{
}