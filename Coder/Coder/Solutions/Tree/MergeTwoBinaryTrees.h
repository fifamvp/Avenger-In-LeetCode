#pragma once
#include <stack>
#include "TreeNode.h"
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();

private:
	// 60 ms	 33.9 MB
	TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
		if (t2)
		{
			if (!t1)
			{
				t1 = new	 TreeNode(t2->val);
			}
			else
			{
				t1->val += t2->val;
			}

			if (!t1->left && t2->left)
			{
				t1->left = new TreeNode();
			}

			if (!t1->right && t2->right)
			{
				t1->right = new TreeNode();
			}

			mergeTrees(t1->left, t2->left);
			mergeTrees(t1->right, t2->right);
		}

		return t1;
	}

	// 60 ms 	33.9 MB
	TreeNode* mergeTrees2(TreeNode* t1, TreeNode* t2) {
		if (!t2) return t1;
		if (!t1) return t2;
		t1->val += t2->val;
		t1->left = mergeTrees2(t1->left, t2->left);
		t1->right = mergeTrees2(t1->right, t2->right);
		return t1;
	}

	// 56 ms	 34.2 MB
	TreeNode* mergeTrees3(TreeNode* t1, TreeNode* t2) {
		if (!t1) return t2;
		stack<TreeNode*> pendingT1, pendingT2;
		pendingT1.push(t1);
		pendingT2.push(t2);

		while (!pendingT1.empty() || !pendingT2.empty())
		{
			TreeNode* tmp1 = pendingT1.top();
			pendingT1.pop();
			TreeNode* tmp2 = pendingT2.top();
			pendingT2.pop();

			if (tmp1 && tmp2)
			{
				tmp1->val += tmp2->val;

				if (!tmp1->left)
				{
					tmp1->left = tmp2->left;
				}
				else
				{
					pendingT1.push(tmp1->left);
					pendingT2.push(tmp2->left);
				}

				if (!tmp1->right)
				{
					tmp1->right = tmp2->right;
				}
				else
				{
					pendingT1.push(tmp1->right);
					pendingT2.push(tmp2->right);
				}
			}
		}

		return t1;
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}