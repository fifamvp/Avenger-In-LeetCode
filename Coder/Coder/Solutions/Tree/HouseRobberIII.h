#pragma once
#include <algorithm>
#include <vector>
#include "TreeNode.h"
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();
	// [79,99,77,null,null,null,69,null,60,53,null,73,11,null,null,null,62,27,62,null,null,98,50,null,null,90,48,82,null,null,null,55,64,null,null,73,56,6,47,null,93,null,null,75,44,30,82,null,null,null,null,null,null,57,36,89,42,null,null,76,10,null,null,null,null,null,32,4,18,null,null,1,7,null,null,42,64,null,null,39,76,null,null,6,null,66,8,96,91,38,38,null,null,null,null,74,42,null,null,null,10,40,5,null,null,null,null,28,8,24,47,null,null,null,17,36,50,19,63,33,89,null,null,null,null,null,null,null,null,94,72,null,null,79,25,null,null,51,null,70,84,43,null,64,35,null,null,null,null,40,78,null,null,35,42,98,96,null,null,82,26,null,null,null,null,48,91,null,null,35,93,86,42,null,null,null,null,0,61,null,null,67,null,53,48,null,null,82,30,null,97,null,null,null,1,null,null]
	// [79, 99, 77, null, null, null, 69, null, 60, 53, null, 73, 11, null, null, null, 62]
private:
	// 8 ms	22.1 MB
	int rob(TreeNode* root) {
		int max01, max02;
		Traverse(root, max01, max02);

		return max(max01, max02);
	}

	void Traverse(TreeNode* node, int& max01, int& max02)
	{
		if (!node)
		{
			max01 = 0;
			max02 = 0;
			return;
		}
		int max01L, max02L, max01R, max02R;
		Traverse(node->left, max01L, max02L);
		Traverse(node->right, max01R, max02R);
		max01 = node->val + max02L + max02R;
		max02 = max(max01L, max02L) + max(max01R, max02R);
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}