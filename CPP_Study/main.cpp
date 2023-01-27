#include <iostream>
using namespace std;
#define endl "\n"
using int64 = long long;
using uint64 = unsigned long long;

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

#include <tchar.h>

int N;
vector<vector<int>> _map;
vector<vector<int>> _dist;
vector<vector<bool>> visited;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

int level = 2;
int eatCount = 0;
pair<int, int> shark;
pair<int, int> target;

void Init()
{
	target = shark;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			_dist[y][x] = -1;
			visited[y][x] = false;
		}
	}
}

bool CheckDir(int y, int x)
{
	if (y < 0 || x < 0 || y >= N || x >= N)
		return false;

	if (_map[y][x] > level)
		return false;

	if (visited[y][x])
		return false;

	return true;
}

void BFS(pair<int,int> shark)
{
	int y = shark.first;
	int x = shark.second;

	visited[y][x] = true;
	_dist[y][x] = 0;

	queue<pair<int, int>> q;
	q.push({ y,x });

	while (q.empty() == false)
	{
		pair<int, int> now = q.front();
		q.pop();

		y = now.first;
		x = now.second;

		if (_map[y][x] != 0 && _map[y][x] < level)
		{
			if (target != shark)
			{
				if (_dist[y][x] < _dist[target.first][target.second])
				{
					target = { y,x };
				}
				else if (_dist[y][x] == _dist[target.first][target.second])
				{
					if (y < target.first)
					{
						target = { y,x };
					}
					else if(y == target.first)
					{
						if (x < target.second)
						{
							target = { y,x };
						}
					}
				}
			}
			else
			{
				target = { y,x };
			}
		}

		for (int i = 0; i < 4; i++)
		{
			int ny = now.first + dy[i];
			int nx = now.second + dx[i];

			if (CheckDir(ny, nx))
			{
				visited[ny][nx] = true;
				_dist[ny][nx] = _dist[y][x] + 1;
				q.push({ ny,nx });
			}
		}
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	_map = vector<vector<int>>(N, vector<int>(N));
	_dist = vector<vector<int>>(N, vector<int>(N));
	visited = vector<vector<bool>>(N, vector<bool>(N, false));

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> _map[y][x];
			if (_map[y][x] == 9)
			{
				shark = { y,x };
				_map[y][x] = 0;
			}
		}
	}

	int count = 0;
	int t = 0;
	while (true)
	{
		Init();

		BFS(shark);

		if (target != shark)
		{
			// ≈∏∞Ÿ¿Ã ¿÷¿Ω
			count += _dist[target.first][target.second];
			_map[target.first][target.second] = 0;
			shark = target;
			eatCount++;
			if (eatCount == level)
			{
				level++;
				eatCount = 0;
			}
		}
		else
		{
			cout << count;
			break;
		}
	}

	return 0;
}
