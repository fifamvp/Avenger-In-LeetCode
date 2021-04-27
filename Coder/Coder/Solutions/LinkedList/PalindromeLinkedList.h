#pragma once
#include <string>
#include <vector>
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
	// 228 ms	121 MB
	ListNode* cur;

	bool isPalindrome(ListNode* head) {
		cur = head;
		return check(head);
	}

	bool check(ListNode* node) {
		if (!node) return true;
		bool isPal = check(node->next) & (node->val == cur->val);
		cur = cur->next;
		return isPal;
	}
#elif S2
	// 160 ms	110.3 MB
	ListNode* reverse(ListNode* head) {
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

	bool isPalindrome(ListNode* head) {
		int len = 0;
		ListNode* p = head, *q;
		while (p)
		{
			len++;
			p = p->next;
		}
		if (len == 1) return true;
		p = head;
		int half = len / 2;
		while (--half)
		{
			p = p->next;
		}
		ListNode* mid;
		if (len & 1) {
			q = p->next->next;
			mid = p->next;
		}
		else
		{
			q = p->next;
			mid = q;
		}
		p->next = nullptr;
		p = reverse(head);

		bool isPal = true;
		while (p && q)
		{
			if (p->val != q->val) {
				isPal = false;
				break;
			}
			p = p->next;
			q = q->next;
		}
		return isPal;
	}
#elif S2_1
	// 156 ms	110.2 MB
	bool isPalindrome(ListNode* head) {
		ListNode* slow = head, *fast = head, *pre = nullptr;
		while (fast && fast->next)
		{
			ListNode* tmp = slow;
			slow = slow->next;
			fast = fast->next->next;
			tmp->next = pre;
			pre = tmp;
		}
		if (fast)
			slow = slow->next;
		bool isPal = true;
		while (pre && slow)
		{
			if (pre->val != slow->val) {
				isPal = false;
				break;
			}
			slow = slow->next;
			pre = pre->next;
		}
		return isPal;
	}
#elif S3
	// 204 ms	128.2 MB
	bool isPalindrome(ListNode* head) {
		ListNode* p = head;
		vector<int> vals;
		while (p)
		{
			vals.push_back(p->val);
			p = p->next;
		}
		for (int i = 0, j = vals.size() - 1; i < j; i++, j--)
		{
			if (vals[i] != vals[j])
				return false;
		}
		return true;
	}
#endif

	
};

Solution::Solution()
{
}

Solution::~Solution()
{
}