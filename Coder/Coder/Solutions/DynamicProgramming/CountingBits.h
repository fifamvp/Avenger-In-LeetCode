#pragma once
#include <vector>
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();

	void Solve()
	{
		int jj = 2 & 1;
		countBits(2);
	}

private:
	// 4 ms	7.6 MB
	vector<int> countBits(int num) {
		vector<int> result(num + 1, 0);
		int p = 0;
		for (int i = 1; i <= num; i++)
		{
			if ((i & (i - 1)) == 0)
			{
				p = 0;
			}
			result[i] = (result[p++] + 1);
		}
		return result;
	}

	// 4 ms	7.8 MB
	vector<int> countBits2(int num) {
		vector<int> result(num + 1, 0);
		for (int i = 1; i <= num; i++)
		{
			result[i] = (result[i >> 1] + i & 1);
		}
		return result;
	}

	// 4 ms	7.8 MB
	vector<int> countBits3(int num) {
		vector<int> result(num + 1, 0);
		for (int i = 1; i <= num; ++i)
			result[i] = result[i & (i - 1)] + 1;
		return result;
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}