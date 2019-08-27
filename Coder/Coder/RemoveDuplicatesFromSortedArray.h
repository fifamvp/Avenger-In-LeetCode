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
	//156 ms	9.9 MB
	int removeDuplicates(vector<int>& nums) {
		if (nums.empty())return 0;
		vector<int>::iterator firstIt = nums.begin();
		for (auto it = nums.begin() + 1; it != nums.end();it++)
		{
			if (*it != *firstIt)
			{
				if (it != firstIt + 1)// save time if there is no interval number
					it = nums.erase(firstIt + 1, it);
				firstIt = it;
			}
		}
		if (firstIt + 1 != nums.end())
			nums.erase(firstIt + 1, nums.end());

		return nums.size();
	}

	//16 ms	10.4 MB
	int removeDuplicates2(vector<int>& nums) {
		if (nums.empty())return 0;
		int size = nums.size(), firstNum = nums[0];
		nums.push_back(firstNum);
		for (int i = 1; i < size;i++)
		{
			if (nums[i] != firstNum)
			{
				nums.push_back(nums[i]);
				firstNum = nums[i];
			}
		}
		nums.erase(nums.begin(), nums.begin() + size);
		return nums.size();
	}

	//32 ms	9.9 MB
	int removeDuplicates3(vector<int>& nums) {
		nums.erase(unique(nums.begin(), nums.end()), nums.end());
		return nums.size();
	}

	//16 ms	9.8 MB
	int removeDuplicates4(vector<int>& nums) {
		if (nums.empty())return 0;
		int index = 0;
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] > nums[index])
				nums[++index] = nums[i];
		}
		return index + 1;
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}