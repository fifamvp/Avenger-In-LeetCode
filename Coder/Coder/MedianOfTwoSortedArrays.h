#pragma once
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

class MedianOfTwoSortedArrays
{
public:
	MedianOfTwoSortedArrays();
	~MedianOfTwoSortedArrays();
	void Solve() {
		vector<int> nums1 = { 1, 3 };
		vector<int> nums2 = { 2 };
		cout << findMedianSortedArrays(nums1, nums2) << endl;
	}

private:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		float index = (float)(nums1.size() + nums2.size() - 1) / 2;

		int i = 0, j = 0;
		vector<int> r;

		while (i < nums1.size() || j < nums2.size())
		{
			if (i >= nums1.size()) {
				while (j < nums2.size())
				{
					r.push_back(nums2[j]);
					j++;
				}
				break;
			}
			if (j >= nums2.size()) {
				while (i < nums1.size())
				{
					r.push_back(nums1[i]);
					i++;
				}
				break;
			}

			if (nums1[i] < nums2[j]) {
				r.push_back(nums1[i]);
				i++;
			}
			else if (nums1[i] > nums2[j])
			{
				r.push_back(nums2[j]);
				j++;
			}
			else
			{
				r.push_back(nums1[i]);
				r.push_back(nums2[j]);
				i++;
				j++;
			}
		}

		return double(r[floor(index)] + r[ceil(index)]) / 2;
	}
};

MedianOfTwoSortedArrays::MedianOfTwoSortedArrays()
{
}

MedianOfTwoSortedArrays::~MedianOfTwoSortedArrays()
{
}