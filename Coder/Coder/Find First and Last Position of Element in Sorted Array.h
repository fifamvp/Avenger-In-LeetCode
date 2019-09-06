#pragma once
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();

private:
	//8 ms	10.2 MB
	vector<int> searchRange(vector<int>& nums, int target) {
		if (nums.empty())return { -1, -1 };
		int i = 0, j = nums.size() - 1, m;
		while (i <= j)
		{
			m = (i + j) / 2;
			if (nums[m] > target)
				j = m - 1;
			else if (nums[m] < target)
				i = m + 1;
			else
				break;
		}
		if (nums[m] == target) {
			int t = m;
			i = 0;
			j = t;
			while (i < j)
			{
				m = (i + j) / 2;
				if (nums[m] < target)
					i = m + 1;
				else
					j = m;
			}
			vector<int> result = { j };
			i = t;
			j = nums.size() - 1;
			while (i < j)
			{
				m = ceil((double)(i + j) / 2);
				if (nums[m] > target)
					j = m - 1;
				else
					i = m;
			}
			result.push_back(i);
			return result;
		}
		return { -1, -1 };
	}

	//8 ms	10.1 MB
	vector<int> searchRange2(vector<int>& nums, int target) {
		if (nums.empty())return { -1, -1 };
		int i = 0, j = nums.size() - 1, m;
		vector<int> result;
		while (i < j)
		{
			m = (i + j) / 2;
			if (nums[m] < target)
				i = m + 1;
			else
				j = m;
		}
		if (nums[j] == target) {
			result.push_back(j);
			i = j;
			j = nums.size() - 1;
			while (i < j)
			{
				m = ceil((double)(i + j) / 2);
				if (nums[m] > target)
					j = m - 1;
				else
					i = m;
			}
			result.push_back(i);
			return result;
		}
		return { -1, -1 };
	}

	//4 ms	10.2 MB
	vector<int> searchRange3(vector<int>& nums, int target) {
		if (nums.empty()) return { -1, -1 };
		int first = findFirst(nums, target);
		if (first >= nums.size() || nums[first] != target) return { -1, -1 };
		vector<int> result;
		result.push_back(first);
		result.push_back(findFirst(nums, target + 1, first + 1) - 1);
		return result;
	}

	int findFirst(vector<int>& nums, int target, int startIdx = 0) {
		int i = startIdx, j = nums.size() - 1, m;
		while (i <= j)
		{
			m = (j - i) / 2 + i;
			if (nums[m] < target)
				i = m + 1;
			else
				j = m - 1;
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