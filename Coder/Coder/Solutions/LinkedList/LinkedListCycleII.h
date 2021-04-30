#pragma once
#include "ListNode.h"
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();

private:
	// 4 ms	7.5 MB
	ListNode *detectCycle(ListNode *head) {
		ListNode *slow = head, *fast = head;
		ListNode *meetingNode = nullptr;
		while (fast && fast->next)
		{
			slow = slow->next;
			fast = fast->next->next;
			if (slow == fast) {
				meetingNode = slow;
				break;
			}
		}

		if (!meetingNode) return nullptr;

		slow = head;
		while (slow != fast)
		{
			slow = slow->next;
			fast = fast->next;
		}

		return slow;
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}