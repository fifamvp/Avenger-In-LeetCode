#pragma once
#include <vector>
using namespace std;
#define S2 1
class Solution
{
public:
	Solution();
	~Solution();

private:
#if S1
	// 56 ms	33.7 MB
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int> result;
		for (int i = 0; i < nums.size(); i++)
		{
			while (nums[i] != i + 1)
			{
				if (nums[i] == nums[nums[i] - 1]) break;
				swap(nums[i], nums[nums[i] - 1]);
			}
		}
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != i + 1)
				result.push_back(i + 1);
		}
		return result;
	}
#elif S2
	// 56 ms	33.6 MB
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		vector<int> result;
		for (int i = 0; i < nums.size(); i++)
		{
			int idx = abs(nums[i]) - 1;
			if (nums[idx] > 0)
				nums[idx] = -nums[idx];
		}
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] > 0)
				result.push_back(i + 1);
		}
		return result;
	}
#elif S2_1
	// 56 ms	33.7 MB
	vector<int> findDisappearedNumbers(vector<int>& nums) {
		int n = nums.size();
		for (auto& num : nums) {
			int x = (num - 1) % n;
			nums[x] += n;
		}
		vector<int> result;
		for (int i = 0; i < n; i++) {
			if (nums[i] <= n) {
				result.push_back(i + 1);
			}
		}
		return result;
	}
#endif
};

Solution::Solution()
{
}

Solution::~Solution()
{
}