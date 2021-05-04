#pragma once
#include <vector>
#include <map>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;
#define S1_3 1
class Solution
{
public:
	Solution();
	~Solution();

	void Solve()
	{
		vector<string> inputs = { "ddddddddddg","dgggggggggg" };
		groupAnagrams(inputs);
	}
private:
#if S1
	// 164 ms	30.7 MB
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> r;
		map<string, vector<string>> anagramMap;
		for (auto &str : strs)
		{
			map<int, int> meetNum;
			for (int i = 0; i < str.size(); i++)
			{
				int idx = str[i] - 'a';
				meetNum[idx]++;
			}
			string key;
			for (int i = 25; i >= 0; i--)
			{
				int num = meetNum.count(i) ? meetNum[i] : 0;
				key.append(to_string(num) + ",");
			}
			anagramMap[key].push_back(str);
		}

		r.reserve(anagramMap.size());
		for (auto &item : anagramMap)
		{
			r.push_back(std::move(item.second));
		}
		return r;
	}
#elif S1_2
	// 68 ms	26.5 MB
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> r;
		map<string, vector<string>> anagramMap;
		for (auto &str : strs)
		{
			map<char, int> meetNum;
			for (int i = 0; i < str.size(); i++)
			{
				meetNum[str[i]]++;
			}
			string key;
			for (auto & kv : meetNum)
			{
				key += (kv.first + to_string(kv.second));
			}
			anagramMap[key].push_back(str);
		}

		r.reserve(anagramMap.size());
		for (auto &item : anagramMap)
		{
			r.push_back(std::move(item.second));
		}
		return r;
	}
#elif S1_3
	// 36 ms	18.2 MB
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> r;
		unordered_map<string, vector<string>> anagramMap;
		for (auto &str : strs)
		{
			int charArr[26] = { 0 };
			for (int i = 0; i < str.size(); i++)
			{
				charArr[str[i] - 'a']++;
			}
			string key;
			for (int i = 0; i < 26; i++)
			{
				if (charArr[i] > 0)
					key += string(1, 'a' + i) + to_string(charArr[i]);
			}
			
			anagramMap[key].push_back(str);
		}

		r.reserve(anagramMap.size());
		for (auto &item : anagramMap)
		{
			r.push_back(std::move(item.second));
		}
		return r;
	}

#elif S1_4
	// 24 ms	21.3 MB
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		// 自定义对 array<int, 26> 类型的哈希函数
		auto arrayHash = [fn = hash<int>{}](const array<int, 26>& arr)->size_t {
			return accumulate(arr.begin(), arr.end(), 0u, [&](size_t acc, int num) {
				return (acc << 1) ^ fn(num);
			});
		};

		unordered_map<array<int, 26>, vector<string>, decltype(arrayHash)> mp(0, arrayHash);
		for (string& str : strs) {
			array<int, 26> counts{};
			int length = str.length();
			for (int i = 0; i < length; ++i) {
				counts[str[i] - 'a'] ++;
			}
			mp[counts].emplace_back(str);
		}
		vector<vector<string>> ans;
		for (auto it = mp.begin(); it != mp.end(); ++it) {
			ans.emplace_back(it->second);
		}
		return ans;
	}
#elif S2
	// 28 ms	17.7 MB
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> r;
		map<string, vector<string>> mymap;
		for (auto& str : strs)
		{
			string copy = str;
			sort(copy.begin(), copy.end());
			mymap[copy].push_back(str);
		}
		r.reserve(mymap.size());
		for (auto& item : mymap)
		{
			r.push_back(std::move(item.second));
		}
		return r;
	}
#elif S2_2
	// 20 ms	17.7 MB
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		vector<vector<string>> r;
		unordered_map<string, vector<string>> mymap;
		for (auto& str : strs)
		{
			string copy = str;
			sort(copy.begin(), copy.end());
			mymap[copy].push_back(str);
		}
		r.reserve(mymap.size());
		for (auto& item : mymap)
		{
			r.push_back(std::move(item.second));
		}
		return r;
	}
#endif
};

Solution::Solution()
{
}

Solution::~Solution()
{
}