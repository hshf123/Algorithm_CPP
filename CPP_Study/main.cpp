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

bool cache[100][100];

bool Solve(const vector<vector<int>>& board, const int& y, const int& x, const int& n)
{
	// 목적지에 도달했으면 끝
	if (y == n - 1 && x == n - 1)
		return true;
	// 맵 밖으로 나가면 끝
	if (y < 0 || x < 0 || y >= n || x >= n)
		return false;

	// 캐시 확인
	bool& ret = cache[y][x];
	if (ret != false)
		return ret;

	// 움직여야하는 칸
	const int& moveCount = board[y][x];
	return ret = Solve(board, y + moveCount, x, n) || Solve(board, y, x + moveCount, n);
}

int main()
{
	Init;
	
	int C;
	cin >> C;

	vector<bool> ans(C, false);
	for (int c = 0; c < C; c++)
	{
		int n;
		cin >> n;
		vector<vector<int>> board(n, vector<int>(n));
		for (int y = 0; y < n; y++)
			for (int x = 0; x < n; x++)
				cin >> board[y][x];

		::memset(cache, false, sizeof(cache));

		ans[c] = Solve(board, 0, 0, n);
	}

	for (const bool& n : ans)
		cout << (n ? "YES" : "NO") << endl;
	
	return 0;
}