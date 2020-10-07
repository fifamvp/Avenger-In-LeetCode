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

	// 20 ms	 24.4 MB	
	TreeNode* trimBST(TreeNode* root, int low, int high) {
		if (!root) return nullptr;
		if (root->val < low)
		{
			return trimBST(root->right, low, high);
		}
		else if (root->val > high)
		{
			return trimBST(root->left, low, high);
		}
		else
		{
			root->left = trimBST(root->left, low, high);
			root->right = trimBST(root->right, low, high);
		}
		return root;
	}

	// 20 ms		17.5 MB
	/*TreeNode* trimBST(TreeNode* root, int low, int high) {
		if (!root) return nullptr;
		root->left = trimBST(root->left, low, high);
		root->right = trimBST(root->right, low, high);
		return root->val >= low && root->val <= high ? root : root->val < low ? root->right : root->left;
	}*/
};

Solution::Solution()
{
}

Solution::~Solution()
{
}