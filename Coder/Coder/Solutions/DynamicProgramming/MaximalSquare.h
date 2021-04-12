#pragma once
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();

private:
	// 32 ms	11.9 MB
	int maximalSquare(vector<vector<char>>& matrix) {
		if (matrix.empty())return 0;
		int ans = 0, m = matrix.size(), n = matrix[0].size();

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
					int squareWidth = min(width, height);
					ans = max(ans, squareWidth * squareWidth);
				}
			}
		}

		return ans;
	}

	// 24 ms	11.8 MB
	int maximalSquare2(vector<vector<char>>& matrix) {
		if (matrix.empty()) return 0;
		int maxWidth = 0, m = matrix.size(), n = matrix[0].size();
		vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				if (matrix[i - 1][j - 1] == '1') {
					dp[i][j] = min(dp[i - 1][j - 1], min(dp[i][j - 1], dp[i - 1][j])) + 1;
					maxWidth = max(maxWidth, dp[i][j]);
				}
			}
		}
		return maxWidth * maxWidth;
	}

	// 24 ms	11.1 MB
	int maximalSquare2_1(vector<vector<char>>& matrix) {
		if (matrix.empty()) return 0;
		int maxWidth = 0, m = matrix.size(), n = matrix[0].size(), pre = 0;
		vector<int> dp(n + 1, 0);
		for (int i = 1; i <= m; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				int temp = dp[j];
				if (matrix[i - 1][j - 1] == '1') {
					dp[j] = min(pre, min(dp[j - 1], dp[j])) + 1;
					maxWidth = max(maxWidth, dp[j]);
				}
				else
				{
					dp[j] = 0;
				}
				pre = temp;
			}
		}
		return maxWidth * maxWidth;
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}