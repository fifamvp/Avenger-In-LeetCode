#pragma once
#include <algorithm>
#include <queue>
#include <stack>
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

	// 12 ms 	21.1 MB
	int maxDia = 0;
	int diameterOfBinaryTree(TreeNode* root) {
		calDepth(root);
		return maxDia;
	}

	int calDepth(TreeNode* root)
	{
		if (!root) return 0;
		int leftDepth = calDepth(root->left);
		int rightDepth = calDepth(root->right);
		maxDia = max(leftDepth + rightDepth, maxDia);
		return max(leftDepth, rightDepth) + 1;
	}

};

Solution::Solution()
{
}

Solution::~Solution()
{
}