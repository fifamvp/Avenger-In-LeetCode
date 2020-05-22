#pragma once
#include <vector>
#include <stack>
#include <set>
#include <queue>
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();
	void Solve()
	{
		vector<string> wordDict = { "leet", "code" };
		string s = "leetcode";
		wordDict = { "apple", "pen" };
		s = "applepenapple";
		//wordDict = { "cats", "dog", "sand", "and", "cat" };
		//s = "catsandog";
		//s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab";
		//wordDict = { "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa" };
		s = "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaabaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
		wordDict = { "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa" };
		//s = "goalspecial";
		//wordDict = { "go", "goal", "goals", "special" };
		//s = "aaabaaaaaa";
		//wordDict = { "a", "aa", "aaa" };
		printf("%d\n", wordBreak4(s, wordDict));
	}

private:
	// 44 ms	13 MB
	bool wordBreak(string s, vector<string>& wordDict) {
		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;
		for (int i = 0; i < s.size(); i++)
		{
			for (int j = i; dp[i] && j < s.size(); j++)
			{
				string t = s.substr(i, j - i + 1);
				if (find(wordDict.begin(), wordDict.end(), t) != wordDict.end())
					dp[j + 1] = true;
			}
		}
		return dp[s.size()];
	}

	// 32 ms	13 MB
	bool wordBreak2(string s, vector<string>& wordDict) {
		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;
		for (int i = 0; i < s.size(); i++)
		{
			for (int j = i; dp[i] && j < s.size(); j++)
			{
				string t = s.substr(i, j - i + 1);
				if (find(wordDict.begin(), wordDict.end(), t) != wordDict.end())
					dp[j + 1] = true;
			}
			if (dp[s.size()])
				return true;
		}
		return dp[s.size()];
	}

	// 4 ms	7.3 MB
	bool wordBreak3(string s, vector<string>& wordDict) {
		int minLen = INT_MAX, maxLen = INT_MIN;
		for (auto &e : wordDict)
		{
			if (minLen > (int)e.size())
				minLen = e.size();
			if (maxLen < (int)e.size())
				maxLen = e.size();
		}

		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;
		for (int i = 0; i + minLen - 1 < s.size(); i++)
		{
			for (int j = i + minLen - 1; dp[i] && j < i + maxLen; j++)
			{
				string t = s.substr(i, j - i + 1);
				if (find(wordDict.begin(), wordDict.end(), t) != wordDict.end())
					dp[j + 1] = true;
			}
			if (dp[s.size()])
				return true;
		}
		return dp[s.size()];
	}

	// 4 ms	7.3 MB
	bool wordBreak4(string s, vector<string>& wordDict) {
		int minLen = INT_MAX, maxLen = INT_MIN;
		for (auto &e : wordDict)
		{
			if (minLen > (int)e.size())
				minLen = e.size();
			if (maxLen < (int)e.size())
				maxLen = e.size();
		}

		vector<bool> dp(s.size() + 1, false);
		dp[0] = true;
		for (int i = minLen - 1; i < s.size(); i++)
		{
			for (int j = i - minLen + 1; j >= i - maxLen + 1 && j >= 0; j--)
			{
				if (dp[j])
				{
					string t = s.substr(j, i - j + 1);
					if (find(wordDict.begin(), wordDict.end(), t) != wordDict.end())
					{
						dp[i + 1] = true;
						break;
					}
				}
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