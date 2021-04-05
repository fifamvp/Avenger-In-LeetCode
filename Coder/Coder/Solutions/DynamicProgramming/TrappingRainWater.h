#pragma once
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();

private:
	// 8 ms	14.4 MB
	int trap(vector<int>& height) {
		vector<int> rightMax(height);
		for (int i = 1; i < rightMax.size(); i++)
		{
			rightMax[i] = max(rightMax[i - 1], rightMax[i]);
		}
		vector<int> leftMax(height);
		for (int i = rightMax.size() - 2; i >= 0; i--)
		{
			leftMax[i] = max(leftMax[i + 1], leftMax[i]);
		}
		int ans = 0;
		for (int i = 0; i < height.size(); i++)
		{
			ans += min(rightMax[i], leftMax[i]) - height[i];
		}
		return ans;
	}

	//8 ms	14.5 MB
	int trap2(vector<int>& height) {
		int current = 0, ans = 0;
		stack<int> stk;
		while (current < height.size())
		{
			while (!stk.empty() && height[current] > height[stk.top()])
			{
				int top = stk.top();
				stk.pop();
				if (stk.empty())
					break;
				int distance = current - stk.top() - 1;
				ans += distance * (min(height[current], height[stk.top()]) - height[top]);
			}
			stk.push(current++);
		}
		return ans;
	}

	// 0 ms	14.2 MB
	int trap3(vector<int>& height) {
		int ans = 0;
		int leftMax = 0, rightMax = 0;
		int leftIdx = 0, rightIdx = height.size() - 1;
		while (leftIdx < rightIdx)
		{
			if (height[leftIdx] < height[rightIdx])
			{
				if (height[leftIdx] > leftMax)
				{
					leftMax = height[leftIdx];
				}
				else
				{
					ans += leftMax - height[leftIdx];
				}
				leftIdx++;
			}
			else
			{
				if (height[rightIdx] > rightMax)
				{
					rightMax = height[rightIdx];
				}
				else
				{
					ans += rightMax - height[rightIdx];
				}
				rightIdx--;
			}
		}
		return ans;
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}