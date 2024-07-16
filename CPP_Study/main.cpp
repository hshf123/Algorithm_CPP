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

int N;
vector<vector<int>> m;
vector<vector<int>> bishopPosList;
int dy[] = { 1, -1, -1, 1 };
int dx[] = { 1, 1, -1, -1 };
int ans = 0;

bool CanGo(const int& y, const int& x)
{
	if (y < 0 || x < 0 || y >= N || x >= N)
		return false;

	return true;
}
void Put(const int& y, const int& x)
{
	if (CanGo(y, x) == false)
		return;

	bishopPosList[y][x]++;

	int nextY = y;
	int nextX = x;
	// 오른쪽 위
	nextY = y + dy[0];
	nextX = x + dx[0];
	while (CanGo(nextY, nextX))
	{
		bishopPosList[nextY][nextX]++;
		nextY += dy[0];
		nextX += dx[0];
	}
	// 오른쪽 아래
	nextY = y + dy[1];
	nextX = x + dx[1];
	while (CanGo(nextY, nextX))
	{
		bishopPosList[nextY][nextX]++;
		nextY += dy[1];
		nextX += dx[1];
	}
	// 왼쪽 아래
	nextY = y + dy[2];
	nextX = x + dx[2];
	while (CanGo(nextY, nextX))
	{
		bishopPosList[nextY][nextX]++;
		nextY += dy[2];
		nextX += dx[2];
	}
	// 왼쪽 위
	nextY = y + dy[3];
	nextX = x + dx[3];
	while (CanGo(nextY, nextX))
	{
		bishopPosList[nextY][nextX]++;
		nextY += dy[3];
		nextX += dx[3];
	}
}
void CleanUp(const int& y, const int& x)
{
	if (CanGo(y, x) == false)
		return;

	bishopPosList[y][x] = max(bishopPosList[y][x] - 1, 0);

	int nextY = y;
	int nextX = x;
	// 오른쪽 위
	nextY = y + dy[0];
	nextX = x + dx[0];
	while (CanGo(nextY, nextX))
	{
		bishopPosList[nextY][nextX]--;
		nextY += dy[0];
		nextX += dx[0];
	}
	// 오른쪽 아래
	nextY = y + dy[1];
	nextX = x + dx[1];
	while (CanGo(nextY, nextX))
	{
		bishopPosList[nextY][nextX]--;
		nextY += dy[1];
		nextX += dx[1];
	}
	// 왼쪽 아래
	nextY = y + dy[2];
	nextX = x + dx[2];
	while (CanGo(nextY, nextX))
	{
		bishopPosList[nextY][nextX]--;
		nextY += dy[2];
		nextX += dx[2];
	}
	// 왼쪽 위
	nextY = y + dy[3];
	nextX = x + dx[3];
	while (CanGo(nextY, nextX))
	{
		bishopPosList[nextY][nextX]--;
		nextY += dy[3];
		nextX += dx[3];
	}
}

void BacktrackingWhite(const int& y, const int& x, int ret)
{
	if (CanGo(y, x) == false)
	{
		ans = max(ans, ret);
		return;
	}

	int nextY = y;
	int nextX = x + 2;
	if (nextX >= N)
	{
		nextY += 1;
		if (nextY % 2 == 0)
			nextX = 0;
		else
			nextX = 1;
	}

	if (m[y][x] == 1 && bishopPosList[y][x] == 0)
	{
		// 놓는다
		Put(y, x);
		BacktrackingWhite(nextY, nextX, ret + 1);
		CleanUp(y, x);
	}

	// 안놓는다
	BacktrackingWhite(nextY, nextX, ret);
}

void BacktrackingBlack(const int& y, const int& x, int ret)
{
	if (CanGo(y, x) == false)
	{
		ans = max(ans, ret);
		return;
	}

	int nextY = y;
	int nextX = x + 2;
	if (nextX >= N)
	{
		nextY += 1;
		if (nextY % 2 == 0)
			nextX = 1;
		else
			nextX = 0;
	}

	if (m[y][x] == 1 && bishopPosList[y][x] == 0)
	{
		// 놓는다
		Put(y, x);
		BacktrackingBlack(nextY, nextX, ret + 1);
		CleanUp(y, x);
	}

	// 안놓는다
	BacktrackingBlack(nextY, nextX, ret);
}

int main()
{
	Init;

	cin >> N;
	m = vector<vector<int>>(N, vector<int>(N));
	bishopPosList = vector<vector<int>>(N, vector<int>(N, 0));
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> m[y][x];
		}
	}

	int sum = 0;
	BacktrackingWhite(0, 0, 0);
	sum += ans;
	ans = 0;
	BacktrackingBlack(0, 1, 0);
	sum += ans;

	cout << sum;
	return 0;
}