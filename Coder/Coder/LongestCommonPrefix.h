#pragma once
#include<string>	
#include<vector>
using namespace std;
class LongestCommonPrefix
{
public:
	LongestCommonPrefix();
	~LongestCommonPrefix();
	void Solve()
	{
		vector<string> test = { "flower", "flow", "flight" };
		printf("%s\n", longestCommonPrefix(test).c_str());
		test = { "dog","racecar","car" };
		printf("%s\n", longestCommonPrefix(test).c_str());
		test = { "","","" };
		printf("%s\n", longestCommonPrefix(test).c_str());
	}

private:
	string longestCommonPrefix(vector<string>& strs) {
		if (strs.size() == 0)return "";
		string result = strs[0];
		for (size_t i = 1; i < strs.size(); i++)
		{
			size_t j = 0;
			for (; j < result.size() && j < strs[i].size(); j++)
			{
				if (result[j] != strs[i][j])
				{
					break;
				}
			}
			if (j < result.size()) {
				result = result.substr(0, j);
			}
		}
		return result;
	}
};

LongestCommonPrefix::LongestCommonPrefix()
{
}

LongestCommonPrefix::~LongestCommonPrefix()
{
}