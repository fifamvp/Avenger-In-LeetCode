#pragma once
#include <unordered_map>
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();

	void Solve()
	{
		Test(1);
		Test(2);
		Test(3);
		Test(16);
		Test(45);
	}

private:
	void Test(int n)
	{
		printf("stairs %d : %d ways\n", n, climbStairs2(n));
	}

	unordered_map<int, int> stairs;
	int climbStairs(int n) {
		stairs[1] = 1;
		stairs[2] = 2;

		return cal(n);
	}

	int cal(int n)
	{
		if (stairs.find(n) != stairs.end())
			return stairs[n];
		stairs[n] = cal(n - 1) + cal(n - 2);
		return stairs[n];
	}

	// Fibonacci, n > 0
	int climbStairs2(int n)
	{
		if (n == 1 || n == 2) return n;
		int a = 1, b = 2;
		for (int i = 3; i <= n; i++)
		{
			b = a + b;
			a = b - a;
		}
		return b;
	}

};

Solution::Solution()
{
}

Solution::~Solution()
{
}