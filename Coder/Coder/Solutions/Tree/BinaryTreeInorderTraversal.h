#pragma once
#include <vector>
#include <stack>
#include "TreeNode.h"
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();

private:
	// 4 ms	10.4 MB
	vector<int> getMaxLinked(TreeNode* root) {
		vector<int> result;
		if (!root) return result;
		vector<int> left = getMaxLinked(root->left);
		result.insert(result.end(), left.begin(), left.end());
		result.push_back(root->val);
		vector<int> right = getMaxLinked(root->right);
		result.insert(result.end(), right.begin(), right.end());
		return result;
	}

	// 0 ms	8.8 MB
	vector<int> inorderTraversal2(TreeNode* root) {
		vector<int> result;
		if (!root) return result;
		stack<TreeNode*> pending;
		TreeNode* tmp = root;
		while (tmp || !pending.empty())
		{
			while (tmp)
			{
				pending.push(tmp);
				tmp = tmp->left;
			}
			tmp = pending.top();
			pending.pop();
			result.push_back(tmp->val);
			if (tmp->right)
				tmp = tmp->right;
		}
		return result;
	}

	// moris 3 - 5
	vector<int> inorderTraversal3(TreeNode* root) {
		vector<int> result;
		if (!root) return result;
		TreeNode* cur = root;
		while (cur)
		{
			if (cur->left)
			{
				TreeNode* tmp = cur->left;
				while (tmp->right)
				{
					tmp = tmp->right;
				}
				tmp->right = cur;
				cur = cur->left;
			}
			else
			{
				result.push_back(cur->val);
				TreeNode* tmp = cur->right;

				if (tmp && tmp->left == cur)
				{
					cur->right = nullptr;
					result.push_back(tmp->val);
					cur = tmp->right;
				}
				else
				{
					cur = tmp;
				}
			}
		}
		return result;
	}

	// 4 ms	8.8 MB
	// different coding, don't break the tree
	vector<int> inorderTraversal4(TreeNode* root) {
		vector<int> result;
		if (!root) return result;
		TreeNode* cur = root;
		while (cur)
		{
			if (cur->left)
			{
				TreeNode* tmp = cur->left;
				while (tmp->right && tmp->right != cur)
				{
					tmp = tmp->right;
				}
				if (!tmp->right)
				{
					tmp->right = cur;
					cur = cur->left;
				}
				else
				{
					result.push_back(cur->val);
					tmp->right = nullptr;
					cur = cur->right;
				}
			}
			else
			{
				result.push_back(cur->val);
				cur = cur->right;
			}
		}
		return result;
	}

	// 0 ms	8.1 MB
	// prune the left
	vector<int> inorderTraversal5(TreeNode* root) {
		vector<int> result;
		if (!root) return result;
		TreeNode* cur = root;
		while (cur)
		{
			if (cur->left)
			{
				TreeNode* tmp = cur->left;
				while (tmp->right)
				{
					tmp = tmp->right;
				}
				tmp->right = cur;
				TreeNode* tmp2 = cur;
				cur = cur->left;
				tmp2->left = nullptr;
			}
			else
			{
				result.push_back(cur->val);
				cur = cur->right;
			}
		}
		return result;
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}