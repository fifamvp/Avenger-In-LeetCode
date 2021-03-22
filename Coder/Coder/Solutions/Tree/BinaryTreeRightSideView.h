#pragma once
#include <vector>
#include <queue>
#include "TreeNode.h"
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();

private:
	// 4 ms	12.2 MB
	vector<int> rightSideView(TreeNode* root) {
		vector<int> result;
		if (!root) return result;
		queue<TreeNode*> bfs({ root });
		int numInLevel = 1;
		while (!bfs.empty())
		{
			for (int i = 0; i < numInLevel; i++)
			{
				TreeNode* tmp = bfs.front();
				bfs.pop();
				if (tmp->left)
				{
					bfs.emplace(tmp->left);
				}
				if (tmp->right)
				{
					bfs.emplace(tmp->right);
				}
				if (i == numInLevel - 1)
				{
					result.push_back(tmp->val);
				}
			}
			numInLevel = bfs.size();
		}
		return result;
	}

	// 0 ms	11.8 MB
	vector<int> rightSideView2(TreeNode* root) {
		vector<int> result;
		recursion(root, 0, result);
		return result;
	}

	void recursion(TreeNode* node, int level, vector<int>& result)
	{
		if (!node) return;
		if (level >= result.size()) result.push_back(node->val);
		recursion(node->right, level + 1, result);
		recursion(node->left, level + 1, result);
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}