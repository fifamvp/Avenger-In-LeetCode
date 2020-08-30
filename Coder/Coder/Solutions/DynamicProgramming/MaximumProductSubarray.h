#pragma once
#include <vector>
//#include <algorithm>
using namespace std;
class Solution
{
#define max(a, b) ((a)>(b)?(a):(b))
#define min(a, b) ((a)<(b)?(a):(b))
public:
	Solution();
	~Solution();

	void Solve()
	{
		// aws:59400,6,0,0,30,500
		vector<int> nums = { -3,5,-2,6,-15,2,-3,-11 };
		//nums = { 2,3,-2,4 };
		nums = { -2,0,-1 };
		//nums = { 0 };
		//[15,0,-3,5,-2]
		nums = { -2,15,0,-3,5,-5,-20 };
		nums = { 2,-5,-2,-4,3 };

		printf("%d\n", maxProduct(nums));
		
	}
private:
	// 8 ms	12 MB
	// 4 ms	11.8 MB use max macro
	// if number is 0, reset the counter
	// firstNegativeProduct means the product from con to the first negative number
	int maxProduct2(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int preMax = nums[0], con = nums[0];
		int firstNegativeProduct = nums[0] < 0 ? nums[0] : 0;
		for (int i = 1; i < nums.size(); i++)
		{
			preMax = max(max(preMax, nums[i]), con * nums[i]);
			if (con * nums[i] < 0 && firstNegativeProduct != 0)
				preMax = max(preMax, con * nums[i] / firstNegativeProduct);

			if (nums[i] == 0)
			{
				con = 0;
				firstNegativeProduct = 0;
			}
			else
			{
				con = con == 0 ? nums[i] : con * nums[i];
				if (firstNegativeProduct == 0 && nums[i] < 0)
					firstNegativeProduct = con;
			}
		}
		return preMax;
	}

	int maxProduct3(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int preMax = nums[0], con = nums[0];
		int firstNegativeProduct = nums[0] < 0 ? nums[0] : 0;
		for (int i = 1; i < nums.size(); i++)
		{
			if (nums[i] == 0)
			{
				preMax = max(preMax, nums[i]);
				con = 0;
				firstNegativeProduct = 0;
			}
			else
			{
				con = con == 0 ? nums[i] : con * nums[i];

				preMax = max(max(preMax, nums[i]), con);
				if (con < 0 && firstNegativeProduct != 0)
					preMax = max(preMax, con / firstNegativeProduct);

				if (firstNegativeProduct == 0 && nums[i] < 0)
					firstNegativeProduct = con;
			}
		}
		return preMax;
	}

	// 4 ms	11.8 MB
	int maxProduct4(vector<int>& nums)
	{
		if (nums.size() == 0) return 0;
		int result = nums[0];
		for (int i = 1, preMin = result, preMax = result; i < nums.size(); i++)
		{
			if (nums[i] < 0)
				swap(preMax, preMin);
			preMax = max(nums[i], preMax * nums[i]);
			preMin = min(nums[i], preMin * nums[i]);
			result = max(result, preMax);
		}
		return result;
	}

	// 4 ms	11.7 MB
	int maxProduct(vector<int>& nums) {
		if (nums.size() == 0) return 0;
		int result = nums[0];
		for (int i = 1, preMin = result, preMax = result; i < nums.size(); i++)
		{
			int pMax = preMax * nums[i], pMin = preMin * nums[i];
			preMax = max(nums[i], max(pMax, pMin));
			preMin = min(nums[i], min(pMax, pMin));
			result = max(result, preMax);
		}
		return result;
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}