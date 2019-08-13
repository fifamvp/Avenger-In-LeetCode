#pragma once
#include<string>
#include<unordered_map>
#include<iostream>
using namespace std;

class RomanToInteger
{
public:
	 RomanToInteger();
	~ RomanToInteger();
	void Solve()
	{
		string s;
		while (cin>>s)
		{
			cout << romanToInt(s) << endl;
		}
	}

private:
	// unordered_map is faster
	const unordered_map<char, int> roman = { { 'I' , 1 }, { 'V', 5 }, { 'X', 10 }, { 'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000} };
	int romanToInt(string s) {
		int result = 0;

		for (size_t i = 0; i < s.size(); i++)
		{
			int v = roman.at(s[i]);
			if (i + 1 < s.size()) {
				if (v < roman.at(s[i + 1]))
					v = -v;
			}
			result += v;
		}

		return result;
	}
};

 RomanToInteger:: RomanToInteger()
{
}

 RomanToInteger::~ RomanToInteger()
{
}