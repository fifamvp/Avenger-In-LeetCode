#pragma once
#include <stdio.h>
using namespace std;
class PalindromeNumber
{
public:
	PalindromeNumber();
	~PalindromeNumber();
	void Solve()
	{
		printf("%d\n", isPalindrome(121));
		printf("%d\n", isPalindrome(-121));
		printf("%d\n", isPalindrome(10));
		printf("%d\n", isPalindrome(0));
		printf("%d\n", isPalindrome(2147483647));
		printf("%d\n", isPalindrome(21120));
	}

private:
	bool isPalindrome(int x) {
		if (x < 0)return false;

		double afterReverse = 0;
		int tmp = x;
		while (tmp != 0)
		{
			afterReverse = afterReverse * 10 + tmp % 10;
			tmp /= 10;
		}

		return (double)x == afterReverse;
	}
};

PalindromeNumber::PalindromeNumber()
{
}

PalindromeNumber::~PalindromeNumber()
{
}