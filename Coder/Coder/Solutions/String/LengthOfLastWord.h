#pragma once
#include <string>;
#include <sstream>
using namespace std;
#define S2 1
class Solution
{
public:
	Solution();
	~Solution();

private:
#ifdef S1
	// 4 ms	6.9 MB
	int lengthOfLastWord(string s) {
		istringstream in(s);
		int len = 0;
		string tmp;
		while (in >> tmp)
		{
			len = tmp.size();
		}
		return len;
	}
#elif S2
	// 4 ms	6.5 MB
	int lengthOfLastWord(string s) {
		int len = 0;
		for (int i = s.size() - 1; i >= 0; i--)
		{
			if (s[i] == ' ')
			{
				if (len == 0)
					continue;
				else
					break;
			}
			len++;
		}
		return len;
}
#endif // S1

	
};

Solution::Solution()
{
}

Solution::~Solution()
{
}