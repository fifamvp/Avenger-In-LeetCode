#pragma once
#include <vector>
using namespace std;
#define S1_2 1
class Solution
{
public:
	Solution();
	~Solution();

private:
#if S1
	// 4 ms	7.7 MB
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> r;
		vector<int> cur;
		permute(nums, r, cur);
		return r;
	}

	void permute(vector<int>& nums, vector<vector<int>>& r, vector<int>& cur) {
		if (nums.empty())
		{
			r.push_back(cur);
		}
		else
		{
			vector<int> next = nums;
			for (int i = 0; i < nums.size(); i++)
			{
				cur.push_back(nums[i]);
				next.erase(next.begin() + i);
				permute(next, r, cur);
				cur.pop_back();
				next.insert(next.begin() + i, nums[i]);
			}
		}
	}
#elif S1_2
	// 0 ms	7.6 MB
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> r;
		permute(nums, r, 0);
		return r;
	}

	void permute(vector<int>& nums, vector<vector<int>>& r, int startIdx) {
		if (startIdx >= nums.size())
		{
			r.push_back(nums);
		}
		else
		{
			for (int i = startIdx; i < nums.size(); i++)
			{
				swap(nums[startIdx], nums[i]);
				permute(nums, r, startIdx + 1);
				swap(nums[startIdx], nums[i]);
			}
		}
	}
#endif
};

Solution::Solution()
{
}

Solution::~Solution()
{
}