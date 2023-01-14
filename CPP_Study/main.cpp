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

int N;
vector<vector<int>> _map;
vector<int> _linked;
vector<vector<bool>> _visited;
int _count = 0;

int ydir[4] = { 1, 0, -1, 0 };
int xdir[4] = { 0, 1, 0 ,-1 };

bool CheckDir(int y, int x)
{
	if (y < 0 || x < 0 || y >= N || x >= N)
		return false;

	if (_map[y][x] == 0)
		return false;

	if (_visited[y][x] == true)
		return false;

	return true;
}

void BFS(int y, int  x)
{
	if (_visited[y][x] == true)
		return;

	// 현재 위치를 방문 상태로
	_visited[y][x] = true;

	// 현재 위치는 집이 아니다.
	if (_map[y][x] == 0)
		return;

	_count++; // 전체 연결된 단지 수 카운트

	int linked = 1; // 연결된 집의 수 카운트

	queue<pair<int, int>> q;
	q.push(make_pair(y, x));

	while (q.empty() == false)
	{
		pair<int, int> now = q.front();
		q.pop();
		int hereY = now.first;
		int hereX = now.second;

		for (int i = 0; i < 4; i++)
		{
			int nextY = hereY + ydir[i];
			int nextX = hereX + xdir[i];

			if (CheckDir(nextY, nextX))
			{
				q.push(make_pair(nextY, nextX));
				_visited[nextY][nextX] = true;
				linked++;
			}
		}
	}

	_linked.push_back(linked);
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	// 1은 집이 있는 곳, 0은 집이 없는 곳
	// 연결이라 함은 상하좌우로 붙어있는 경우

	cin >> N;

	_map = vector<vector<int>>(N, vector<int>(N));
	_visited = vector<vector<bool>>(N, vector<bool>(N, false));

	for (int y = 0; y < N; y++)
	{
		string line;
		cin >> line;
		for (int x = 0; x < N; x++)
		{
			_map[y][x] = (int)(line[x] - '0');
		}
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			BFS(y, x);
		}
	}

	cout << _count << endl;
	sort(_linked.begin(), _linked.end());
	for (int& n : _linked)
		cout << n << endl;

	return 0;
}

