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
	// 4 ms	9 MB
	void moveZeroes(vector<int>& nums) {
		int i = 0, j = 1;
		while (j < nums.size())
		{
			if (nums[j] == 0)
				j++;
			else if (nums[i] != 0)
			{
				i++;
				if (i >= j)
					j = i + 1;
			}
			else if (nums[i] == 0 && nums[j] != 0)
				swap(nums[i], nums[j]);
		}
	}
#elif S2
	void moveZeroes(vector<int>& nums) {
		int j = 0;
		// move all the nonzero elements advance
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] != 0) {
				nums[j++] = nums[i];
			}
		}
		for (; j < nums.size(); j++) {
			nums[j] = 0;
		}
	}
#elif S2_1
	void moveZeroes(vector<int>& nums) {
		for (int lastNonZeroFoundAt = 0, cur = 0; cur < nums.size(); cur++) {
			if (nums[cur] != 0) {
				swap(nums[lastNonZeroFoundAt++], nums[cur]);
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