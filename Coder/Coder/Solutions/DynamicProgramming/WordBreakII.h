#pragma once
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();

	void Solve()
	{
		string s = "catsanddog";
		vector<string> wordDict = { "cat", "cats", "and", "sand", "dog" };
		wordBreak(s, wordDict);

	}

private:
	unordered_map<string, vector<string>> m;
	// 28 ms		11.8 MB
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		if (m.find(s) != m.end())return m[s];
		vector<string> result;
		if (find(wordDict.begin(), wordDict.end(), s) != wordDict.end())
			result.push_back(s);
		for (int i = 1; i < s.size(); i++)
		{
			string word = s.substr(i);
			if (find(wordDict.begin(), wordDict.end(), word) != wordDict.end())
			{
				vector<string> pre = wordBreak(s.substr(0, i), wordDict);
				for (int j = 0; j < pre.size(); j++)
				{
					pre[j] += " " + word;
				}
				result.insert(result.end(), pre.begin(), pre.end());
			}
		}
		m[s] = result;
		return result;
	}

	// 124 ms	13.6 MB
	vector<string> wordBreak2(string s, vector<string>& wordDict) {
		if (m.find(s) != m.end())return m[s];
		vector<string> result;
		if (find(wordDict.begin(), wordDict.end(), s) != wordDict.end())
			result.push_back(s);
		for (int i = 1; i < s.size(); i++)
		{
			string word = s.substr(0, i);
			if (find(wordDict.begin(), wordDict.end(), word) != wordDict.end())
			{
				vector<string> next = wordBreak2(s.substr(i), wordDict);
				for (int j = 0; j < next.size(); j++)
				{
					next[j] = word + " " + next[j];
				}
				result.insert(result.end(), next.begin(), next.end());
			}
		}
		m[s] = result;
		return result;
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}