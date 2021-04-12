#pragma once
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();
	// [["0","0","0"],["0","0","0"],["1","1","1"]]
	// [["1","0","1","1","0","1"],["1","1","1","1","1","1"],["0","1","1","0","1","1"],["1","1","1","0","1","0"],["0","1","1","1","1","1"],["1","1","0","1","1","1"]]

private:
	// 28 ms	11.5 MB
	int maximalRectangle(vector<vector<char>>& matrix) {
		if (matrix.empty())return 0;
		int r = 0, m = matrix.size(), n = matrix[0].size();

		vector<vector<int>> dp(m, vector<int>(n, 0));
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				dp[i][j] = (matrix[i][j] == '1') ? (j == 0 ? 1 : dp[i][j - 1] + 1) : 0;
			}
		}

		for (int j = 0; j < n; j++)
		{
			for (int i = 0; i < m; i++)
			{
				int width = dp[i][j];
				int height = 0;
				for (int k = i; k < m; k++)
				{
					if (dp[k][j] == 0) break;
					if (dp[k][j] < width)
					{
						width = dp[k][j];
					}
					height++;
					r = max(r, width * height);
				}
			}
		}

		return r;
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}