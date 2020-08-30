#pragma once
#include <iostream>
#include <algorithm>
#include <vector>
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

	// 0 ms	6.3 MB
	int uniquePaths3(int m, int n) {
		vector<int> column(n, 1);
		for (int i = 1; i < m; i++) {
			for (int j = 1; j < n; j++) {
				column[j] += column[j - 1];
			}
		}
		return column[n - 1];
	}
	
	// Math, Composition(m+n-2,n-1)
	// 0 ms	5.9 MB
	int uniquePaths2(int m, int n) {
		int A = m + n - 2, B = std::min(m - 1, n - 1);
		long long result = 1;
		for (int i = 1; i <= B; ++i)
			result = result * A-- / i;
		return static_cast<int>(result);
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}