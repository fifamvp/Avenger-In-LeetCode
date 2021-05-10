#pragma once
#include <vector>
using namespace std;
#define S3 1
class Solution
{
public:
	Solution();
	~Solution();

private:
#if S1
	// 0 ms	7.3 MB
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> r;
		r.push_back({});
		for (int num : nums)
		{
			vector<vector<int>> tmp;
			for (auto vec : r)
			{
				vec.push_back(num);
				tmp.emplace_back(vec);
			}
			r.insert(r.end(), tmp.begin(), tmp.end());
		}
		return r;
	}
#elif S2
	// 0 ms	10.6 MB
	void dfs(int cur, vector<int>& nums, vector<vector<int>>& r, vector<int>& curSet)
	{
		if (cur >= nums.size()) {
			r.push_back(curSet);
			return;
		}
		// Exclude current num
		dfs(cur + 1, nums, r, curSet);
		// Include current num
		curSet.push_back(nums[cur]);
		dfs(cur + 1, nums, r, curSet);
		curSet.pop_back();
	}
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> r;
		vector<int> curSet;
		dfs(0, nums, r, curSet);
		return r;
	}
#elif S3
	// 0 ms	6.9 MB
	vector<vector<int>> subsets(vector<int>& nums) {
		vector<vector<int>> r;
		vector<int> curSet;
		int n = nums.size();
		for (int mask = 0; mask < (1 << n); mask++)
		{
			curSet.clear();
			for (int i = 0; i < n; i++)
			{
				if (mask & (1 << i)) {
					curSet.push_back(nums[i]);
				}
			}
			r.emplace_back(curSet);
		}
		return r;
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}