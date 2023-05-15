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
vector<vector<int>> paper;

int dy[] = { -1, 0, 1, 0 };
int dx[] = { 0,1,0,-1 };

bool Cango(int y, int x)
{
	if (y < 0 || x < 0)
		return false;

	if (y >= N || x >= M)
		return false;

	return true;
}

void BFS(int y, int x)
{
	vector<vector<bool>> bfsFlag(N, vector<bool>(M, false));
	queue<pair<int, int>> q;
	q.push({ y,x });

	while (q.empty() == false)
	{
		auto& p = q.front();
		int nowY = p.first;
		int nowX = p.second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nextY = nowY + dy[i];
			int nextX = nowX + dx[i];

			if (Cango(nextY, nextX))
			{
				int next = paper[nextY][nextX];

				switch (next)
				{
				case -1:
				case 0:
					if (bfsFlag[nextY][nextX] == false)
					{
						bfsFlag[nextY][nextX] = true;
						paper[nextY][nextX] = -1;
						q.push({ nextY, nextX });
					}
					break;
				case 1:
				case 2:
				case 3:
				case 4:
					paper[nextY][nextX]++;
					break;
				}
			}
		}
	}

	return;
}

bool Check()
{
	bool flag = false;
	for (int y = 1; y < N - 1; y++)
	{
		for (int x = 1; x < M - 1; x++)
		{
			if (paper[y][x] >= 3)
			{
				paper[y][x] = 0;
				flag = true;
			}
			else if (paper[y][x] == 2)
			{
				paper[y][x] = 1;
			}
		}
	}
	return flag;
}

int main()
{
	Init;

	cin >> N >> M;
	paper = vector<vector<int>>(N, vector<int>(M));
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cin >> paper[y][x];
		}
	}

	int time = 0;
	while (true)
	{
		BFS(0, 0);
		if (Check() == false)
			break;
		time++;
	}

	cout << time;

	return 0;
}