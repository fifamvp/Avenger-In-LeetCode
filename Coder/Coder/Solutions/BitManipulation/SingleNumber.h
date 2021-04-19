#pragma once
#include <vector>
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();

private:
	// 8 ms	17 MB
	int singleNumber(vector<int>& nums) {
		int result = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			result ^= nums[i];
		}
		return result;
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}