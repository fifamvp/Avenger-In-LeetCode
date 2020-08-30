#pragma once
#include <iostream>
#include <algorithm>
#include <queue>
#include <map>
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();
	void Solve()
	{
		printf("%d\n", numSquares2(48));
		printf("%d\n", numSquares2(914));
		printf("%d\n", numSquares2(15555));

	}
private:
	// 72 ms	22.4 MB
	int numSquares(int n) {
		queue<int> bfs({ n });
		int minNum = 0, numOfPreNodes = 1;
		while (true)
		{
			int num = bfs.front();
			bfs.pop();
			for (int i = floor(sqrt(num)); i > 0; i--)
			{
				int left = num - pow(i, 2);
				if (left == 0) 
					return ++minNum;
				else
					bfs.push(left);
			}
			if (--numOfPreNodes == 0)
			{
				minNum++;
				numOfPreNodes = bfs.size();
			}
		}
		return minNum;
	}

	// 256 ms	9 MB
	int numSquares2(int n) {
		vector<int> dp(n + 1, n);
		dp[0] = 0;
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= sqrt(i); j++)
			{
				if (dp[i] > dp[i - j * j] + 1)
					dp[i] = dp[i - j * j] + 1;
			}
		}
		return dp[n];
	}

	// 4 ms	6.2 MB
	// from leetcode, to save computing, leetcode will not clear your initialization in each testcase. that means, if you use static, your previous caching will be used by later case.
	int numSquares3(int n) {
		static vector<int> dp({ 0 });
		while (dp.size() <= n)
		{
			int i = dp.size(), cur = INT_MAX;
			for (int j = 1; j * j <= i; j++)
			{
				if (cur > dp[i - j * j] + 1)
					cur = dp[i - j * j] + 1;
			}
			dp.push_back(cur);
		}
		return dp[n];
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}
