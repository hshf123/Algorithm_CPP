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
#define INT32_HALF (2147483647 / 2)
#define Init cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
using int64 = long long;
using uint64 = unsigned long long;

int N, M;
vector<vector<int>> _map;
vector<pair<int, int>> city;

vector<pair<int, int>> chicken;
vector<pair<int, int>> output;
vector<bool> visited;

int dy[] = { 1,0,-1,0 };
int dx[] = { 0,1,0,-1 };

int ans = INT32_MAX;

bool CheckDir(int y, int x)
{
	if (y < 0 || x < 0 || y >= N || x >= N)
		return false;
	return true;
}

int FindChickenPath2(int y, int x)
{
	int ret = INT32_MAX;
	for (pair<int, int> p : output)
	{
		int cy = p.first;
		int cx = p.second;

		ret = min(ret, abs(y - cy) + abs(x - cx));
	}

	return ret;
}

int FindChickenPath(int y, int x)
{
	bool mapVisited[50][50];
	::memset(mapVisited, false, sizeof(mapVisited));
	priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> q;
	q.push({ 0, {y,x} });
	mapVisited[y][x] = true;

	while (q.empty() == false)
	{
		int dist = q.top().first;
		int nowY = q.top().second.first;
		int nowX = q.top().second.second;
		q.pop();

		for (pair<int,int> p : output)
		{
			int cy = p.first;
			int cx = p.second;

			if (cy == nowY && cx == nowX)
			{
				return dist;
			}
		}

		for (int i = 0; i < 4; i++)
		{
			int nextY = nowY + dy[i];
			int nextX = nowX + dx[i];

			if (CheckDir(nextY, nextX) && mapVisited[nextY][nextX] == false)
			{
				mapVisited[nextY][nextX] = true;
				q.push({ dist + 1, {nextY, nextX} });
			}
		}
	}
}

void BackTracking(int n, int count)
{
	if (count == M)
	{
		int sum = 0;
		for (pair<int, int> p : city)
		{
			int y = p.first;
			int x = p.second;
			sum += FindChickenPath2(y, x);
		}
		ans = min(ans, sum);
		return;
	}

	for (int i = n; i < chicken.size(); i++)
	{
		if (visited[i] == false)
		{
			visited[i] = true;
			output[count] = chicken[i];
			BackTracking(i, count + 1);
			visited[i] = false;
		}
	}
}

int main()
{
	Init;

	cin >> N >> M;
	_map = vector<vector<int>>(N, vector<int>(N));
	output = vector<pair<int, int>>(M);
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> _map[y][x];
			if (_map[y][x] == 2)
				chicken.push_back({ y,x });
			else if (_map[y][x] == 1)
				city.push_back({ y,x });
		}
	}

	visited = vector<bool>(chicken.size(), false);
	BackTracking(0, 0);

	cout << ans;

	return 0;
}
