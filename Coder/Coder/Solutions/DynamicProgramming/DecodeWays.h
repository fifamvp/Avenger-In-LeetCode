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
		// ans:2,0,3,1,0
		printf("%d\n", numDecodings("12"));
		printf("%d\n", numDecodings("30"));
		printf("%d\n", numDecodings("12659"));
		printf("%d\n", numDecodings("20"));
		printf("%d\n", numDecodings("0"));

	}

private:
	// 0 ms	6.5 MB
	// F(n) = F(n - 1) + F(n - 2)
	// F(n - 1) means current number can be alone
	// F(n - 2) means current number can be combined with the previous one
	int numDecodings2(string s) {
		vector<int> arr;
		arr.push_back(s[0] - '0' != 0 ? 1 : 0);
		for (int i = 1; i < s.size(); i++)
		{
			arr.push_back(0);
			int cur = s[i] - '0', pre = s[i - 1] - '0';
			if (cur != 0)
			{
				arr[i] = arr[i - 1];
			}
			if (pre != 0 && pre * 10 + cur <= 26 && pre * 10 + cur >= 1)
			{
				arr[i] += i > 1 ? arr[i - 2] : 1;
			}
		}
		return arr[s.size() - 1];
	}

	// 0 ms	6.2 MB
	// give up vector
	int numDecodings(string s) {
		int prepreCount = 1, preCount = s[0] - '0' != 0 ? 1 : 0;
		for (int i = 1; i < s.size(); i++)
		{
			int curCount = 0;
			int cur = s[i] - '0', pre = s[i - 1] - '0';
			if (cur != 0)
			{
				curCount += preCount;
			}
			if (pre != 0 && pre * 10 + cur <= 26 && pre * 10 + cur >= 1)
			{
				curCount += prepreCount;
			}
			prepreCount = preCount;
			preCount = curCount;
		}
		return preCount;
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}