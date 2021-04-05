#pragma once
#include <vector>
#include <unordered_map>
#include "TreeNode.h"
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();

private:
	// 24 ms	15.9 MB
	int amount = 0;
	vector<int> sums;
	int pathSum(TreeNode* root, int sum) {
		if (!root) return 0;
		sums.push_back(0);
		for (int i = 0; i < sums.size(); i++)
		{
			sums[i] += root->val;
			if (sums[i] == sum)
				amount++;
		}

		pathSum(root->left, sum);
		pathSum(root->right, sum);
		sums.pop_back();
		for (int i = 0; i < sums.size(); i++)
		{
			sums[i] -= root->val;
		}
		return amount;
	}

	class Solution2
	{
	public:
		// 16 ms	18.5 MB
		int pathSum(TreeNode* root, int sum) {
			unordered_map<int, int> store;
			return helper(root, sum, store, 0);
		}

		int helper(TreeNode* node, int sum, unordered_map<int, int>& store, int pre) {
			if (!node) return 0;
			node->val += pre;
			int res = (node->val == sum) + (store.count(node->val - sum) ? store[node->val - sum] : 0);
			store[node->val]++;
			res += helper(node->left, sum, store, node->val) + helper(node->right, sum, store, node->val);
			store[node->val]--;
			return res;
		}
	};

	class Solution3
	{
	public:
		// 16 ms	15.6 MB
		int ans = 0;
		int pathSum(TreeNode* root, int sum) {
			if (root) {
				traverse(root, sum, 0);
				pathSum(root->left, sum);
				pathSum(root->right, sum);
			}
			return ans;
		}

		void traverse(TreeNode* node, int sum, int pre)
		{
			if (!node) return;
			pre += node->val;
			if (pre == sum)
				ans++;
			traverse(node->left, sum, pre);
			traverse(node->right, sum, pre);
		}
	};
};

Solution::Solution()
{
}

Solution::~Solution()
{
}