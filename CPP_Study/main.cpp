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
#include <memory.h>
#define endl "\n"
#define INT32_HALF (2147483647 / 2)
#define Init cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
using int64 = long long;
using uint64 = unsigned long long;

struct Pos
{
	int y, x, crash;
};

int dx[] = { 0, 1, 0, -1 };
int dy[] = { -1, 0, 1, 0 };
int visited[1000][1000][2];

int N, M;
vector<vector<int>> matrix;

bool CheckDir(int y, int x)
{
	if (y < 0 || x < 0 || y >= N || x >= M)
		return false;

	return true;
}

int BFS(int y, int x)
{
	queue<Pos> q;
	q.push({ y,x,1 });
	visited[y][x][1] = true;

	while (q.empty() == false)
	{
		int nowY = q.front().y;
		int nowX = q.front().x;
		int crash = q.front().crash;

		q.pop();

		if (nowY == N - 1 && nowX == M - 1)
		{
			return visited[nowY][nowX][crash];
		}

		for (int i = 0; i < 4; i++)
		{
			int nextY = nowY + dy[i];
			int nextX = nowX + dx[i];

			if (CheckDir(nextY, nextX))
			{
				if (matrix[nextY][nextX] == 1 && crash == 1)
				{
					q.push({ nextY, nextX, 0 });
					visited[nextY][nextX][0] = visited[nowY][nowX][crash] + 1;
				}
				else if (matrix[nextY][nextX] == 0 && visited[nextY][nextX][crash] == 0)
				{
					q.push({ nextY, nextX, crash });
					visited[nextY][nextX][crash] = visited[nowY][nowX][crash] + 1;
				}
			}
		}
	}

	return -1;
}

int main()
{
	Init;

	cin >> N >> M;
	matrix = vector<vector<int>>(N, vector<int>(M));
	for (int y = 0; y < N; y++)
	{
		string num;
		cin >> num;
		for (int x = 0; x < M; x++)
		{
			matrix[y][x] = num[x] - '0';
		}
	}

	
	cout << BFS(0, 0);

	return 0;
}
