#pragma once
#include <string>
#include <algorithm>
#include <iostream>

using namespace std;

class LongestPalindromicSubstring
{
public:
	LongestPalindromicSubstring();
	~LongestPalindromicSubstring();
	bool isPalindrome(string s) {
		for (size_t i = 0; i < s.length() / 2; i++)
		{
			if (s[i] != s[s.length() - 1 - i]) {
				return false;
			}
		}
		return true;
	}

	void Solve(int option = 0) {
		string testData[] = { "babad", "cbbd", "aaaaa" };

		switch (option)
		{
		case 0:
			for (auto v : testData) {
				cout << longestPalindromeOp0(v) << endl;
			}
			break;
		case 1:
			for (auto v : testData) {
				cout << longestPalindromeOp1(v) << endl;
			}
			break;
		default:
			break;
		}
	}
private:

	string addFlag(string s) {
		string newS = "#";
		for (size_t i = 0; i < s.length(); i++)
		{
			newS = newS + s[i] + '#';
		}
		return newS;
	}

	string longestPalindromeOp0(string s) {
		s = addFlag(s);
		string result;

		int* halfRange = new int[s.length()];

		int rightSide = 0;
		int rightSideCenter = 0;
		int center = 0;
		int max = 0;
		for (int i = 0; i < s.length(); i++)
		{
			halfRange[i] = 0;
			bool needCalC = true;

			if (rightSide > i) {
				int leftSideCenter = 2 * rightSideCenter - i;
				halfRange[i] = halfRange[leftSideCenter];

				if (i + halfRange[i] > rightSide) {
					halfRange[i] = rightSide - i;
				}

				if (i + halfRange[leftSideCenter] < rightSide) {
					needCalC = false;
				}
			}

			if (needCalC) {
				while (i - 1 - halfRange[i] >= 0 && i + 1 + halfRange[i] < s.length())
				{
					if (s.at(i - 1 - halfRange[i]) == s.at(i + 1 + halfRange[i])) {
						halfRange[i]++;
					}
					else
					{
						break;
					}
				}
				rightSide = i + halfRange[i];
				rightSideCenter = i;

				if (halfRange[i] > max) {
					max = halfRange[i];
					center = i;
				}
			}
		}

		result = s.substr(center - max, 2 * max + 1);
		result.erase(remove(result.begin(), result.end(), '#'), result.end());

		return result;
	}

	// Op1 is faster
	string longestPalindromeOp1(string s) {
		if (s.size() < 2) return s;
		int maxLen = 0;
		int startIdx = 0;
		for (int i = 0; i < s.size(); i++) {
			if (maxLen > (s.size() - i) * 2)
				return s.substr(startIdx, maxLen);
			int count = 0;
			while (i + 1 < s.size() && s[i + 1] == s[i]) {
				count++;
				i++;
			}
			int right = i;
			int left = i - count;
			while (left >= 0 && right < s.size() && s[left] == s[right]) {
				left--;
				right++;
			}
			left++;
			right--;
			if (right - left + 1 > maxLen) {
				maxLen = right - left + 1;
				startIdx = left;
			}
		}
		return s.substr(startIdx, maxLen);
	}

};

LongestPalindromicSubstring::LongestPalindromicSubstring()
{
}

LongestPalindromicSubstring::~LongestPalindromicSubstring()
{
}