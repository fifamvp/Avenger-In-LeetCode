#pragma once
#include <vector>
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();

private:
	// 0 ms	6 MB
	// Actrually it's a DP question.
	int numTrees(int n) {
		vector<int> result(n + 1);
		result[0] = 1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j <= i - 1; j++)
			{
				result[i] += result[i - 1 - j] * result[j];
			}
		}
		return result[n];
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}