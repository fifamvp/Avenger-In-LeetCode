#pragma once

#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>

using namespace std;

class LongestSubstringWithoutRepeatingCharacters
{
public:
	LongestSubstringWithoutRepeatingCharacters();
	~LongestSubstringWithoutRepeatingCharacters();

	void Solve() {
		cout << lengthOfLongestSubstring("abcabcbb") << endl;
		cout << lengthOfLongestSubstring("bbbbb") << endl;
		cout << lengthOfLongestSubstring("pwwkew") << endl;
	}
private:
	int lengthOfLongestSubstring(string s) {
		int length = 0;
		unordered_map<char, int> map;

		int start = 0;
		for (int i = 0; i < s.length(); i++) {
			if (map.find(s[i]) != map.end()) {
				if (map[s[i]] >= start) {
					start = map[s[i]] + 1;
				}
			}
			length = max(length, i - start + 1);

			map[s[i]] = i;
		}
		return length;
	}
};

LongestSubstringWithoutRepeatingCharacters::LongestSubstringWithoutRepeatingCharacters()
{
}

LongestSubstringWithoutRepeatingCharacters::~LongestSubstringWithoutRepeatingCharacters()
{
}