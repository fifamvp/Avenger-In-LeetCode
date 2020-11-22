#pragma once
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

	// 4 ms	9.5 MB
	TreeNode* invertTree(TreeNode* root) {
		if (root)
		{
			TreeNode* newRight = invertTree(root->left);
			TreeNode* newLeft = invertTree(root->right);
			root->left = newLeft;
			root->right = newRight;
		}
		return root;
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}