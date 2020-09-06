#pragma once
#include <vector>
#include <algorithm>
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();
	void Solve()
	{
		vector<int> coins = { 1, 2, 5 };
		int amount = 11;

		coins = { 2, 5, 6 };
		amount = 21;

		coins = { 206, 280, 362, 59, 486, 27, 177, 437, 329 };
		amount = 7621;
		printf("%d\n", coinChange(coins, amount));
	}
private:
	// 132 ms	20.6 MB	
	int coinChange2(vector<int>& coins, int amount) {
		if (amount == 0) return 0;
		vector<int> result = { 0 };
		for (int i = 1; i <= amount; i++)
		{
			result.push_back(-1);
			for (int j = 0; j < coins.size(); j++)
			{
				if (i >= coins[j] && result[i - coins[j]] != -1)
				{
					if (result[i] == -1 || result[i] > result[i - coins[j]] + 1)
						result[i] = result[i - coins[j]] + 1;
				}
			}
		}
		return result[amount];
	}

	// 104 ms	20.6 MB
	int coinChange3(vector<int>& coins, int amount) {
		if (amount == 0) return 0;
		vector<int> result(amount + 1, INT_MAX);
		for (int i = 1; i <= amount; i++)
		{
			for (int j = 0; j < coins.size(); j++)
			{
				if (i >= coins[j] && result[i] - 1 > result[i - coins[j]])
				{
					result[i] = result[i - coins[j]] + 1;
				}
			}
		}
		return result[amount] == INT_MAX ? -1 : result[amount];
	}

	// 76 ms 	14 MB
	// There is a problem when amount is INT_MAX
	int coinChange(vector<int>& coins, int amount) {
		if (amount == 0) return 0;
		vector<int> result(amount + 1, INT_MAX);
		result[0] = 0;
		for (int i = 1; i <= amount; i++)
		{
			for (int j = 0; j < coins.size(); j++)
			{
				if (i >= coins[j] && result[i] - 1 > result[i - coins[j]])
				{
					result[i] = result[i - coins[j]] + 1;
				}
			}
		}
		return result[amount] == INT_MAX ? -1 : result[amount];
	}

	int coinChange4(vector<int>& coins, int amount) {
		if (amount == 0) return 0;
		vector<double> result(amount + 1, INT_MAX);
		result[0] = 0;
		for (int i = 1; i <= amount; i++)
		{
			for (int j = 0; j < coins.size(); j++)
			{
				if (i >= coins[j] && result[i] - 1 > result[i - coins[j]])
				{
					result[i] = result[i - coins[j]] + 1;
				}
			}
		}
		return (int)result[amount] == INT_MAX ? -1 : (int)result[amount];
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}