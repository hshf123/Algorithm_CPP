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

// 시계방향 8방
array<int, 8> dy = { 1, 1, 0, -1, -1, -1, 0, 1 };
array<int, 8> dx = { 0, 1, 1, 1, 0, -1, -1, -1 };
vector<vector<char>> board(5, vector<char>(5));
vector<string> tc;

bool Search(const int& y, const int& x, const string& str)
{
	// 범위를 벗어났다면 실패
	if (y < 0 || x < 0 || y >= 5 || x >= 5)
		return false;

	const char& c = board[y][x];
	if (str[0] != c)		// 틀린문자
		return false;
	if (str.size() == 1)	// 다 찾음!
		return true;

	// 다음 8방향 탐색
	for (int i = 0; i < 8; i++)
	{
		// 먼저 한 번이라도 찾으면 끝
		if (Search(y + dy[i], x + dx[i], str.substr(1)))
			return true;
	}

	return false;
}

int main()
{
	Init;

	int C;
	cin >> C;

	for (int y = 0; y < 5; y++)
		for (int x = 0; x < 5; x++)
			cin >> board[y][x];

	for (int c = 0; c < C; c++)
	{
		int N;
		cin >> N;
		tc.resize(N);
		for (int i = 0; i < N; i++)
			cin >> tc[i];

		vector<bool> existList(tc.size(), false);
		for (int y = 0; y < 5; y++)
		{
			for (int x = 0; x < 5; x++)
			{
				for (int i = 0; i < tc.size(); i++)
				{
					if (Search(y, x, tc[i]))
						existList[i] = true;
				}
			}
		}

		for (int i = 0; i < tc.size(); i++)
		{
			if (existList[i])
				cout << tc[i] << " YES" << endl;
			else
				cout << tc[i] << " NO" << endl;
		}
	}
	
	return 0;
}