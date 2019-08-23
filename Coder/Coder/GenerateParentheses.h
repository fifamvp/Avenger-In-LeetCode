#pragma once
#include <vector>
#include <string>
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();

	void Solve()
	{
		generateParenthesis(3);
	}

private:
	// official solution
	/*vector<string> generateParenthesis(int n) {
		vector<string> result;

		if (n == 0)
		{
			result.push_back("");
		}
		else
		{
			for (size_t i = 0; i < n; i++)
			{
				for (auto left : generateParenthesis(i))
				{
					for (auto right : generateParenthesis(n - 1 - i))
					{
						result.push_back("(" + left + ")" + right);
					}
				}
			}
		}

		return result;
	}*/

	vector<string> generateParenthesis(int n) {
		vector<string> result;

		addParens(result, "", n, n);

		return result;
	}

	void addParens(vector<string> &r, string s, int open, int close)
	{
		if (open == 0 && close == 0)
		{
			r.push_back(s);
		}
		else
		{
			if (open > 0)
				addParens(r, s + "(", open - 1, close);
			if (close > open)
				addParens(r, s + ")", open, close - 1);
		}
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}