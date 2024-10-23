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

struct Pos
{
	int y = 0;
	int x = 0;
	int dir = -1;
	int cnt = 0;

	bool operator==(const Pos& other) const
	{
		return y == other.y && x == other.x;
	}
};

int n;
vector<vector<int>> vec;
vector<vector<int>> visited;
Pos tom;
Pos jerry;
int ans = INT32_MAX;

int dy[] = { 1,0,-1,0 };
int dx[] = { 0,1,0,-1 };

void BFS()
{
	queue<Pos> q;
	q.push(tom);
	while (q.empty() == false)
	{
		auto p = q.front();
		q.pop();

		if (p == jerry)
			ans = min(ans, p.cnt);

		for (int i = 0; i < 4; i++)
		{
			int ny = p.y + dy[i];
			int nx = p.x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= n || vec[ny][nx] == 1)
				continue;
			int ncnt = p.cnt;
			if (i != p.dir)
				ncnt++;
			if (visited[ny][nx] < ncnt)
				continue;
			visited[ny][nx] = ncnt;
			q.push(Pos{ ny, nx, i, ncnt });
		}
	}
}

int main()
{
	Init;

	cin >> n;
	vec = vector<vector<int>>(n, vector<int>(n, 0));
	visited = vector<vector<int>>(n, vector<int>(n, INT32_MAX));
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < n; x++)
		{
			cin >> vec[y][x];
		}
	}

	int ty, tx, jy, jx;
	cin >> ty >> tx >> jy >> jx;
	tom.y = ty - 1;
	tom.x = tx - 1;
	jerry.y = jy - 1;
	jerry.x = jx - 1;
	
	BFS();

	cout << (ans == INT32_MAX ? -1 : ans - 1);

	return 0;
}