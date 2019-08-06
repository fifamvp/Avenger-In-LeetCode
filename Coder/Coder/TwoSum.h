#pragma once

#include <vector>
#include <unordered_map>

using namespace std;

class TwoSum
{
public:
	TwoSum();
	~TwoSum();
	void Solve() {
		vector<int> nums = { 2, 7, 15, 18 };

		vector<int> r = twoSum(nums, 9);

		for (auto v : r) {
			printf("%d", v);
		}
	}
private:
	vector<int> twoSum(vector<int> &numbers, int target)
	{
		//Key is the number and value is its index in the vector.
		unordered_map<int, int> hash;
		vector<int> result;
		for (size_t i = 0; i < numbers.size(); i++) {
			int numberToFind = target - numbers[i];

			//if numberToFind is found in map, return them
			if (hash.find(numberToFind) != hash.end()) {
				//+1 because indices are NOT zero based
				result.push_back(hash[numberToFind]);
				result.push_back(i);
				return result;
			}

			//number was not found. Put it in the map.
			hash[numbers[i]] = i;
		}
		return result;
	}
};

TwoSum::TwoSum()
{
}

TwoSum::~TwoSum()
{
}
