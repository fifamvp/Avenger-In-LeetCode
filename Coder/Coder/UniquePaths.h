#pragma once
#include <iostream>
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();

	void Solve()
	{
		printf("%d\n", uniquePaths(3, 2));
		printf("%d\n", uniquePaths(7, 3));
		printf("%d\n", uniquePaths(5, 100));

	}

private:
	// 0 ms	6.4 MB
	int *arr;
	int uniquePaths(int m, int n) {
		arr = (int *)malloc(m * n * sizeof(int));
		for (int i = 0; i < m; i++)
			for (int j = 0; j < n; j++)
				*(arr + i * n + j) = 0;
		/*int** p = new int*[m];
		for (int i = 0; i < n; i++)
			p[i] = new int[n];*/
		
		return go(m, n, 0, 0);
	}

	int go(int m, int n, int i, int j)
	{
		if (*(arr + i * n + j) == 0)
		{
			if (i == m - 1 || j == n - 1)
				*(arr + i * n + j) = 1;
			else
				*(arr + i * n + j) = go(m, n, i + 1, j) + go(m, n, i, j + 1);
		}

		return *(arr + i * n + j);
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}