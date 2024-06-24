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
#define Init cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
using int64 = long long;
using uint64 = unsigned long long;
#pragma endregion

int N, M;

struct Pos
{
	Pos operator+(const Pos& other)
	{
		return { y + other.y , x + other.x };
	}

	int y = 0;
	int x = 0;
};

array<Pos, 4> dir =
{
	Pos{1,0},
	Pos{0,1},
	Pos{-1,0},
	Pos{0,-1}
};

bool CanGo(Pos pos)
{
	if (pos.y < 0 || pos.x < 0 || pos.y >= N || pos.x >= M)
		return false;

	return true;
}

int main()
{
	cin >> N >> M;

	vector<vector<char>> m(N, vector<char>(M));
	vector<vector<bool>> discovered(N, vector<bool>(M, false));

	queue<Pos> q;

	for (int y = 0; y < N; y++)
	{
		string str;
		cin >> str;
		for (int x = 0; x < M; x++)
		{
			m[y][x] = str[x];
			if (m[y][x] == 'I')
			{
				q.push({ y,x });
				discovered[y][x] = true;
			}
		}
	}

	int count = 0;
	while (q.empty() == false)
	{
		Pos p = q.front();
		q.pop();

		if (m[p.y][p.x] == 'P')
			++count;

		for (Pos d : dir)
		{
			Pos nd = p + d;
			if (CanGo(nd) == false || m[nd.y][nd.x] == 'X' || discovered[nd.y][nd.x])
				continue;

			discovered[nd.y][nd.x] = true;
			q.push({ nd.y, nd.x });
		}
	}

	if (count == 0)
	{
		cout << "TT";
		return 0;
	}

	cout << count;
}