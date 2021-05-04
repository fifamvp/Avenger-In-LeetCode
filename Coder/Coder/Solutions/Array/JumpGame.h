#pragma once
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();

private:
	// 8 ms	12.9 MB
	bool canJump(vector<int>& nums) {
		int curEnd = 0, maxEnd = 0;
		for (int i = 0; i < nums.size() - 1; i++)
		{
			maxEnd = max(maxEnd, i + nums[i]);
			if (i == curEnd) {
				if (curEnd == maxEnd)
					break;
				curEnd = maxEnd;
			}
		}
		return curEnd >= nums.size() - 1;
	}

	// 4 ms	12.7 MB
	bool canJump2(vector<int>& nums) {
		int lastPos = nums.size() - 1;
		for (int i = nums.size() - 1; i >= 0; i--) {
			if (i + nums[i] >= lastPos) {
				lastPos = i;
			}
		}
		return lastPos == 0;
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}