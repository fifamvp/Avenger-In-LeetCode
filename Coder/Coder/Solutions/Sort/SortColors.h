#pragma once
#include <vector>
using namespace std;
#define S2_2 1
class Solution
{
public:
	Solution();
	~Solution();

private:
#if S1
	// 4 ms	8.1 MB
	void sortColors(vector<int>& nums) {
		int red = 0, white = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] == 0) {
				red++;
			}
			else if (nums[i] == 1) {
				white++;
			}
		}
		for (int i = 0; i < nums.size(); i++)
		{
			if (i < red) {
				nums[i] = 0;
			}
			else if (i - red < white)
			{
				nums[i] = 1;
			}
			else
			{
				nums[i] = 2;
			}
		}
	}
#elif S2
	// 0 ms	8.2 MB
	void sortColors(vector<int>& nums) {
		int i = 0, j = nums.size() - 1;
		while (i < j)
		{
			if (nums[i] != 0) {
				swap(nums[i], nums[j--]);
			}
			else
			{
				i++;
			}
		}
		if (nums[i] == 0) i++;
		j = nums.size() - 1;
		while (i < j)
		{
			if (nums[i] != 1) {
				swap(nums[i], nums[j--]);
			}
			else
			{
				i++;
			}
		}
	}
#elif S2_2
	// 0 ms	8.3 MB
	void sortColors(vector<int>& nums) {
		auto mysort = [&](int& i, int target) {
			int j = nums.size() - 1;
			while (i < j)
			{
				if (nums[i] != target) {
					swap(nums[i], nums[j--]);
				}
				else
				{
					i++;
				}
			}
		};
		int i = 0;
		mysort(i, 0);
		if (nums[i] == 0) i++;
		mysort(i, 1);
	}
#elif S2
	// 0 ms	8.3 MB
	void sortColors(vector<int>& nums) {
		int r = 0, w = 0, b = 0; // label the end of different colors;
		for (int num : nums) {
			if (num == 0) {
				nums[b++] = 2;
				nums[w++] = 1;
				nums[r++] = 0;
			}
			else if (num == 1) {
				nums[b++] = 2;
				nums[w++] = 1;
			}
			else if (num == 2) {
				nums[b++] = 2;
			}
		}
	}

#elif S3
	void sortColors(vector<int>& nums) {
		int n = nums.size();
		int p0 = 0, p2 = n - 1;
		for (int i = 0; i <= p2; ++i) {
			while (i <= p2 && nums[i] == 2) {
				swap(nums[i], nums[p2]);
				--p2;
			}
			if (nums[i] == 0) {
				swap(nums[i], nums[p0]);
				++p0;
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