#pragma once
#include "TreeNode.h"
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();

private:
	// 12 ms	24.2 MB
	int kthSmallest(TreeNode* root, int k) {
		int cur = 0, kthVal = root->val;
		inorderTraversal(root, k, cur, kthVal);
		return kthVal;
	}

	void inorderTraversal(TreeNode* node, int& k, int& cur, int& kthVal)
	{
		if (!node || k <= cur) return;
		inorderTraversal(node->left, k, cur, kthVal);
		if (++cur == k)
		{
			kthVal = node->val;
			return;
		}
		inorderTraversal(node->right, k, cur, kthVal);
	}

	// 12 ms	24.2 MB
	int kthSmallest2(TreeNode* root, int k) {
		return traverse(root, k);
	}

	int traverse(TreeNode* root, int& k)
	{
		if (root)
		{
			int pre = traverse(root->left, k);
			return k == 0 ? pre : --k == 0 ? root->val : traverse(root->right, k);
		}
		return 0;
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}