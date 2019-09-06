#pragma once
#include <vector>
using namespace std;
class SearchInRotatedSortedArray
{
public:
	SearchInRotatedSortedArray();
	~SearchInRotatedSortedArray();

private:
	//4 ms	8.6 MB
	int search(vector<int>& nums, int target) {
		int i = 0, j = nums.size() - 1, m;
		while (i <= j)
		{
			if (nums[i] == target)return i;
			if (nums[j] == target)return j;
			m = (i + j) / 2;
			if (nums[m] == target)return m;

			if (nums[m] > target && nums[i] < target)
				j = m - 1;
			else if (nums[m] < target && nums[j] > target)
				i = m + 1;
			else if (nums[m] < target && nums[j] < target) {
				if (nums[m] > nums[j])
					i = m + 1;
				else
					j = m - 1;
			}
			else if (nums[m] > target && nums[i] > target) {
				if (nums[m] > nums[i])
					i = m + 1;
				else
					j = m - 1;
			}
		}
		return -1;
	}

	//4 ms	8.8 MB
	int search2m(vector<int>& nums, int target) {
		int i = 0, j = nums.size() - 1, m;
		while (i <= j)
		{
			m = (i + j) / 2;
			if (nums[m] < target) {
				if (nums[i] > nums[m] && nums[j] < target)
					j = m - 1;
				else
					i = m + 1;
			}
			else if (nums[m] > target){
				if (nums[m] > nums[j] && nums[i] > target)
					i = m + 1;
				else
					j = m - 1;
			}
			else {
				return m;
			}
		}
		return -1;
	}

	//4 ms	8.8 MB
	int search2(vector<int>& nums, int target) {
		if (nums.empty())return -1;
		int i = 0, j = nums.size() - 1, m;
		if (nums[i] > nums[j]) {
			while (i < j)
			{
				m = (i + j) / 2;
				if (nums[m] > nums[j])
					i = m + 1;
				else
					j = m;
			}
		}
		int n = nums.size(), rot = i;
		i = 0;
		j = n - 1;
		while (i <= j)
		{
			m = (i + j) / 2;
			int real = (rot + m) % n;
			if (nums[real] == target)
				return real;
			if (nums[real] >= target)
				j = m - 1;
			else
				i = m + 1;
		}
		return -1;
	}
};

SearchInRotatedSortedArray::SearchInRotatedSortedArray()
{
}

SearchInRotatedSortedArray::~SearchInRotatedSortedArray()
{
}