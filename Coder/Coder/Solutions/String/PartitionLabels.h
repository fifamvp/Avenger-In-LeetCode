#pragma once
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();

private:
	// 4 ms	6.7 MB
	vector<int> partitionLabels(string s) {
		map<char, int> last;
		for (int i = 0; i < s.size(); i++)
		{
			last[s[i]] = i;
		}

		vector<int> r;
		int start = 0, end = 0;
		for (int i = 0; i < s.size(); i++)
		{
			end = max(end, last[s[i]]);
			if (i == end)
			{
				r.push_back(i - start + 1);
				start = i + 1;
			}
		}

		return r;
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}