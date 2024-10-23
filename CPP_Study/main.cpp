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
};

int N, M, K;
vector<vector<int>> vec;
vector<vector<bool>> visited;

int dy[] = { 1,0,-1,0 };
int dx[] = { 0,1,0,-1 };

int BFS(const int& y, const int& x)
{
	if (visited[y][x])
		return 0;

	queue<Pos> q;
	q.push({ y,x });
	visited[y][x] = true;
	int ret = 0;
	while (q.empty() == false)
	{
		int y = q.front().y;
		int x = q.front().x;
		q.pop();
		ret++;

		for (int i = 0; i < 4; i++)
		{
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= M)
				continue;
			if (vec[ny][nx] == 0)
				continue;
			if (visited[ny][nx])
				continue;
			visited[ny][nx] = true;
			q.push({ ny,nx });
		}
	}
	return ret;
}

int main()
{
	Init;

	cin >> N >> M >> K;
	vec = vector<vector<int>>(N, vector<int>(M, 0));
	visited = vector<vector<bool>>(N, vector<bool>(M, false));
	vector<pair<int, int>> posList;
	for (int i = 0; i < K; i++)
	{
		int y, x;
		cin >> y >> x;
		vec[y - 1][x - 1] = 1;
		posList.push_back({ y - 1, x - 1 });
	}

	int ans = 0;
	for (const auto& p : posList)
	{
		ans = max(ans, BFS(p.first, p.second));
	}
	cout << ans;
	return 0;
}