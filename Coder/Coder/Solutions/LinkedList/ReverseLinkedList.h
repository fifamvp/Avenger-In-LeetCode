#pragma once
#include <stack>
#include "ListNode.h"
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();

private:
	// 8 ms	8.5 MB
	ListNode* reverseList(ListNode* head) {
		if (!head) return nullptr;
		stack<ListNode*> stk;
		while (head)
		{
			stk.push(head);
			head = head->next;
		}
		head = stk.top();
		stk.pop();
		ListNode* p = head;
		while (!stk.empty())
		{
			ListNode* tmp = stk.top();
			stk.pop();
			p->next = tmp;
			p = p->next;
		}
		p->next = nullptr;
		return head;
	}

	// 4 ms	8.3 MB	
	ListNode* reverseList2(ListNode* head) {
		ListNode* pre = nullptr;
		while (head)
		{
			ListNode* tmp = head->next;
			head->next = pre;
			pre = head;
			head = tmp;
		}
		return pre;
	}

	// 8 ms	8.5 MB
	ListNode* reverseList3(ListNode* head) {
		if (!head || !head->next) return head;
		ListNode* p = reverseList3(head->next);
		head->next->next = head;
		head->next = nullptr;
		return p;
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}