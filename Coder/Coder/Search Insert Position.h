#pragma once
#include <vector>
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();

private:
	//8 ms	8.9 MB
	int searchInsert(vector<int>& nums, int target) {
		int i = 0, j = nums.size() - 1, m;
		while (i <= j)
		{
			m = (i + j) / 2;
			if (nums[m] < target)
				i = m + 1;
			else if (nums[m] > target)
				j = m - 1;
			else
				return m;
		}
		return i;
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}