#pragma once
#include <unordered_map>
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();
	//["LRUCache","put","get","put","get","get"]
	//[[1], [2, 1], [2], [3, 2], [2], [3]]

	//["LRUCache","get","put","get","put","put","get","get"]
	//[[2], [2], [2, 6], [1], [1, 5], [1, 2], [1], [2]]

	//["LRUCache","put","put","put","put","get","get"]
	//[[2], [2, 1], [1, 1], [2, 3], [4, 1], [1], [2]]
private:
	//64 ms	39.9 MB
	class LRUCache {
		struct ListNode
		{
			ListNode* pre;
			ListNode* next;
			int key;
			int value;
		};
	public:
		LRUCache(int capacity) {
			m_capacity = capacity;
			head = nullptr;
			tail = nullptr;
		}

		int get(int key) {
			if (cache.count(key))
			{
				ListNode* cur = cache[key];
				if (cur != tail)
				{
					if (cur == head)
					{
						head = cur->next;
					}
					else
					{
						cur->pre->next = cur->next;
						cur->next->pre = cur->pre;
					}
					cur->next = nullptr;
					cur->pre = tail;
					tail->next = cur;
					tail = tail->next;
				}
				return cur->value;
			}
			return -1;
		}

		void put(int key, int value) {
			// Key has already exists (it is regarded as an get)
			if (get(key) != -1)
			{
				cache[key]->value = value;
				return;
			}

			// The cache is full
			if (cache.size() == m_capacity)
			{
				int deleteKey = head->key;
				cache.erase(deleteKey);
				ListNode* tmp = head->next;
				delete(head);
				head = tmp;
				if (head)
					head->pre = nullptr;
			}

			// Put new one
			ListNode* newNode = new ListNode();
			newNode->key = key;
			newNode->value = value;
			if (!head)
			{
				head = tail = newNode;
			}
			else
			{
				newNode->pre = tail;
				tail->next = newNode;
				tail = tail->next;
			}
			cache[key] = newNode;
		}

		// 76 ms	39.5 MB
		void put2(int key, int value) {
			// Key has already exists (it is regarded as an get)
			if (get(key) != -1)
			{
				cache[key]->value = value;
				return;
			}

			ListNode* newNode;

			// The cache is full
			if (cache.size() == m_capacity)
			{
				cache.erase(head->key);
				newNode = head;
				head = head->next;
				if (head)
					head->pre = nullptr;
			}
			else
			{
				newNode = new ListNode();
			}

			// Put new one
			newNode->key = key;
			newNode->value = value;
			cache[key] = newNode;

			if (!head)
			{
				head = tail = newNode;
			}
			else
			{
				newNode->pre = tail;
				tail->next = newNode;
				tail = tail->next;
			}
		}
	private:
		int m_capacity;
		unordered_map<int, ListNode*> cache;
		ListNode* head;
		ListNode* tail;
	};

	/**
	 * Your LRUCache object will be instantiated and called as such:
	 * LRUCache* obj = new LRUCache(capacity);
	 * int param_1 = obj->get(key);
	 * obj->put(key,value);
	 */
};

Solution::Solution()
{
}

Solution::~Solution()
{
}