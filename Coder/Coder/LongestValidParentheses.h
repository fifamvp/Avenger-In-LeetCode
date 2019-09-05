#pragma once
#include <string>
#include <stack>
#include <algorithm>
using namespace std;
class LongestValidParentheses
{
public:
	LongestValidParentheses();
	~LongestValidParentheses();
	//"()())()()()(((()"
private:
	//8 ms	9.1 MB
	int longestValidParentheses(string s) {
		int r = 0, left = 0, right = 0;
		for (size_t i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
				left++;
			else {
				right++;
				if (right == left)
					r = max(r, 2 * left);
				else if (right > left)
					left = right = 0;
			}

		}
		left = right = 0;
		for (int i = s.size() - 1; i >= 0; i--)
		{
			if (s[i] == '(') {
				left++;
				if (right == left)
					r = max(r, 2 * left);
				else if (left > right)
					left = right = 0;
			}
			else
				right++;
		}
		return r;
	}

	//0 ms	9.5 MB
	int longestValidParentheses2(string s) {
		int r = 0;
		stack<int> stk;
		stk.push(-1);
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
				stk.push(i);
			else {
				stk.pop();
				if (!stk.empty())
					r = max(r, i - stk.top());
				else
					stk.push(i);
			}
		}
		return r;
	}
};

LongestValidParentheses::LongestValidParentheses()
{
}

LongestValidParentheses::~LongestValidParentheses()
{
}