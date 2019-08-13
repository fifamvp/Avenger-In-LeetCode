#pragma once
#include<string>
#include<stdlib.h>
#include<iostream>
using namespace std;
class IntegerToRoman
{
public:
	IntegerToRoman();
	~IntegerToRoman();
	void Solve()
	{
		int n;
		while (cin >> n)
		{
			printf("%s\n", intToRoman(n).c_str());
		}
	}

private:

	string search(int m, int n, string signal, int num)
	{
		if (num < m)
		{
			return intToRoman(n) + intToRoman(m) + intToRoman(num - (m - n));
		}
		else
		{
			string r;
			int q = num / m;
			while (q > 0)
			{
				r += signal;
				q--;
			}
			return r + intToRoman(num % m);
		}
	}

	string intToRoman(int num)
	{
		if (num <= 0)
			return "";
		if (num >= 1000 - 100)
			return search(1000, 100, "M", num);
		if (num >= 500 - 100)
			return search(500, 100, "D", num);
		if (num >= 100 - 10)
			return search(100, 10, "C", num);
		if (num >= 50 - 10)
			return search(50, 10, "L", num);
		if (num >= 10 - 1)
			return search(10, 1, "X", num);
		if (num >= 5 - 1)
			return search(5, 1, "V", num);
		return search(1, 0, "I", num);
	}
};

IntegerToRoman::IntegerToRoman()
{
}

IntegerToRoman::~IntegerToRoman()
{
}