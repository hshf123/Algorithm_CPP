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

#define endl "\n"
#define INT32_HALF (INT32_MAX / 2)
#define Init cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
using int64 = long long;
using uint64 = unsigned long long;

int N, M;
vector<vector<int>> MAP;
vector<vector<int>> SIM;
int maxCount = -1;
stack<pair<int, int>> parent;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0, 1, 0, -1 };

bool CanGo(int y, int x)
{
	if (y < 0 || x < 0 || y >= N || x >= M)
		return false;

	return true;
}

int Simulation()
{
	SIM = MAP;

	queue<pair<int, int>> q;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (SIM[y][x] == 2)
			{
				q.push({ y,x });
			}
		}
	}

	while (q.empty() == false)
	{
		auto& p = q.front();
		int nowY = p.first;
		int nowX = p.second;
		q.pop();
		SIM[nowY][nowX] = 2;

		for (int i = 0; i < 4; i++)
		{
			int nextY = nowY + dy[i];
			int nextX = nowX + dx[i];

			if (CanGo(nextY, nextX) && SIM[nextY][nextX] == 0)
			{
				q.push({ nextY, nextX });
			}
		}
	}

	int count = 0;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			count += (SIM[y][x] == 0 ? 1 : 0);
		}
	}
	return count;
}

void SetWall(int count)
{
	if (count == 3)
	{
		maxCount = max(maxCount, Simulation());
		return;
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			if (MAP[y][x] == 0)
			{
				MAP[y][x] = 1;
				SetWall(count + 1);
				MAP[y][x] = 0;
			}
		}
	}
}

int main()
{
	Init;

	cin >> N >> M;

	MAP = vector<vector<int>>(N, vector<int>(M));
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cin >> MAP[y][x];
		}
	}

	SetWall(0);
	
	cout << maxCount;

	return 0;
}