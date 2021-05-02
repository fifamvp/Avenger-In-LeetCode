#pragma once
#include <vector>
#include <set>
#include <algorithm>
using namespace std;
#define S3 1
class Solution
{
public:
	Solution();
	~Solution();

	void Solve()
	{
		vector<int> nums;
		nums = { 2,3,1,1,4 };
		printf("%d\n", jump(nums));
	}

private:
	// 8 ms	10.6 MB
#if S1
	int jump(vector<int>& nums) {
		set<int> s1({ 0 }), s2;
		int depth = 0, curSet = 0;
		int target = nums.size() - 1;
		auto stepToNext = [&](set<int>& cur, set<int>& next) {
			for (auto& e : cur)
			{
				if (e == target)
					return true;
				for (int i = 1; i <= nums[e] && e + i <= target; i++)
					next.emplace(e + i);
			}
			cur.clear();
			curSet = 1 - curSet;
			return false;
		};
		while (!s1.empty() || !s2.empty())
		{
			bool isFound = curSet == 0 ? stepToNext(s1, s2) : stepToNext(s2, s1);
			if (isFound)
				return depth;
			depth++;
		}
		return -1;
	}
#elif S1_2
	// 4 ms	8.4 MB
	int jump(vector<int>& nums) {
		vector<int> v{ 0 };
		int depth = 0;
		int target = nums.size() - 1;
		while (depth <= target)
		{
			vector<int> cur;
			for (int i = 0; i < v.size(); i++)
			{
				int e = v[i];
				if (e == target)
					return depth;
				for (int i = 1; i <= nums[e] && e + i <= target; i++)
				{
					if (std::find(cur.begin(), cur.end(), e + i) == cur.end())
					{
						cur.push_back(e + i);
					}
				}
			}
			v = cur;
			depth++;
		}
		return -1;
	}
#elif S2
	// 4 ms	8 MB
	int jump(vector<int>& nums) {
		int target = nums.size() - 1, start = 0, end = 0;
		int steps = 0;
		while (end < target)
		{
			steps++;
			int maxEnd = end + 1;
			for (int i = start; i <= end; i++)
			{
				if (i + nums[i] >= target) return steps;
				maxEnd = max(maxEnd, i + nums[i]);
			}
			start = end + 1;
			end = maxEnd;
		}
		return steps;
	}
#elif S3
	// Greedy
	// 4 ms	8 MB
	int jump(vector<int>& nums) {
		int target = nums.size() - 1, curEnd = 0, maxEnd = 0;
		int steps = 0;
		for (int i = 0; i < target; i++)
		{
			maxEnd = max(maxEnd, i + nums[i]);
			if (i == curEnd) {
				steps++;
				curEnd = maxEnd;
			}
		}
		return steps;
	}
#endif
};

Solution::Solution()
{
}

Solution::~Solution()
{
}