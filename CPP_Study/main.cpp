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

struct Log
{
	vector<int> ABC = vector<int>(3, 0);

	int Get() const
	{
		if (count(ABC.begin(), ABC.end(), 0) > 0)
			return 0;

		return max(ABC[0], max(ABC[1], ABC[2]));
	}

	bool operator<(const Log& other)
	{
		return Get() < other.Get();
	}
};

struct Pos
{
	int y = 0;
	int x = 0;
	int w = 0;
	int c = 0;
};

int N;
vector<vector<int>> vec;
vector<vector<Log>> logs;

pair<int, int> A;
pair<int, int> B;
pair<int, int> C;

void BFS()
{
	queue<Pos> q;
	q.push({ A.first - 1, A.second - 1, 0, 0 });
	q.push({ B.first - 1, B.second - 1, 1, 0 });
	q.push({ C.first - 1, C.second - 1, 2, 0 });
	while (q.empty() == false)
	{
		Pos p =q.front();
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int ny = p.y + dy[i];
			int nx = p.x + dx[i];
			if (ny < 0 || nx < 0 || ny >= N || nx >= N)
				continue;
			if (vec[ny][nx] == 1)
				continue;
			if (logs[ny][nx].ABC[p.w] != 0)
				continue;
			logs[ny][nx].ABC[p.w] = p.c;
			q.push({ ny, nx, p.w, p.c + 1 });
		}
	}
}

int main()
{
	Init;

	cin >> N;
	vec = vector<vector<int>>(N, vector<int>(N, 0));
	logs = vector<vector<Log>>(N, vector<Log>(N));
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> vec[y][x];
		}
	}

	cin >> A.first >> A.second;
	cin >> B.first >> B.second;
	cin >> C.first >> C.second;

	BFS();

	vector<int> v;
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			if (logs[y][x].Get() == 0)
				continue;
			v.push_back(logs[y][x].Get());
		}
	}
	if (v.empty())
	{
		cout << -1;
		return 0;
	}

	sort(v.begin(), v.end());
	int cnt = count(v.begin(), v.end(), v.front());
	cout << cnt;

	return 0;
}