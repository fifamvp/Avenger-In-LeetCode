#pragma once
#include<string>
#include<vector>
using namespace std;
class RegularExpressionMatching
{
	//* means 0 - N, misunderstanding again!!!!
public:
	RegularExpressionMatching();
	~RegularExpressionMatching();
	void Solve()
	{
		printf("%d\n", isMatch("aa", "a"));
		printf("%d\n", isMatch("aa", "a*"));
		printf("%d\n", isMatch("ab", ".*"));
		printf("%d\n", isMatch("aab", "c*a*b"));
		printf("%d\n", isMatch("mississippi", "mis*is*p*."));
		printf("%d\n", isMatch("", "a*"));
		printf("%d\n", isMatch("aa", ""));
		printf("%d\n", isMatch("aaa", "ab*a*c*a"));
		printf("%d\n", isMatch("aaa", "ab*a*c*a*"));
		//
		printf("%d\n", isMatch("a", "a*a"));
		printf("%d\n", isMatch("aa", "a*a"));
		printf("%d\n", isMatch("aaa", "a*"));
	}

private:
	//Recursion
	/*bool isMatch(string s, string p)
	{
		if (p.empty())return s.empty();

		bool isFirstMatch = !s.empty() && (s[0] == p[0] || p[0] == '.');

		if (p.size() > 1 && p[1] == '*')
		{
			return isMatch(s, p.substr(2)) || isFirstMatch && isMatch(s.substr(1), p);
		}
		else
		{
			return isFirstMatch && isMatch(s.substr(1), p.substr(1));
		}
	}*/

	// DP
	/*bool isMatch(string s, string p)
	{
		if (p.empty())return s.empty();

		result = new int*[s.size() + 1];
		for (size_t i = 0; i < s.size() + 1; i++)
		{
			result[i] = new int[p.size() + 1];
			memset(result[i], -1, (p.size() + 1) * sizeof(int));
		}

		return letsDP(0, 0, s, p);
	}

	int** result;

	bool letsDP(int i, int j, string s, string p)
	{
		if (result[i][j] != -1)
		{
			return result[i][j] == 1;
		}

		bool r;
		if (j == p.size())
			r = i == s.size();
		else
		{
			bool isFirstMatch = s.size() > i && (s[i] == p[j] || p[j] == '.');

			if (p.size() > j + 1 && p[j + 1] == '*')
			{
				r = letsDP(i, j + 2, s, p) || isFirstMatch && letsDP(i + 1, j, s, p);
			}
			else
			{
				r = isFirstMatch && letsDP(i + 1, j + 1, s, p);
			}
		}
		result[i][j] = r;
		return r;
	}*/


	bool isMatch(string s, string p)
	{
		if (p.empty())return s.empty();

		vector<vector<bool>> dp(s.size() + 1, vector<bool>(p.size() + 1, false));

		dp[0][0] = true;
		for (size_t i = 0; i <= s.size(); i++)
		{
			for (size_t j = 1; j <= p.size(); j++)
			{
				if (p[j - 1] == '*')
				{
					dp[i][j] = dp[i][j - 2] || i && dp[i - 1][j] && j >= 2 && (s[i - 1] == p[j - 2] || p[j - 2] == '.') ;
				}
				else
				{
					dp[i][j] = i && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');
				}
			}
		}

		return dp[s.size()][p.size()];
	}
};

 RegularExpressionMatching:: RegularExpressionMatching()
{
}

 RegularExpressionMatching::~ RegularExpressionMatching()
{
}