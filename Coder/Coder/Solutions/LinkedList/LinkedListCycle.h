#pragma once
#include "ListNode.h"
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();

private:
	// 12 ms	8.1 MB
	bool hasCycle(ListNode *head) {
		if (!head) return false;
		ListNode *slow = head, *fast = head->next;

		while (slow && fast)
		{
			if (slow == fast)
				return true;
			slow = slow->next;
			fast = fast->next;
			if (fast)
				fast = fast->next;
		}

		return false;
	}

	bool hasCycle2(ListNode *head) {
		ListNode* slow = head, *fast = head;

		while (fast && fast->next) {
			slow = slow->next;
			fast = fast->next->next;

			if (slow == fast) {
				return true;
			}
		}

		return false;
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}