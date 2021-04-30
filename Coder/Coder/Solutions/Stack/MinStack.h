#pragma once
#include <stack>
#include <algorithm>
using namespace std;
class MinStack {
public:
	//24 ms	16.4 MB
	/** initialize your data structure here. */
	MinStack() {
		minStack.push(INT_MAX);
	}

	void push(int val) {
		baseStack.push(val);
		minStack.push(min(minStack.top(), val));
	}

	void pop() {
		baseStack.pop();
		minStack.pop();
	}

	int top() {
		return baseStack.top();
	}

	int getMin() {
		return minStack.top();
	}
private:
	stack<int> baseStack, minStack;
};

class MinStack2 {
public:
	// 20 ms	16.2 MB
	/** initialize your data structure here. */
	MinStack2() {
		minValue = LLONG_MAX;
	}

	void push(int val) {
		if (baseStack.empty())
		{
			baseStack.push(0);
			minValue = val;
		}
		else
		{
			baseStack.push(val - minValue);

			minValue = val < minValue ? val : minValue;
		}
	}

	void pop() {
		long long top = baseStack.top();
		baseStack.pop();
		if (top < 0)
		{
			minValue = minValue - top;
		}
	}

	int top() {
		return baseStack.top() < 0 ? minValue : minValue + baseStack.top();
	}

	int getMin() {
		return minValue;
	}
private:
	stack<long long> baseStack;
	long long minValue;
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */