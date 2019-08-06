#pragma once
#include <string>
#include <iostream>
#include <algorithm>

using namespace std;

class ZigZagConversion
{
public:
	ZigZagConversion();
	~ZigZagConversion();
	void Solve() {
		cout << convert("PAYPALISHIRING", 3) << endl;
		cout << convert("PAYPALISHIRING", 4) << endl;
		// Reminder : numRows could be 1;
		cout << convert("ABCDE", 1) << endl;
	}
private:
	string convert(string s, int numRows) {
		if (numRows < 2 || s.empty()) return s;

		int neededRows = min(numRows, (int)s.size());
		string * arr = new string[neededRows];
		int currentRow = 0;
		bool isDown = false;
		for (int i = 0; i < s.length(); i++) {
			arr[currentRow] += (s[i]);

			if (currentRow == 0 || currentRow == neededRows - 1)
				isDown = !isDown;

			currentRow += isDown ? 1 : -1;
		}

		string result = "";
		for (int i = 0; i < neededRows; i++) {
			result += arr[i];
		}
		return result;
	}
};

ZigZagConversion::ZigZagConversion()
{
}

ZigZagConversion::~ZigZagConversion()
{
}
