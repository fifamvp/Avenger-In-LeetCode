#pragma once
#include <string>
#include <sstream>
#include "TreeNode.h"
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();

	void	 Solve()
	{
		Solution1 sl;
		string str = "1,2,2,2,1,2,";
		str = "3,2,3,4,3,2,3,4,";
		sl.deserialize(str);
	}

private:
	class Solution1
	{
	public:
		//52 ms	40.3 MB

		// Encodes a tree to a single string.
		string serialize(TreeNode* root) {
			return !root ? "null" : to_string(root->val) + " " + serialize(root->left) + " " + serialize(root->right);
		}

		// Decodes your encoded data to tree.
		TreeNode* deserialize(string data) {
			istringstream ss(data);
			return buildTree(ss);
		}

		TreeNode* buildTree(istringstream& ss)
		{
			string cur;
			ss >> cur;
			if (cur == "null") return nullptr;

			TreeNode* node = new TreeNode(stoi(cur));
			node->left = buildTree(ss);
			node->right = buildTree(ss);
			return node;
		}
	};
	
};

Solution::Solution()
{
}

Solution::~Solution()
{
}