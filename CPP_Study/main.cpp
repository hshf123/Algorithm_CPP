#pragma region Headers
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <numeric>
#include <sstream>
#include <array>

#define endl "\n"
#define INT32_HALF (INT32_MAX / 2)
#define Init cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
using namespace std;
using int64 = long long;
using uint64 = unsigned long long;
#pragma endregion

vector<vector<vector<int>>> blockTypeList =
{
	{{0,0},{1,0}, {0,1}},
	{{0,0},{0,1}, {1,1}},
	{{0,0},{1,0}, {1,1}},
	{{0,0},{1,0}, {1,-1}}
};

bool Set(vector<vector<int>>& board, const int& type, const int& y, const int& x, const bool& isAdd)
{
	bool ret = true;
	for (int i = 0; i < 3; i++)
	{
		// 블록 좌표
		int posY = y + blockTypeList[type][i][0];
		int posX = x + blockTypeList[type][i][1];

		// 좌표가 범위를 벗어나거나
		// 애초에 못 놓는 곳이라거나 이미 놓아져 있으면
		if (posY < 0 || posX < 0 || posY >= board.size() || posX >= board[0].size())
			ret = false;
		else
		{
			if (isAdd)
				board[posY][posX] += 1;
			else
				board[posY][posX] -= 1;
			if (board[posY][posX] > 1)
				ret = false;
		}
	}

	return ret;
}

int Solution(vector<vector<int>>& board)
{
	// 일단 보드에서 놓을 수 있는 곳 중 왼쪽 위를 찾는다
	int findY = -1;
	int findX = -1;
	for (int y = 0; y < board.size(); y++)
	{
		for (int x = 0; x < board[y].size(); x++)
		{
			if (board[y][x] != 0)	// 못 놓는 칸이거나 이미 놓아진 칸
				continue;

			findY = y;
			findX = x;
			break;					// 찾으면 바로 빠져나옴
		}
		if (findY != -1 && findX != -1) // 한번 더 빠져나와야하네..
			break;
	}
	if (findY == -1 && findX == -1)	// 여기 걸리면 다 채워진거
		return 1;

	// 4개 타입 중에서 놓을 수 있는지
	int ret = 0;
	for (int i = 0; i < 4; i++)
	{
		if (Set(board, i, findY, findX, true))
			ret += Solution(board);
		Set(board, i, findY, findX, false);
	}
	return ret;
}

int main()
{
	Init;

	int C;
	cin >> C;
	vector<int> ansList(C);
	for (int c = 0; c < C; c++)
	{
		int H, W;
		cin >> H >> W;
		vector<vector<int>> board(H, vector<int>(W));
		int count = 0;
		for (int y = 0; y < H; y++)
		{
			for (int x = 0; x < W; x++)
			{
				char c;
				cin >> c;
				if (c == '.')
				{
					board[y][x] = 0;
					count++;
				}
				else
					board[y][x] = 1;
			}
		}
		if (count % 3 != 0)
		{
			ansList[c] = 0;
			continue;
		}
		ansList[c] = Solution(board);
	}
	
	for (const int& ans : ansList)
		cout << ans << endl;
	
	return 0;
}