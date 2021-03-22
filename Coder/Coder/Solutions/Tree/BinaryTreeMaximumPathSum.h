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
		getMaxLinked(root);
		return maxSum;
	}

	int getMaxLinked(TreeNode* root)
	{
		if (!root) return 0;
		int maxLinkedL = getMaxLinked(root->left);
		int maxLinkedR = getMaxLinked(root->right);
		int maxLinked = max(max(root->val + maxLinkedL, root->val + maxLinkedR), root->val);
		maxSum = max(max(maxSum, root->val + maxLinkedL + maxLinkedR), maxLinked);
		return maxLinked;
	}

	// 20 ms 27.5 MB
	int getMaxLinked2(TreeNode* root)
	{
		if (!root) return 0;
		int maxLinkedL = max(getMaxLinked2(root->left), 0);
		int maxLinkedR = max(getMaxLinked2(root->right), 0);
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