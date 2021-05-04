#pragma once
#include <vector>
#include <algorithm>
using namespace std;
#define S1_2 1
class Solution
{
public:
	Solution();
	~Solution();

private:
#if S1
	// 20 ms	14.2 MB
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> r;
		if (intervals.empty()) return r;
		sort(intervals.begin(), intervals.end());
		int preStart = intervals[0][0], preEnd = intervals[0][1];
		for (int i = 1; i < intervals.size(); i++)
		{
			if (intervals[i][0] > preEnd)
			{
				vector<int> interval = { preStart, preEnd };
				r.push_back(interval);
				preStart = intervals[i][0];
				preEnd = intervals[i][1];
			}
			else
			{
				if (intervals[i][0] < preStart)
				{
					preStart = intervals[i][0];
				}
				if (intervals[i][1] > preEnd)
				{
					preEnd = intervals[i][1];
				}
			}
		}
		vector<int> interval = { preStart, preEnd };
		r.push_back(interval);
		return r;
	}
#elif S1_2
	// 12 ms	14.2 MB
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		vector<vector<int>> r;
		sort(intervals.begin(), intervals.end());
		r.push_back(intervals[0]);
		for (int i = 1; i < intervals.size(); i++)
		{
			if (intervals[i][0] > r.back()[1])
			{
				r.push_back({ intervals[i][0] , intervals[i][1] });
			}
			else
			{
				r.back()[1] = max(r.back()[1], intervals[i][1]);
			}
		}
		return r;
	}
#endif
};

Solution::Solution()
{
}

Solution::~Solution()
{
}