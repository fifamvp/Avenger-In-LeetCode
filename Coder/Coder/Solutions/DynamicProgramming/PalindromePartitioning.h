#pragma once
#include <vector>
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();

	void	 Solve()
	{
		partition("aba");
		partition("ffff");
	}
private:
	bool isPalindrome(string& s)
	{
		for (size_t i = 0; i < s.length() / 2; i++)
		{
			if (s[i] != s[s.length() - 1 - i]) {
				return false;
			}
		}
		return true;
	}

	// 312 ms	126.2 MB
	vector<vector<string>> partition(string s) {
		vector<vector<string>> result;
		for (int i = 0; i < s.length(); i++)
		{
			vector<vector<string>> r;
			string cur = s.substr(i, 1);
			vector<string> tmp;
			if (result.empty())
			{
				tmp.push_back(cur);
				r.push_back(tmp);
			}
			else
			{
				for (int j = 0; j < result.size(); j++)
				{
					tmp = result[j];
					tmp.push_back(cur);
					r.push_back(tmp);

					int num = (int)result[j].size();
					bool hasConcatLast = false;
					if (num > 0)
					{
						string concatStr = result[j].back() + cur;
						if (isPalindrome(concatStr))
						{
							tmp = result[j];
							tmp[num - 1] = concatStr;
							r.push_back(tmp);
							hasConcatLast = true;
						}
					}

					if (!hasConcatLast && num > 1)
					{
						if (result[j][num - 2] == cur)
						{
							result[j][num - 2] = result[j][num - 2] + result[j].back() + cur;
							result[j].pop_back();
							r.push_back(result[j]);
						}
					}
				}
			}

			result = r;
		}
		return result;
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}