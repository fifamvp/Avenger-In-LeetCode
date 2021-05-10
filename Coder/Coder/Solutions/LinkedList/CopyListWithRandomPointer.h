#pragma once
#include "Node.h"
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();

private:
	// 8 ms	11.3 MB
	Node* copyRandomList(Node* head) {
		if (!head) return nullptr;
		createNewNode(head);
		copyRandomPointer(head);
		return disconnectNewNodeList(head);
	}
	
	void createNewNode(Node* head) {
		Node* origin = head;
		while (origin)
		{
			Node* copied = new Node(origin->val);
			copied->next = origin->next;
			origin->next = copied;
			origin = origin->next->next;
		}
	}

	void copyRandomPointer(Node* head) {
		Node* origin = head;
		while (origin)
		{
			Node* copied = origin->next;
			if (origin->random)
				copied->random = origin->random->next;
			origin = origin->next->next;
		}
	}

	Node* disconnectNewNodeList(Node* head) {
		Node* newHead = head->next;
		Node* preCopied = newHead;
		Node* origin = head;

		origin->next = origin->next->next;
		origin = origin->next;
		while (origin)
		{
			preCopied->next = origin->next;
			preCopied = preCopied->next;
			origin->next = origin->next->next;
			origin = origin->next;
		}
		return newHead;
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}