#pragma once
#include <stdio.h>
#include <vector>
#include <set>
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
	void Solve()
	{
		vector<ListNode*> lists;
		vector<vector<int>> params = { {1, 4, 5}, {1, 3, 4}, {2, 6} };
		for (auto v : params)
		{
			ListNode* r = new ListNode(-1);
			ListNode* p = r;
			for (auto g : v)
			{
				p->next = new ListNode(g);
				p = p->next;
			}
			lists.push_back(r->next);
		}
		mergeKLists(lists);
	}

private:
	//168 ms	10.7 MB
	/*ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode *r = NULL;
		if (lists.size() > 0)
		{
			r = lists[0];
			for (size_t i = 1; i < lists.size(); i++)
			{
				r = mergeTwoLists(r, lists[i]);
			}
		}

		return r;
	}

	ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if (!l1 || l2 && l1->val > l2->val)swap(l1, l2);
		ListNode *p = l1;

		while (l2)
		{
			if (l1->val <= l2->val)
			{
				if (l1->next != NULL && l1->next->val > l2->val)
				{
					ListNode *tmp = l1->next;
					l1->next = l2;
					l2 = l2->next;
					l1->next->next = tmp;
				}
			}

			if (l1->next)
				l1 = l1->next;
			else
				break;
		}
		if (l2)
			l1->next = l2;

		return p;
	}*/

	//168 ms	10.7 MB
	/*ListNode* mergeKLists(vector<ListNode*>& lists) {
		ListNode *r = new ListNode(-1);
		ListNode *p = r;
		while (lists.size() > 0)
		{
			int i = 0, idx = -1, min = INT32_MAX;
			for (auto it = lists.begin(); it != lists.end();)
			{
				if (!*it)
				{
					it = lists.erase(it);
				}
				else
				{
					if (lists[i]->val < min)
					{
						idx = i;
						min = lists[i]->val;
					}
					i++;
					it++;
				}
			}
			if (idx == -1)continue;
			p->next = lists[idx];
			p = p->next;
			lists[idx] = lists[idx]->next;
			if (!lists[idx])
				lists.erase(lists.begin() + idx);
		}

		return r->next;
	}*/

	struct compare {
		bool operator()(ListNode* lhs,
			ListNode* rhs) const {
			return lhs->val < rhs->val;
		}
	};

	ListNode* mergeKLists(vector<ListNode*>& lists) {
		multiset<ListNode*, compare> set;
		for (auto v : lists)
		{
			while (v)
			{
				set.insert(v);
				v = v->next;
			}
		}

		ListNode *r = new ListNode(-1);
		ListNode *p = r;

		for (auto v : set)
		{
			if (v)
			{
				p->next = v;
				p = p->next;
			}
		}

		return r->next;
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}