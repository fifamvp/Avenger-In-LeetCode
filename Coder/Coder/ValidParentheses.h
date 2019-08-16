#pragma once
#include <string>
#include <stack>
using namespace std;
class ValidParentheses
{
public:
	ValidParentheses();
	~ValidParentheses();

private:
	// This is a really awesome solution that makes time shorter
	bool isValid(string s) {
		stack<char> stk;
		for (const auto& c : s) {
			switch (c) {
			case '{':  stk.push('}'); break;
			case '[':  stk.push(']'); break;
			case '(':  stk.push(')'); break;
			default:
				if (stk.empty() || c != stk.top()) return false;
				else stk.pop();
			}
		}
		return stk.empty();
	}

	/*bool isValid(string s) {
		stack<char> former;
		for (size_t i = 0; i < s.size(); i++)
		{
			if (s[i] == '(' || s[i] == '[' || s[i] == '{')
				former.push(s[i]);
			else
			{
				if (!former.empty())
				{
					bool isValid = s[i] == ')' && former.top() == '(' || s[i] == ']' && former.top() == '[' || s[i] == '}' && former.top() == '{';
					if (isValid)
					{
						former.pop();
						continue;
					}
				}
				return false;
			}
		}

		return former.empty();
	}*/
};

ValidParentheses::ValidParentheses()
{
}

ValidParentheses::~ValidParentheses()
{
}