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
	// [5,1,4,null,null,6,7]
	// [1,1]

	//16 ms	21.7 MB
	bool isValidBST(TreeNode* root) {
		stack<TreeNode*> stk;
		TreeNode* cur = root, *prev = nullptr;
		while (!stk.empty() || cur)
		{
			while (cur)
			{
				stk.push(cur);
				cur = cur->left;
			}
			cur = stk.top();
			stk.pop();
			if (prev && prev->val >= cur->val) return false;
			prev = cur;
			cur = cur->right;
		}
		return true;
	}

	// 8 ms	21.7 MB
	bool isValidBST2(TreeNode* root) {
		vector<int> vals;
		inorderTraversal(root, vals);
		for (int i = 0; i < vals.size() - 1; i++)
		{
			if (vals[i] >= vals[i + 1])
				return false;
		}
		return true;
	}

	void inorderTraversal(TreeNode* root, vector<int>& vals)
	{
		if (!root) return;
		inorderTraversal(root->left, vals);
		vals.push_back(root->val);
		inorderTraversal(root->right, vals);
	}

	//16 ms	21.7 MB
	bool isValidBST2_1(TreeNode* root) {
		TreeNode* prev = nullptr;
		return inorderTraversal(root, prev);
	}

	bool inorderTraversal(TreeNode* cur, TreeNode*& prev)
	{
		if (!cur) return true;
		if (!inorderTraversal(cur->left, prev)) return false;
		if (prev && prev->val >= cur->val) return false;
		prev = cur;
		return inorderTraversal(cur->right, prev);
	}

	// 16 ms	21.8 MB
	// morris
	bool isValidBST3(TreeNode* root) {
		vector<int> vals;
		TreeNode* cur = root;
		while (cur)
		{
			if (!cur->left)
			{
				vals.push_back(cur->val);
				cur = cur->right;
			}
			else
			{
				TreeNode* tempPrev = cur->left;
				while (tempPrev->right && tempPrev->right != cur)
				{
					tempPrev = tempPrev->right;
				}
				if (tempPrev->right == cur)
				{
					tempPrev->right = nullptr;
					vals.push_back(cur->val);
					cur = cur->right;
				}
				else
				{
					tempPrev->right = cur;
					cur = cur->left;
				}
			}
		}
		for (int i = 0; i < vals.size() - 1; i++)
		{
			if (vals[i] >= vals[i + 1])
				return false;
		}
		return true;
	}

	// 20 ms	21.5 MB
	bool isValidBST4(TreeNode* root) {
		vector<int> vals;
		inorderTraversal(root, nullptr, nullptr);
		for (int i = 0; i < vals.size() - 1; i++)
		{
			if (vals[i] >= vals[i + 1])
				return false;
		}
		return true;
	}

	bool inorderTraversal(TreeNode* cur, TreeNode* lower, TreeNode* higher)
	{
		if (!cur) return true;
		if (lower && lower->val >= cur->val) return false;
		if (!inorderTraversal(cur->left, lower, cur)) return false;
		if (higher && higher->val <= cur->val) return false;
		return inorderTraversal(cur->right, cur, higher);
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}