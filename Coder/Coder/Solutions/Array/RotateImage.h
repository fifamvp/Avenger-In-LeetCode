#pragma once
#include <vector>
using namespace std;
#define S3 1
class Solution
{
public:
	Solution();
	~Solution();

private:
#if S1
	// 0 ms	7.1 MB
	void rotate(vector<vector<int>>& matrix) {
		rotateRecursion(matrix, 0, (int)matrix.size() - 1);
	}

	void rotateRecursion(vector<vector<int>>& matrix, int startPos, int maxPos)
	{
		if (startPos >= maxPos) return;
		for (int count = 1; count <= maxPos - startPos; count++)
		{
			int tmp = matrix[startPos][startPos];
			int i = startPos, j = startPos;
			// down
			for (; i < maxPos; i++)
			{
				matrix[i][j] = matrix[i + 1][j];
			}
			// right
			for (; j < maxPos; j++)
			{
				matrix[i][j] = matrix[i][j + 1];
			}
			// up
			for (; i > startPos; i--)
			{
				matrix[i][j] = matrix[i - 1][j];
			}
			// left
			for (; j > startPos; j--)
			{
				matrix[i][j] = matrix[i][j - 1];
			}
			matrix[startPos][startPos + 1] = tmp;
		}
		rotateRecursion(matrix, startPos + 1, maxPos - 1);
	}
#elif S2
	// 4 ms	7 MB
	void rotate(vector<vector<int>>& matrix) {
		for (int i = 0; i < matrix.size(); i++)
		{
			for (int j = 0; j < i; j++)
			{
				swap(matrix[i][j], matrix[j][i]);
			}
		}
		for (int i = 0; i < matrix.size(); i++)
		{
			std::reverse(matrix[i].begin(), matrix[i].end());
		}
	}
#elif S3
	// 4 ms	6.9 MB
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		int a = 0, b = n - 1;
		while (a < b)
		{
			for (int i = 0; i < (b - a); i++)
			{
				swap(matrix[a][a + i], matrix[a + i][b]);
				swap(matrix[a][a + i], matrix[b][b - i]);
				swap(matrix[a][a + i], matrix[b - i][a]);
			}
			a++;
			b--;
		}
	}
#endif
};

Solution::Solution()
{
}

Solution::~Solution()
{
}