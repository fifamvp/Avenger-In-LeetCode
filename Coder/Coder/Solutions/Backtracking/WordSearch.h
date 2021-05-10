#pragma once
#include <vector>
#include <set>
using namespace std;
#define S1_4 1
class Solution
{
public:
	Solution();
	~Solution();

private:
#if S1
	// 428 ms	7.5 MB
	bool exist(vector<vector<char>>& board, string word) {
		bool isFound = false;
		vector<pair<int, int>> t;
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				if (board[i][j] == word[0]) {
					t.clear();
					t.push_back(make_pair(i, j));
					isFound = dfs(board, word, 1, t);
					if (isFound)
						return isFound;
				}
			}
		}
		return isFound;
}

	bool dfs(vector<vector<char>>& board, string& word, int wordIdx, vector<pair<int, int>>& t) {
		if (wordIdx >= word.size()) {
			return true;
		}
		int i = t.back().first, j = t.back().second;
		auto check = [&](int i, int j) {
			if (i < 0 || i >= board.size())
				return false;
			if (j < 0 || j >= board[0].size())
				return false;
			if (board[i][j] != word[wordIdx])
				return false;
			if (find(t.begin(), t.end(), make_pair(i, j)) != t.end())
				return false;
			t.push_back(make_pair(i, j));
			bool isFound = dfs(board, word, wordIdx + 1, t);
			t.pop_back();
			return isFound;
		};

		return check(i + 1, j) || check(i, j + 1) || check(i - 1, j) || check(i, j - 1);
	}
#elif S1_2
	// 180 ms	7.3 MB
	bool exist(vector<vector<char>>& board, string word) {
		bool isFound = false;
		vector<vector<bool>> t((int)board.size(), vector<bool>((int)board[0].size(), false));
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				if (board[i][j] == word[0]) {
					t[i][j] = true;
					isFound = dfs(board, word, 1, t, i, j);
					if (isFound)
						return isFound;
					t[i][j] = false;
				}
			}
		}
		return isFound;
	}

	bool dfs(vector<vector<char>>& board, string& word, int wordIdx, vector<vector<bool>>& t, int formerI, int formerJ) {
		if (wordIdx >= word.size()) {
			return true;
		}
		auto check = [&](int i, int j) {
			if (i < 0 || i >= board.size())
				return false;
			if (j < 0 || j >= board[0].size())
				return false;
			if (board[i][j] != word[wordIdx])
				return false;
			if (t[i][j])
				return false;
			t[i][j] = true;
			bool isFound = dfs(board, word, wordIdx + 1, t, i, j);
			t[i][j] = false;
			return isFound;
		};

		return check(formerI + 1, formerJ) || check(formerI, formerJ + 1) || check(formerI - 1, formerJ) || check(formerI, formerJ - 1);
	}
#elif S1_3
	// 180 ms	7.3 MB
	bool exist(vector<vector<char>>& board, string word) {
		bool isFound = false;
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				if (board[i][j] == word[0]) {
					board[i][j] = ' ';
					isFound = dfs(board, word, 1, i, j);
					if (isFound)
						return isFound;
					board[i][j] = word[0];
				}
			}
		}
		return isFound;
	}

	bool dfs(vector<vector<char>>& board, string& word, int wordIdx, int formerI, int formerJ) {
		if (wordIdx >= word.size()) {
			return true;
		}
		auto check = [&](int i, int j) {
			if (i < 0 || i >= board.size())
				return false;
			if (j < 0 || j >= board[0].size())
				return false;
			if (board[i][j] != word[wordIdx])
				return false;
			board[i][j] = ' ';
			bool isFound = dfs(board, word, wordIdx + 1, i, j);
			board[i][j] = word[wordIdx];
			return isFound;
		};

		return check(formerI + 1, formerJ) || check(formerI, formerJ + 1) || check(formerI - 1, formerJ) || check(formerI, formerJ - 1);
	}
#elif S1_4
	// 116 ms	7.2 MB
	bool exist(vector<vector<char>>& board, string word) {
		for (int i = 0; i < board.size(); i++)
		{
			for (int j = 0; j < board[0].size(); j++)
			{
				if (dfs(board, word, 0, i, j))
					return true;
			}
		}
		return false;
	}

	bool dfs(vector<vector<char>>& board, string& word, int wordIdx, int i, int j) {
		if (wordIdx >= word.size())
			return true;
		if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[wordIdx])
			return false;
		
		board[i][j] = ' ';
		bool isFound = dfs(board, word, wordIdx + 1, i + 1, j) 
			|| dfs(board, word, wordIdx + 1, i, j + 1) 
			|| dfs(board, word, wordIdx + 1, i - 1, j) 
			|| dfs(board, word, wordIdx + 1, i, j - 1);
		board[i][j] = word[wordIdx];
		return isFound;
	}
#endif
	
};

Solution::Solution()
{
}

Solution::~Solution()
{
}