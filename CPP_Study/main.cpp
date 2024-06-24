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



struct Pos
{
	Pos& operator+=(const Pos& pos)
	{
		Y += pos.Y;
		X += pos.X;
	}
	Pos operator+(const Pos& pos)
	{
		return { Y + pos.Y, X + pos.X };
	}
	bool operator==(const Pos& pos)
	{
		return Y == pos.Y && X == pos.X;
	}
	bool operator!=(const Pos& pos)
	{
		return (*this == pos) == false;
	}
	bool operator<(const Pos& pos) const
	{
		if (pos.Y != Y)
			return Y < pos.Y;
		return X < pos.X;
	}

	int Y;
	int X;
};

array<Pos, 4> distList =
{
	Pos{1,0},
	Pos{0,1},
	Pos{-1,0},
	Pos{0,-1},
};

int n, m;

bool CanGo(vector<vector<int>>& map, const Pos& pos)
{
	if (pos.Y < 0 || pos.X < 0 || pos.Y >= n || pos.X >= m)
		return false;

	if (map[pos.Y][pos.X] == 0)
		return false;

	return true;
}

int main()
{
	cin >> n >> m;
	vector<vector<int>> map(n, vector<int>(m));
	queue<Pos> q;
	vector<vector<int>> ans(n, vector<int>(m, -1));
	vector<vector<bool>> discovered(n, vector<bool>(m, false));
	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			cin >> map[y][x];
			if (map[y][x] == 2)
			{
				q.push({ y,x });
				ans[y][x] = 0;
				discovered[y][x] = true;
			}
		}
	}

	while (q.empty() == false)
	{
		Pos p = q.front();
		q.pop();
		

		for (Pos dir : distList)
		{
			Pos nextDir = p + dir;
			if (CanGo(map, nextDir) == false || discovered[nextDir.Y][nextDir.X])
				continue;

			discovered[nextDir.Y][nextDir.X] = true;
			ans[nextDir.Y][nextDir.X] = ans[p.Y][p.X] + 1;
			q.push({ nextDir.Y, nextDir.X });
		}
	}

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			if (map[y][x] == 0)
				ans[y][x] = 0;
		}
	}
	

	for (int y = 0; y < n; y++)
	{
		for (int x = 0; x < m; x++)
		{
			cout << ans[y][x] << " ";
		}
		cout << endl;
	}
}