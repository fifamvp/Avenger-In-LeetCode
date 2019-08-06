#pragma once
#include <algorithm>
using namespace std;
class ReverseInteger
{
public:
	ReverseInteger();
	~ReverseInteger();
	void Solve() {
		printf("%d\n", reverse(123));
		printf("%d\n", reverse(-123));
		printf("%d\n", reverse(120));
		printf("%d\n", reverse(0));
		printf("%d\n", reverse(-1));
		printf("%d\n", reverse(pow(2, 31) - 1));
		printf("%d\n", reverse(-pow(2, 31)));
		// -2147483648 is a testcase on LeetCode
	}
private:
	int reverse(int x) {
		if (x % 10 == x)
			return x;

		double result = 0;
		while (x != 0)
		{
			result = result * 10 + x % 10;
			x /= 10;
		}

		return result > pow(2, 31) - 1 || result < -pow(2, 31) ? 0 : result;
	}
};

ReverseInteger::ReverseInteger()
{
}

ReverseInteger::~ReverseInteger()
{
}