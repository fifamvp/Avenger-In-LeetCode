#pragma once
#include <vector>
#include <string>
using namespace std;
class LetterCombinationsOfAPhoneNumber
{
public:
	LetterCombinationsOfAPhoneNumber();
	~LetterCombinationsOfAPhoneNumber();
	void Solve()
	{
		string test = "23";
		test = "";
		auto r = letterCombinations(test);
		for (auto v : r)
		{
			printf("%s ", v.c_str());
		}
		printf("\n");
	}
private:
	vector<string> letterCombinations(string digits) {
		vector<string> result;
		if (digits.size() == 0)return result;

		string letters[9] = { "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
		for (int j = 0; j < letters[digits[0] - '1'].size(); j++)
		{
			result.push_back(string(1, letters[digits[0] - '1'][j]));
		}

		for (size_t i = 1; i < digits.size(); i++)
		{
			for (vector<string>::iterator it = result.begin(); it != result.end(); it++)
			{
				string tmp = *it;
				*it = *it + string(1, letters[digits[i] - '1'][0]);

				for (int j = 1; j < letters[digits[i] - '1'].size(); j++)
				{
					it = result.insert(it + 1, tmp + string(1, letters[digits[i] - '1'][j]));
				}
			}
		}
		return result;
	}
};

LetterCombinationsOfAPhoneNumber::LetterCombinationsOfAPhoneNumber()
{
}

LetterCombinationsOfAPhoneNumber::~LetterCombinationsOfAPhoneNumber()
{
}