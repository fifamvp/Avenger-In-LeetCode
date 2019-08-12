#pragma once
#include <vector>
#include <algorithm>
#include <chrono>
using namespace std;
class ContainerWithMostWater
{
public:
	ContainerWithMostWater();
	~ContainerWithMostWater();
	void Solve()
	{
		vector<int> v = { 1, 8, 6, 2, 5, 4, 8, 3, 7 };
		printf("%d\n", maxArea(v));

		v.clear();
		for (size_t i = 1; i <= 15000; i++)
		{
			v.push_back(i);
		}
		printf("%d\n", maxArea(v));

	}

private:

	//int maxArea(vector<int>& height) {
	//	//auto start_time = std::chrono::system_clock::now();

	//	int result = 0;

	//	for (size_t i = 0; i < height.size(); i++)
	//	{
	//		int left = 0;
	//		int right = height.size() - 1;
	//		while (left < i || right > i)
	//		{
	//			if (left < i && height[left] >= height[i])
	//			{
	//				int v = (i - left) * height[i];
	//				if (v > result)
	//					result = v;
	//				break;
	//			}
	//			if (right > i && height[right] >= height[i])
	//			{
	//				int v = (right - i) * height[i];
	//				if (v > result)
	//					result = v;
	//				break;
	//			}
	//			if (left < i)
	//				left++;
	//			if (right > i)
	//				right--;
	//		}
	//	}

	//	//auto end_time = std::chrono::system_clock::now();
	//	//auto inteval = chrono::duration_cast<chrono::milliseconds>(end_time - start_time);

	//	//printf("%f\n", inteval);

	//	return result;
	//}

	int maxArea(vector<int>& height) {
		int result = 0;
		int i = 0, j = height.size() - 1, h = 0;
		while (i < j) 
		{
			h = min(height[i], height[j]);
			result = max(result, (j - i) * h);

			while (height[i] <= h && i < j)i++;
			while (height[j] <= h && i < j)j--;
		}
		return result;
	}
};

ContainerWithMostWater::ContainerWithMostWater()
{
}

ContainerWithMostWater::~ContainerWithMostWater()
{
}