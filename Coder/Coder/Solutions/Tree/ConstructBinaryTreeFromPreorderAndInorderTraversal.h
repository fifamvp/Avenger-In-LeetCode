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
	// 20 ms	25.9 MB
	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		return buildTree(preorder, 0, inorder, 0, inorder.size() - 1);
	}

	TreeNode* buildTree(vector<int>& preorder, int curIdx, vector<int>& inorder, int inBeginIdx, int inEndIdx) {
		if (curIdx >= preorder.size() || inBeginIdx > inEndIdx) return nullptr;
		TreeNode* node = new TreeNode(preorder[curIdx]);
		auto it = find(inorder.begin() + inBeginIdx, inorder.begin() + inEndIdx, preorder[curIdx]);
		int inIdx = distance(inorder.begin(), it);
		int numOfLeft = inIdx - inBeginIdx;
		node->left = buildTree(preorder, curIdx + 1, inorder, inBeginIdx, inIdx - 1);
		node->right = buildTree(preorder, curIdx + numOfLeft + 1, inorder, inIdx + 1, inEndIdx);
		return node;
	}

	// 44 ms	25.9 MB	
	// spent more time if using for-loop
	TreeNode* buildTree(vector<int>& preorder, int curIdx, vector<int>& inorder, int inBeginIdx, int inEndIdx) {
		if (curIdx >= preorder.size() || inBeginIdx > inEndIdx) return nullptr;
		TreeNode* node = new TreeNode(preorder[curIdx]);
		int inIdx = inBeginIdx;
		for (; inIdx <= inEndIdx; inIdx++)
		{
			if (inorder[inIdx] == preorder[curIdx])
				break;
		}
		int numOfLeft = inIdx - inBeginIdx;
		node->left = buildTree(preorder, curIdx + 1, inorder, inBeginIdx, inIdx - 1);
		node->right = buildTree(preorder, curIdx + numOfLeft + 1, inorder, inIdx + 1, inEndIdx);
		return node;
	}

	// 16 ms	25.9 MB
	int preIdx = 0;
	TreeNode* buildTree2(vector<int>& preorder, vector<int>& inorder) {
		return buildTree(preorder, inorder, 0, inorder.size() - 1);
	}

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int start, int end) {
		if (start > end) return nullptr;
		TreeNode* node = new TreeNode(preorder[preIdx++]);
		auto it = find(inorder.begin() + start, inorder.begin() + end, node->val);
		int inIdx = distance(inorder.begin(), it);
		node->left = buildTree(preorder, inorder, start, inIdx - 1);
		node->right = buildTree(preorder, inorder, inIdx + 1, end);
		return node;
	}

	// 8 ms	26.3 MB
	unordered_map<int, int> inorderMap;
	TreeNode* buildTree3(vector<int>& preorder, vector<int>& inorder) {
		for (int i = 0; i < inorder.size(); i++)
			inorderMap.emplace(inorder[i], i);
		return buildTreeWithMap(preorder, inorder, 0, inorder.size() - 1);
	}

	TreeNode* buildTreeWithMap(vector<int>& preorder, vector<int>& inorder, int start, int end) {
		if (start > end) return nullptr;
		TreeNode* node = new TreeNode(preorder[preIdx++]);
		int inIdx = inorderMap[node->val];
		node->left = buildTreeWithMap(preorder, inorder, start, inIdx - 1);
		node->right = buildTreeWithMap(preorder, inorder, inIdx + 1, end);
		return node;
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}