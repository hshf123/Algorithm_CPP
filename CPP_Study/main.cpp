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

int N, M;
vector<vector<int>> vec;
vector<vector<bool>> bools;

int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, 1, 0, -1 };

bool CheckDir(int y, int x)
{
	if (y < 0 || x < 0 || y >= N || x >= M)
		return false;

	return true;
}

int ans = 0;
void DFS(int y, int x, int depth, int score)
{
	bools[y][x] = true;

	if (depth == 3)
	{
		ans = max(ans, score);
		bools[y][x] = false;
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int nextY = y + dy[i];
		int nextX = x + dx[i];
		if (CheckDir(nextY, nextX) && bools[nextY][nextX] == false)
		{
			bools[nextY][nextX] = true;
			DFS(nextY, nextX, depth + 1, score + vec[nextY][nextX]);
			bools[nextY][nextX] = false;
		}
	}

	if (x - 1 >= 0 && y - 1 >= 0 && y + 1 < N) 
	{ //っ
		ans = max(ans, (vec[y][x - 1] + vec[y][x] + vec[y + 1][x] + vec[y - 1][x]));
	}
	if (y - 1 >= 0 && y + 1 < N && x + 1 < M) 
	{ //た
		ans = max(ans, (vec[y][x + 1] + vec[y][x] + vec[y + 1][x] + vec[y - 1][x]));
	}
	if (x - 1 >= 0 && x + 1 < M && y + 1 < N) 
	{ //で
		ans = max(ans, (vec[y + 1][x] + vec[y][x] + vec[y][x - 1] + vec[y][x + 1]));
	}
	if (y - 1 >= 0 && x - 1 >= 0 && x + 1 < M) 
	{ //ぬ
		ans = max(ans, (vec[y - 1][x] + vec[y][x] + vec[y][x - 1] + vec[y][x + 1]));
	}

	bools[y][x] = false;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	vec = vector<vector<int>>(N, vector<int>(M));
	bools = vector<vector<bool>>(N, vector<bool>(M, false));

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			cin >> vec[y][x];
		}
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			DFS(y, x, 0, vec[y][x]);
		}
	}

	cout << ans;

	return 0;
}

