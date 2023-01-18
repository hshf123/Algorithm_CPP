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
#include <functional>

int N;
vector<vector<int>> vec;
vector<vector<int>> cwvec;
vector<vector<bool>> visited;
vector<vector<bool>> cwvisited;
map<int, int> counts;
map<int, int> cwcounts;

int ydir[4] = { 1,0,0,-1 };
int xdir[4] = { 0,1,-1,0 };

bool CheckDir(int y, int x,int n)
{
	if (y < 0 || y >= N || x < 0 || x >= N)
		return false;

	return true;
}

void BFS(int y, int x, vector<vector<int>>& ve, vector<vector<bool>>& vis, map<int,int>& _map)
{
	if (vis[y][x] == true)
		return;

	vis[y][x] = true;

	int n = ve[y][x];
	auto findIt = _map.find(n);
	findIt->second++;

	queue<pair<int,int>> qnorm;
	qnorm.push({ y,x });

	while (qnorm.empty() == false)
	{
		auto now = qnorm.front();
		qnorm.pop();
		int n = ve[now.first][now.second];

		for (int i = 0; i < 4; i++)
		{
			int nextY = now.first + ydir[i];
			int nextX = now.second + xdir[i];

			if (CheckDir(nextY, nextX, n) && (n == ve[nextY][nextX]) && (vis[nextY][nextX] == false))
			{
				qnorm.push({nextY, nextX});
				vis[nextY][nextX] = true;
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
	vec = vector<vector<int>>(N, vector<int>(N));
	cwvec = vector<vector<int>>(N, vector<int>(N));
	visited = vector<vector<bool>>(N, vector<bool>(N, false));
	cwvisited = vector<vector<bool>>(N, vector<bool>(N, false));
	for (int y = 0; y < N; y++)
	{
		string line;
		cin >> line;
		for (int x = 0; x < N; x++)
		{
			char c = line[x];
			if (c == 'R')
			{
				vec[y][x] = 0;
				cwvec[y][x] = 0;
			}
			else if (c == 'G')
			{
				vec[y][x] = 1;
				cwvec[y][x] = 0;
			}
			else
			{
				vec[y][x] = 2;
				cwvec[y][x] = 2;
			}
		}
	}

	counts.insert({ 0, 0 });
	counts.insert({ 1, 0 });
	counts.insert({ 2, 0 });
	cwcounts.insert({ 0, 0 });
	cwcounts.insert({ 2, 0 });

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			BFS(y, x, vec, visited, counts);
			BFS(y, x, cwvec, cwvisited, cwcounts);
		}
	}

	auto it = counts.begin();
	int count = it++->second;
	count += it++->second;
	count += it->second;
	it = cwcounts.begin();
	int cwcount = it++->second;
	cwcount += it->second;

	cout << count << " " << cwcount;

	return 0;
}

