#pragma once
#include <queue>
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();

private:
	struct TreeNode {
		int val;
		TreeNode *left;
		TreeNode *right;
		TreeNode() : val(0), left(nullptr), right(nullptr) {}
		TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
		TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
	};
	// the answer is true when root is nullptr


	// 12 ms		16.7 MB
	bool isSymmetric(TreeNode* root) {
		return !root || isEquivalent(root->left, root->right);
	}

	bool isEquivalent(TreeNode* leftNode, TreeNode* rightNode)
	{
		if (!leftNode && rightNode || leftNode && !rightNode) return false;

		return !leftNode || leftNode->val == rightNode->val && isEquivalent(leftNode->left, rightNode->right) && isEquivalent(leftNode->right, rightNode->left);
	}

	// 0 ms		17.2 MB
	bool isSymmetric2(TreeNode* root) {
		if (!root) return true;
		queue<TreeNode*> leftQ({ root->left });
		queue<TreeNode*> rightQ({ root->right });

		while (!leftQ.empty() && !rightQ.empty())
		{
			TreeNode* l = leftQ.front();
			leftQ.pop();
			TreeNode* r = rightQ.front();
			rightQ.pop();

			if (!l && r || l && !r) return false;
			if (l)
			{
				if (l->val != r->val) return false;
				leftQ.push(l->left);
				leftQ.push(l->right);
				rightQ.push(r->right);
				rightQ.push(r->left);
			}
		}

		return leftQ.empty() && rightQ.empty();
	}

	// 4 ms	16.9 MB
	bool isSymmetric3(TreeNode* root) {
		if (!root) return true;
		queue<TreeNode*> pending({ root->left, root->right });

		while (!pending.empty())
		{
			TreeNode* l = pending.front();
			pending.pop();
			TreeNode* r = pending.front();
			pending.pop();

			if (!l && r || l && !r) return false;
			if (l)
			{
				if (l->val != r->val) return false;
				pending.push(l->left);
				pending.push(r->right);
				pending.push(l->right);
				pending.push(r->left);
			}
		}

		return true;
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}