#pragma once
#include <vector>
using namespace std;
class RemoveElement
{
public:
	RemoveElement();
	~RemoveElement();

private:
	//4 ms	8.5 MB
	int removeElement(vector<int>& nums, int val) {
		int lastIndex = nums.size() - 1, count = 0;
		for (int i = 0; i <= lastIndex; i++)
		{
			if (nums[i] == val)
			{
				count++;
				while (lastIndex > i && nums[lastIndex] == val)
				{
					count++;
					lastIndex--;
				}
				if (lastIndex == i)break;
				nums[i] = nums[lastIndex--];
			}
		}
		return nums.size() - count;
	}

	//4 ms	8.7 MB
	int removeElement2(vector<int>& nums, int val) {
		int index = -1;
		for (int i = 0; i < nums.size(); i++)
		{
			if (nums[i] != val)
				nums[++index] = nums[i];
		}
		return index + 1;
	}
};

RemoveElement::RemoveElement()
{
}

RemoveElement::~RemoveElement()
{
}