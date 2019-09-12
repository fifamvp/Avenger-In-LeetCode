#pragma once
#include <vector>
#include <unordered_set>
using namespace std;
class Solution
{
public:
	Solution();
	~Solution();

private:
	//28 ms	10.4 MB
	bool isValidSudoku(vector<vector<char>>& board) {
		unordered_set<char> s;
		for (int i = 0, j = 0; i < board.size() && j < board.size(); ) {
			if (board[i][j] != '.' && s.find(board[i][j]) != s.end())
				return false;
			else
				s.insert(board[i][j]);

			if (++j >= board.size()) {
				i++;
				j = 0;
				s.clear();
			}
		}

		for (int i = 0, j = 0; i < board.size() && j < board.size(); ) {
			if (board[i][j] != '.' && s.find(board[i][j]) != s.end())
				return false;
			else
				s.insert(board[i][j]);

			if (++i >= board.size()) {
				j++;
				i = 0;
				s.clear();
			}
		}

		for (int m = 0, n = 0; m < 3 && n < 3;)
		{
			for (int i = m * 3, j = n * 3; i < (m + 1) * 3 && j < (n + 1) * 3; ) {
				if (board[i][j] != '.' && s.find(board[i][j]) != s.end())
					return false;
				else
					s.insert(board[i][j]);
				if (++j >= (n + 1) * 3) {
					i++;
					j = n * 3;
				}
			}
			if (++n >= 3) {
				m++;
				n = 0;
			}
			s.clear();
		}

		return true;
	}
};

Solution::Solution()
{
}

Solution::~Solution()
{
}