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

int R, C;
vector<vector<char>> vec;
vector<vector<bool>> discovered;

array<pair<int, int>, 4> dir =
{
	make_pair(0, 1),
	make_pair(1, 0),
	make_pair(0, -1),
	make_pair(-1, 0)
};

int ans = 0;

bool CanGo(const int& y, const int& x)
{
	if (y < 0 || x < 0 || y >= R || x >= C)
		return false;

	return true;
}

void DFS(const int& y, const int& x, unordered_set<char>& log, int count)
{
	ans = max(ans, count);

	for (auto& p : dir)
	{
		int nextY = p.first + y;
		int nextX = p.second + x;
		if (CanGo(nextY, nextX) == false || discovered[nextY][nextX] || log.find(vec[nextY][nextX]) != log.end())
			continue;

		log.insert(vec[nextY][nextX]);
		discovered[nextY][nextX] = true;
		DFS(nextY, nextX, log, count + 1);
		log.erase(vec[nextY][nextX]);
		discovered[nextY][nextX] = false;
	}
}

int main()
{
	Init;
	cin >> R >> C;
	vec.resize(R, vector<char>(C));
	discovered.resize(R, vector<bool>(C, false));
	for (int y = 0; y < R; y++)
	{
		string str;
		cin >> str;
		for (int x = 0; x < C; x++)
		{
			vec[y][x] = str[x];
		}
	}
	unordered_set<char> log;
	discovered[0][0] = true;
	log.insert(vec[0][0]);
	DFS(0, 0, log, 1);
	cout << ans;
}