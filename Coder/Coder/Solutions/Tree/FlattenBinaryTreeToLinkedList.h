#pragma once
#include "TreeNode.h"
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();

private:
	// 0 ms	12.5 MB
	void flatten(TreeNode* root) {
		if (!root) return;
		TreeNode* cur = root;
		while (!cur->left && cur->right)
			cur = cur->right;

		while (cur->left)
		{
			TreeNode* p = cur->left;
			while (p->right)
				p = p->right;
			p->right = cur->right;
			cur->right = cur->left;
			cur->left = nullptr;
			while (!cur->left && cur->right)
				cur = cur->right;
		}
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}