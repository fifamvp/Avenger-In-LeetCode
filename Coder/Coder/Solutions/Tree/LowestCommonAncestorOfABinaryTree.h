#pragma once
#include "TreeNode.h"
class Solution
{	
public:
	Solution();
	~Solution();

private:
	TreeNode* result;
	// 16 ms	14.2 MB
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		recurse(root, p, q);
		return result;
	}

	bool recurse(TreeNode* node, TreeNode* p, TreeNode* q)
	{
		if (!node) return false;
		int left = recurse(node->left, p, q) ? 1 : 0;
		int right = recurse(node->right, p, q) ? 1 : 0;
		int mid = node->val == p->val || node->val == q->val ? 1 : 0;
		if (left + right + mid >= 2)
		{
			result = node;
		}
		return left + right + mid > 0;
	}

	//16 ms	14.1 MB
	TreeNode* lowestCommonAncestor2(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root || root == p || root == q) return root;
		TreeNode* left = lowestCommonAncestor2(root->left, p, q);
		TreeNode* right = lowestCommonAncestor2(root->right, p, q);
		return !left ? right : !right ? left : root;
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}