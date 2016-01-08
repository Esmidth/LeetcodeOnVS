//	Valid Sudoku	<Easy>
#include "stdafx.h"
#include <iostream>
#include <vector>

using namespace std;

bool isValidBlock(vector<vector<char>>& board, int pos)
{
	int x_start;
	int y_start;
	y_start = pos / 3;
	y_start *= 3;
	x_start = pos % 3;
	x_start *= 3;
	int table[9] = {0,0,0,0,0,0,0,0,0};
	for (int i = x_start; i < x_start + 3; i++)
		for (int j = y_start; j < y_start + 3; j++)
			if (board[i][j] != '.')
			{
				if (table[board[i][j] - '0' - 1] == 1)
					return false;
				else if (table[board[i][j] - '0' - 1] == 0)
					table[board[i][j] - '0' - 1] = 1;
			}
	return true;
}

bool isValidLine(vector<vector<char>>& board, int line, int row)
{
	int table[9] = {0,0,0,0,0,0,0,0,0};
	if (row == 1)
	{
		for (int i = 0; i < 9; i++)
			if (board[i][line] != '.')
			{
				if (table[board[i][line] - '0' - 1] == 1)
					return false;
				else if (table[board[i][line] - '0' - 1] == 0)
					table[board[i][line] - '0' - 1] = 1;
			}
		return true;
	}
	else
	{
		for (int j = 0; j < 9; j++)
			if (board[line][j] != '.')
			{
				if (table[board[line][j] - '0' - 1] == 1)
					return false;
				else if (table[board[line][j] - '0' - 1] == 0)
					table[board[line][j] - '0' - 1] = 1;
			}
		return true;
	}
}


int display(vector<vector<char>>* a)
{
	if (a == nullptr)
	{
		cout << "FUCKING A NULL POINTER\n";
		return 1;
	}
	for (int i = 0; i < a->size(); i++)
	{
		for (int j = 0; j < (*a)[i].size(); j++)
		{
			cout << (*a)[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}


bool isValidSudoku(vector<vector<char>>& board)
{
	int sum = 0;
	for (int i = 0; i < 9; i++)
		sum += isValidBlock(board, i);
	if (sum != 9)
		return false;
	sum = 0;
	for (int i = 0; i < 9; i++)
		sum += isValidLine(board, i, 1);
	if (sum != 9)
		return false;
	sum = 0;
	for (int i = 0; i < 9; i++)
		sum += isValidLine(board, i, 0);
	if (sum != 9)
		return false;
	return true;
}

int displayBlock(vector<vector<char>>* a, int pos)
{
	int x_start = pos % 3;
	int y_start = pos / 3;
	x_start *= 3;
	y_start *= 3;
	for (int i = y_start; i < y_start + 3; i++)
	{
		for (int j = x_start; j < x_start + 3; j++)
		{
			cout << (*a)[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}

void test()
{
	vector<vector<char>> test_case1
			{
				{'5','3','.','.','7','.','.','.','.'},
				{'6','.','.','1','9','5','.','.','.'},
				{'.','9','8','.','.','.','.','6','.'},
				{'8','.','.','.','6','.','.','.','3'},
				{'4','.','.','8','.','3','.','.','1'},
				{'7','.','.','.','2','.','.','.','6'},
				{'.','6','.','.','.','.','2','8','.'},
				{'.','.','.','4','1','9','.','.','5'},
				{'.','.','.','.','8','.','.','7','9'}
			};
	display(&test_case1);
	cout << isValidSudoku(test_case1);
}


int main()
{
	test();
	system("pause");
}

