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
	// 12 ms	12.5 MB
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		return combination(candidates, target, 0);
	}

	vector<vector<int>> combination(vector<int>& candidates, int target, int startIdx) {

		vector<vector<int>> r;
		for (int i = startIdx; i < candidates.size(); i++)
		{
			if (target - candidates[i] == 0)
			{
				vector<int> cur;
				cur.push_back(candidates[i]);
				r.push_back(cur);
			}
			else if (target - candidates[i] > 0)
			{
				vector<vector<int>> subs = combination(candidates, target - candidates[i], i);
				for (auto& e : subs)
				{
					vector<int> cur;
					cur.push_back(candidates[i]);
					cur.insert(cur.end(), e.begin(), e.end());
					r.push_back(cur);
				}
			}
		}
		return r;
	}
#elif S1_2
	// 4 ms	10.9 MB
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> r;
		vector<int> combine;
		combination(candidates, target, 0, r, combine);
		return r;
	}

	void combination(vector<int>& candidates, int target, int startIdx, vector<vector<int>>& r, vector<int>& combine) {
		for (int i = startIdx; i < candidates.size(); i++)
		{
			if (target - candidates[i] == 0)
			{
				combine.push_back(candidates[i]);
				r.push_back(combine);
				combine.pop_back();
			}
			else if (target - candidates[i] > 0)
			{
				combine.push_back(candidates[i]);
				combination(candidates, target - candidates[i], i, r, combine);
				combine.pop_back();
			}
		}
	}
#elif S3
	// official
	// 4 ms	10.8 MB
	void dfs(vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& combine, int idx) {
		if (idx == candidates.size()) {
			return;
		}
		if (target == 0) {
			ans.emplace_back(combine);
			return;
		}
		// 直接跳过
		dfs(candidates, target, ans, combine, idx + 1);
		// 选择当前数
		if (target - candidates[idx] >= 0) {
			combine.emplace_back(candidates[idx]);
			dfs(candidates, target - candidates[idx], ans, combine, idx);
			combine.pop_back();
		}
	}

	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> ans;
		vector<int> combine;
		dfs(candidates, target, ans, combine, 0);
		return ans;
	}
#endif
};

Solution::Solution()
{
}

Solution::~Solution()
{
}