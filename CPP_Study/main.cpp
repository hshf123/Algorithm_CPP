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

int dy[] = { 1,0,-1,0 };
int dx[] = { 0,1,0,-1 };
#pragma endregion

int R, C;
vector<vector<int>> vec;
vector<vector<pair<bool, bool>>> visited;
queue<pair<int, int>> q;
int ans = 0;

void BFS()
{
	while (q.empty() == false)
	{
		int y = q.front().first;
		int x = q.front().second;
		q.pop();

		if (visited[y][x].second == false)
			ans++;

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= R || nx >= C)
				continue;
			if (visited[ny][nx].first || vec[ny][nx] == 0)
				continue;
			visited[ny][nx].first = true;
			visited[ny][nx].second = true;
			q.push({ ny,nx });
		}
	}
}

int main()
{
	Init;
	
	cin >> R >> C;
	vec = vector<vector<int>>(R, vector<int>(C, 0));
	visited = vector<vector<pair<bool, bool>>>(R, vector<pair<bool, bool>>(C, {false, false}));

	for (int y = 0; y < R; y++)
	{
		for (int x = 0; x < C; x++)
		{
			char c;
			cin >> c;
			if (c == '#')
			{
				vec[y][x] = 1;
				q.push({ y,x });
				visited[y][x] = { false, false };
			}
		}
	}

	BFS();
	cout << ans;
	return 0;
}