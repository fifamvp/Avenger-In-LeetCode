#pragma once
#include <string>
#include <algorithm>
using namespace std;

class StringToInteger
{
public:
	StringToInteger();
	~StringToInteger();
	void Solve() {
		printf("%d\n", myAtoi("42"));
		printf("%d\n", myAtoi("   -42"));
		printf("%d\n", myAtoi("4193 with words"));
		printf("%d\n", myAtoi("words and 987"));
		printf("%d\n", myAtoi("-91283472332"));

		//special testcase
		printf("%d\n", myAtoi("-+45"));
		printf("%d\n", myAtoi("+1 550"));
		printf("%d\n", myAtoi("- 1550"));
		printf("%d\n", myAtoi("0-1"));
		printf("%d\n", myAtoi("   "));
	}
private:
	/*int myAtoi(string str) {
		double result = 0;
		int signFound = 0;
		int nextTarget = 0;
		for (size_t i = 0; i < str.length(); i++)
		{
			if (nextTarget == 0)
			{
				if (str[i] == ' ')
					continue;
				else if (str[i] == '-' || str[i] == '+')
				{
					signFound = str[i] == '-' ? -1 : 1;
					nextTarget = 1;
				}
				else if (str[i] >= '0' && str[i] <= '9')
				{
					result = result * 10 + (str[i] - '0');
					nextTarget = 1;
				}
				else
				{
					break;
				}
			}
			else
			{
				if (str[i] >= '0' && str[i] <= '9')
				{
					nextTarget = 1;
					result = result * 10 + (str[i] - '0');
				}
				else
				{
					break;
				}
			}
		}

		if (signFound < 0)
			result = -result;

		if (result > INT_MAX)
			return INT_MAX;
		if (result < INT_MIN)
			return INT_MIN;

		return result;
	}*/

	int myAtoi(string str) {
		double result = 0;
		int i = str.find_first_not_of(' ');
		if (i == string::npos)
			return result;

		int sign = 1;
		if (str[i] == '-' || str[i] == '+') 
		{
			sign = str[i++] == '-' ? -1 : 1;
		}
		while (i < str.size() && str[i] >= '0' && str[i] <= '9')
		{
			result = result * 10 + (str[i++] - '0') * sign;
			if (result > INT_MAX) return INT_MAX;
			if (result < INT_MIN) return INT_MIN;
		}

		return result;
	}
};

StringToInteger::StringToInteger()
{
}

StringToInteger::~StringToInteger()
{
}