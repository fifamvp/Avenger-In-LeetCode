#pragma once
#include <vector>
#include <map>
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();

private:
	// Boyer-Moore Voting Algorithm
	// 16 ms	19.7 MB
	int majorityElement(vector<int>& nums) {
		int cur, amount = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (amount == 0)
			{
				cur = nums[i];
			}
			amount += cur == nums[i] ? 1 : -1;
		}
		return cur;
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}