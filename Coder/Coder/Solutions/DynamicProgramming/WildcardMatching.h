#pragma once
#include <string>
#include <vector>
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();
	void Solve()
	{
		printf("%d\n", isMatch("", "**"));
		printf("%d\n", isMatch("aa", "*"));

	}
private:
	// 224 ms 11.1 MB
	bool isMatch(string s, string p) {
		vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
		dp[0][0] = true;
		for (int i = 0; i <= s.size(); i++)
		{
			for (int j = 1; j <= p.size(); j++)
			{
				if (p[j - 1] == '*')
				{
					dp[i][j] = dp[i][j - 1] || i && dp[i - 1][j];
				}
				else
				{
					dp[i][j] = i && dp[i - 1][j - 1] && (p[j - 1] == '?' || s[i - 1] == p[j - 1]);
				}
			}
		}
		return dp[s.size()][p.size()];
	}

	// 220 ms	11.1 MB
	bool isMatch2(string s, string p) {
		vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));
		dp[0][0] = true;
		for (int j = 1; j <= p.size(); j++)
		{
			dp[0][j] = dp[0][j - 1] && p[j - 1] == '*';
			for (int i = 1; i <= s.size(); i++)
			{
				if (p[j - 1] == '*')
				{
					dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
				}
				else
				{
					dp[i][j] = dp[i - 1][j - 1] && (p[j - 1] == '?' || s[i - 1] == p[j - 1]);
				}
			}
		}
		return dp[s.size()][p.size()];
	}

	// 180 ms	6.6 MB
	bool isMatch3(string s, string p) {
		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;
		for (int j = 1; j <= p.size(); j++)
		{
			bool pre = dp[0]; // record dp[i-1][j-1]
			dp[0] = dp[0] && p[j - 1] == '*';
			for (int i = 1; i <= s.size(); i++)
			{
				bool temp = dp[i];
				if (p[j - 1] == '*')
				{
					dp[i] = dp[i] || dp[i - 1];
				}
				else
				{
					dp[i] = pre && (p[j - 1] == '?' || s[i - 1] == p[j - 1]);
				}
				pre = temp;
			}
		}
		return dp[s.size()];
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}