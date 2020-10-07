#pragma once
#include <string>
#include <sstream>
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();

private:
	// 0 ms	7.3 MB
	string reverseWords(string s) {
		reverse(s.begin(), s.end());
		int idx = 0; // idx means the next position to insert word
		for (int start = idx; start < s.size(); start++)
		{
			if (s[start] == ' ') continue;
			int end = start + 1;
			while (end < s.size() && s[end] != ' ')
			{
				end++;
			}
			reverse(s.begin() + start, s.begin() + end);
			while (start < end)
			{
				s[idx++] = s[start++];
			}
			s[idx++] = ' ';
		}
		// erase left whitespaces and remember the one at idx - 1 is added manually
		s.erase(s.begin() + idx - 1, s.end());
		return s;
	}

	// 4 ms	7.2 MB
	string reverseWords2(string s) {
		reverse(s.begin(), s.end());
		int idx = 0; // idx means the next position to insert word
		for (int start = idx; start < s.size(); start++)
		{
			if (s[start] == ' ') continue;
			if (idx != 0) s[idx++] = ' ';
			int end = start;
			while (end < s.size() && s[end] != ' ')
			{
				s[idx++] = s[end++];
			}
			reverse(s.begin() + idx - (end - start), s.begin() + idx);
			start = end;
		}
		s.erase(s.begin() + idx, s.end());
		return s;
	}

	// 0 ms	7.5 MB
	string reverseWords3(string s) {
		istringstream in(s);
		string tmp;
		s = "";
		while (in >> tmp)
		{
			reverse(tmp.begin(), tmp.end());
			s += ' ' + tmp;
		}
		if (!s.empty())
		{
			reverse(s.begin(), s.end());
			s.pop_back(); // remove the whitespace added at first
		}
		return s;
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}