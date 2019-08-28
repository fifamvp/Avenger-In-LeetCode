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
		strStr2("mississippi", "issip");
	}

private:
	int strStr(string haystack, string needle) {
		return haystack.find(needle);
	}

	int strStr2(string haystack, string needle) {
		if (needle.empty())return 0;
		vector<int> next = getNext(needle);

		int endIndex = haystack.size() - needle.size();
		for (int i = 0; i <= endIndex;)
		{
			for (int j = i, k = 0; k < needle.size(); j++, k++)
			{
				if (haystack[j] != needle[k])
				{
					i += k == 0 ? 1 : k - next[k - 1];
					break;
				}
				else
				{
					if (k == needle.size() - 1)
						return i;
				}
			}
		}
		return -1;
	}

	vector<int> getNext(string p)
	{
		int size = p.size();
		vector<int> next(size, 0);
		for (int i = 1, len = 0; i < size;)
		{
			if (p[i] == p[len])
			{
				next[i++] = ++len;
			}
			else if (len)
			{
				len = next[len - 1];
			}
			else
			{
				next[i++] = 0;
			}
		}
		return next;
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}