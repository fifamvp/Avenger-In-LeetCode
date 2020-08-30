#pragma once
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();

	void Solve()
	{
		vector<int> nums = { 2,7,9,3,1 };
		nums = { 1,2,3,1 };
		nums = { 7,9,4,1,100,99 };

		printf("%d\n", rob(nums));
	}

private:
	// rob(i) = max(rob(i - 2) + currentHouseValue, rob(i - 1))

	// 4 ms	8.3 MB
	// nextMaxSum is used to store all the max sum of following possible numbers
	unordered_map<int, int> nextMaxSum;
	int rob(vector<int>& nums) {
		return max(robNext(nums, 0, 0), robNext(nums, 0, 1));
	}

	int robNext(vector<int>& nums, int sum, int idx) {
		if (idx >= nums.size()) return sum;
		sum += nums[idx];
		if (nextMaxSum.find(idx) == nextMaxSum.end())
			nextMaxSum[idx] = max(robNext(nums, sum, idx + 2), robNext(nums, sum, idx + 3)) - sum;
		return sum + nextMaxSum[idx];
	}

	// 4 ms	7.9 MB
	// 0 ms	7.7 MB if use #define max(a, b) ((a)>(b)?(a):(b))
	int rob2(vector<int>& nums) {
		int pre2house = 0, pre1house = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			int temp = max(pre2house + nums[i], pre1house);
			pre2house = pre1house;
			pre1house = temp;
		}
		return pre1house;
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}
