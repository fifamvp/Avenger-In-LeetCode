#pragma once
#include <algorithm>
#include "TreeNode.h"
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();

private:
	int maxSum = INT_MIN;
	int maxPathSum(TreeNode* root) {
		inorderTraversal(root);
		return maxSum;
	}

	int inorderTraversal(TreeNode* root)
	{
		if (!root) return 0;
		int maxLinkedL = inorderTraversal(root->left);
		int maxLinkedR = inorderTraversal(root->right);
		int maxLinked = max(max(root->val + maxLinkedL, root->val + maxLinkedR), root->val);
		maxSum = max(max(maxSum, root->val + maxLinkedL + maxLinkedR), maxLinked);
		return maxLinked;
	}

	// 20 ms 27.5 MB
	int inorderTraversal2(TreeNode* root)
	{
		if (!root) return 0;
		int maxLinkedL = max(inorderTraversal2(root->left), 0);
		int maxLinkedR = max(inorderTraversal2(root->right), 0);
		maxSum = max(maxSum, root->val + maxLinkedL + maxLinkedR);
		return root->val + max(maxLinkedL, maxLinkedR);
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}