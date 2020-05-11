#pragma once
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();

	void Solve()
	{
		vector<int> prices = { 7,1,5,3,6,4 };
		prices = { 7,6,5,4,3 };
		//prices = { 7,1,5,3,6,4,4564,53132,6,13,13,3,16 };
		//prices = { 2,4,1,7 };
		//prices = { 2,7 };
		//prices = { 4,7,1,2,11 };
		//prices = { 4,7,2,11,1 };

		printf("%d\n", maxProfit2(prices));

		for (int i = 19999; i > 0; i--) {
			printf("%d,", i);
		}
	}

private:
	// if current number is less than the next, just skip current one

	// 24 ms	13.1 MB
	int maxProfit(vector<int>& prices) {
		int p = 0;
		for (int i = 0; i < prices.size(); i++)
		{
			if (i + 1 < prices.size() && prices[i] >= prices[i + 1]) continue;
			int maxIdx = i, firstLessIdx = i;
			for (int j = i + 1; j < prices.size(); j++)
			{
				if (prices[j] - prices[i] > p)
				{
					p = prices[j] - prices[i];
					maxIdx = j;
				}
				if (firstLessIdx == i && prices[j] < prices[firstLessIdx])
				{
					firstLessIdx = j;
				}
			}
			i = i < firstLessIdx && firstLessIdx < maxIdx ? firstLessIdx - 1 : maxIdx;
		}
		return p;
	}

	// change to MaximumSubarray by taking advantage of the difference between the number and the next
	// 12 ms	13.5 MB
	int maxProfit2(vector<int>& prices) {
		if (prices.size() < 2) return 0;
		vector<int> diff;
		for (int i = 0; i + 1 < prices.size(); i++)
			diff.push_back(prices[i + 1] - prices[i]);
		int maxProfit = diff[0], s = diff[0];
		for (int i = 1; i < diff.size(); i++)
		{
			if (s >= 0)
				s += diff[i];
			else
				s = diff[i];
			maxProfit = max(maxProfit, s);
		}
		return max(maxProfit, 0);
	}

	// profit gained on this day (current price - minimum price before)
	// 12 ms	13.1 MB
	int maxProfit3(vector<int>& prices) {
		int minValue = INT32_MAX, maxProfit = 0;
		for (int i = 0; i < prices.size(); i++)
		{
			if (prices[i] < minValue)
				minValue = prices[i];
			else if (prices[i] - minValue > maxProfit)
				maxProfit = prices[i] - minValue;
		}
		return maxProfit;
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}