#pragma once
#include <algorithm>
#include <Queue>
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

	// O(N) O(height)
	// 8 ms 19.5 MB
	int maxDepth(TreeNode* root) {
		if (!root) return 0;
		return max(maxDepth(root->left), maxDepth(root->right)) + 1;
	}

	// 12 ms	 19.3 MB
	int maxDepth2(TreeNode* root) {
		if (!root) return 0;
		queue<TreeNode*> q({ root });
		int depth = 0, amountInNextLevel = 1;
		int count = amountInNextLevel;
		while (!q.empty())
		{
			TreeNode* ptr = q.front();
			q.pop();
			if (--count == 0)
			{
				depth++;
				count = amountInNextLevel;
				amountInNextLevel = 0;
			}

			if (ptr->left)
			{
				q.push(ptr->left);
				amountInNextLevel++;
			}
			if (ptr->right)
			{
				q.push(ptr->right);
				amountInNextLevel++;
			}
		}
		return depth;
	}

	// O(N) O(N)
	// 16 ms 	19.4 MB
	int maxDepth2_1(TreeNode* root) {
		if (!root) return 0;
		queue<TreeNode*> unvisited({ root });
		int maxDepth = 0;
		while (!unvisited.empty())
		{
			int amount = unvisited.size();
			for (int i = 0; i < amount; i++)
			{
				TreeNode* ptr = unvisited.front();
				unvisited.pop();
				if (ptr->left)
					unvisited.push(ptr->left);
				if (ptr->right)
					unvisited.push(ptr->right);
			}
			maxDepth++;
		}
		return maxDepth;
	}

	// 12 ms	 19.3 MB
	int maxDepth3(TreeNode* root) {
		if (!root) return 0;
		stack<TreeNode*> unvisitedStk({ root });
		stack<int> depthStk({ 1 });
		int maxDepth = 1;
		while (!unvisitedStk.empty())
		{
			TreeNode* ptr = unvisitedStk.top();
			int t = depthStk.top();
			maxDepth = max(maxDepth, t);
			unvisitedStk.pop();
			depthStk.pop();
			if (ptr->right) 
			{
				unvisitedStk.push(ptr->right);
				depthStk.push(t + 1);
			}
			if (ptr->left)
			{
				unvisitedStk.push(ptr->left);
				depthStk.push(t + 1);
			}
		}
		return maxDepth;
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}