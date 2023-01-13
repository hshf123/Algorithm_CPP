#include <iostream>
using namespace std;
#define endl "\n"
using int64 = long long;

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

int N, M;
vector<vector<int>> _map;
vector<vector<int>> dist;
vector<vector<bool>> visited;
int xdir[4] = { 0, 1, 0, -1 };
int ydir[4] = { -1, 0, 1, 0 };

bool CheckDir(int nextY, int nextX)
{
	if (nextY < 0 || nextX < 0 || nextY >= N || nextX >= M)
		return false;
	if (visited[nextY][nextX] == true)
		return false;
	if (_map[nextY][nextX] == 0)
		return false;

	return true;
}

void BFS(int y, int x)
{
	visited[y][x] = true;

	queue<pair<int, int>> q;
	q.push(make_pair(y, x));

	while (q.empty() == false)
	{
		auto here = q.front();
		q.pop();

		if (here.first == N - 1 && here.second == M - 1)
			return;

		for (int i = 0; i < 4; i++)
		{
			int nextY = here.first + ydir[i];
			int nextX = here.second + xdir[i];

			if (CheckDir(nextY, nextX) == true)
			{
				dist[nextY][nextX] = dist[here.first][here.second] + 1;
				q.push(make_pair(nextY, nextX));
				visited[nextY][nextX] = true;
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	_map = vector<vector<int>>(N, vector<int>(M));
	dist = vector<vector<int>>(N, vector<int>(M, 0));
	visited = vector<vector<bool>>(N, vector<bool>(M, false));
	for (int y = 0; y < N; y++)
	{
		string line;
		cin >> line;
		for (int x = 0; x < M; x++)
		{
			_map[y][x] = (int)(line[x] - '0');
		}
	}
		
	BFS(0, 0);
	cout << dist[N - 1][M - 1] + 1;

	return 0;
}

