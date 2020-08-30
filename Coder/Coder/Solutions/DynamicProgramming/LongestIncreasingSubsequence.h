#pragma once
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();
	void Solve()
	{
		vector<int> nums = { 10,9,2,5,3,7,101,18 };
		nums = { 10,9,2,5,3,7,101,18,464,42,64,164,46164,38,13185,61,8946,13,163,15 };
		printf("%d\n", lengthOfLIS(nums));
	}
private:
	// 68 ms	7.9 MB
	int lengthOfLIS(vector<int>& nums) {
		if (nums.size() < 2) return nums.size();
		vector<int> dp(nums.size(), 1);
		for (int i = 1; i < nums.size(); i++)
		{
			for (int j = 0; j < i; j++)
			{
				if (nums[j] < nums[i] && dp[i] < dp[j] + 1)
					dp[i] = dp[j] + 1;
			}
		}
		int maxLen = INT_MIN;
		for (int i = 0; i < dp.size(); i++)
		{
			if (maxLen < dp[i])
				maxLen = dp[i];
		}
		return maxLen;
	}

	// 4 ms	7.8 MB
	// find the index of number which is >= target
	int indexOfNum(vector<int>& dp, int target)
	{
		int i = 0, j = dp.size() - 1;
		while (i <= j)
		{
			int m = (i + j) / 2;
			if (dp[m] < target)
				i = m + 1;
			else
				j = m - 1;
		}
		return i;
	}

	int lengthOfLIS2(vector<int>& nums) {
		if (nums.size() < 2) return nums.size();
		vector<int> dp = { nums[0] };
		for (int i = 1; i < nums.size(); i++)
		{
			int idx = indexOfNum(dp, nums[i]);
			if (idx == dp.size())
				dp.push_back(nums[i]);
			else
				dp[idx] = nums[i];
		}
		return dp.size();
	}

	// another expression
	int lengthOfLIS2_1(vector<int>& nums) {
		vector<int> res;
		for (int i = 0; i < nums.size(); i++) {
			auto it = std::lower_bound(res.begin(), res.end(), nums[i]);
			if (it == res.end())
				res.push_back(nums[i]);
			else
				*it = nums[i];
		}
		return res.size();
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}