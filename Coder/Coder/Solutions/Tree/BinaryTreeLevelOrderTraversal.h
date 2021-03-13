#pragma once
#include <queue>
#include <vector>
#include "TreeNode.h"
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();

private:
	// 4 ms	12.5 MB
	vector<vector<int>> levelOrder(TreeNode* root) {
		vector<vector<int>> r;
		if (!root) return r;
		queue<TreeNode*> q({ root });
		int numInLevel = 1;
		vector<int> tmp;
		while (!q.empty())
		{
			for (int i = 0; i < numInLevel; i++)
			{
				TreeNode* cur = q.front();
				q.pop();
				tmp.push_back(cur->val);
				if (cur->left)
					q.emplace(cur->left);
				if (cur->right)
					q.emplace(cur->right);
			}
			numInLevel = q.size();
			r.push_back(tmp);
			tmp.clear();
		}
		return r;
	}

	vector<vector<int>> levelOrder2(TreeNode* root) {
		vector<vector<int>> r;
		traversal(root, 0, r);
		return r;
	}

	// 0 ms 13.6 MB
	void traversal(TreeNode* cur, int depth, vector<vector<int>>& r)
	{
		if (!cur) return;
		if (r.size() == depth)
			r.push_back(vector<int>{});
		if (cur)
			r[depth].push_back(cur->val);
		traversal(cur->left, depth + 1, r);
		traversal(cur->right, depth + 1, r);
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}