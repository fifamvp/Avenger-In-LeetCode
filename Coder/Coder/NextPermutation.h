#pragma once
#include <vector>
#include <algorithm>
using namespace std;
class NextPermutation
{
public:
	NextPermutation();
	~NextPermutation();

private:
	void nextPermutation(vector<int>& nums) {
		int minIdx = nums.size() - 1, sortIdx = 0;
		for (int i = nums.size() - 1; i >= 1; i--) {
			if (nums[i] > nums[i - 1]) {
				while (nums[minIdx] <= nums[i - 1])
					minIdx--;
				swap(nums[minIdx], nums[i - 1]);
				sortIdx = i;
				break;
			}
		}
		sort(nums.begin() + sortIdx, nums.end());
	}
};

NextPermutation::NextPermutation()
{
}

NextPermutation::~NextPermutation()
{
}