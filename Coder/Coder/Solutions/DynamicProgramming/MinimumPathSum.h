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
	// 16 ms		10.3 MB
	int minPathSum(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid.front().size();
		int** r = new int*[m];
		for (int i = 0; i < m; i++)
		{
			r[i] = new int[n];
			memset(r[i], 100, n);
		}
		r[0][0] = grid[0][0];
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (i == 0 && j > 0)
				{
					r[i][j] = r[i][j - 1] + grid[i][j];
				}
				else if (i > 0 && j == 0)
				{
					r[i][j] = r[i - 1][j] + grid[i][j];
				}
				else if (i > 0 && j > 0)
				{
					r[i][j] = min(r[i][j - 1] + grid[i][j], r[i - 1][j] + grid[i][j]);
				}
			}
		}

		return r[m - 1][n - 1];
	}

	// 16 ms		9.9 MB
	int minPathSum2(vector<vector<int>>& grid) {
		int m = grid.size(), n = grid[0].size();
		vector<int> cur(m, grid[0][0]);
		for (int i = 1; i < m; i++)
			cur[i] = cur[i - 1] + grid[i][0];
		for (int j = 1; j < n; j++)
		{
			cur[0] += grid[0][j];
			for (int i = 1; i < m; i++)
			{
				cur[i] = min(cur[i], cur[i - 1]) + grid[i][j];
			}
		}
		return cur[m - 1];
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}