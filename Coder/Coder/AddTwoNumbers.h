#pragma once

struct ListNode {
	int val;
	ListNode *next;
	ListNode(int x) : val(x), next(NULL) {}
};

class AddTwoNumbers
{
public:
	AddTwoNumbers();
	~AddTwoNumbers();
	void Solve() {
		ListNode* l1 = new ListNode(2);
		l1->next = new ListNode(4);
		l1->next->next = new ListNode(3);

		ListNode* l2 = new ListNode(5);
		l2->next = new ListNode(6);
		l2->next->next = new ListNode(4);

		ListNode* r = addTwoNumbers(l1, l2);

		while (r != nullptr)
		{
			cout << r->val << endl;
			r = r->next;
		}
	}

private:
	ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
		ListNode* p = new ListNode(-1);
		ListNode* result = p;

		int d = 0;
		while (l1 || l2 || d != 0)
		{
			if (l1) {
				d += l1->val;
				l1 = l1->next;
			}
			if (l2) {
				d += l2->val;
				l2 = l2->next;
			}

			p->next = new ListNode(d % 10);
			p = p->next;

			d /= 10;
		}

		return result->next;
	}
};

AddTwoNumbers::AddTwoNumbers()
{
}

AddTwoNumbers::~AddTwoNumbers()
{
}