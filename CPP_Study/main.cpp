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
	int cnt = 0;
	int flag = 0;
};

int W, H;
vector<vector<int>> vec;
vector<vector<vector<int>>> visited;
Pos startPos;
Pos knightPos;
vector<Pos> strawberryPosList;

int dy[] = { 1,0,-1,0 };
int dx[] = { 0,1,0,-1 };

bool CanMove(const int& y, const int& x, const int& flag)
{
	if (y >= H || x >= W || x < 0 || y < 0)
		return false;

	if (vec[y][x] == 1)
		return false;

	if (visited[flag][y][x] != 0)
		return false;

	if (flag == 0 && vec[y][x] == 3)
		return false;

	return true;
}

void BFS()
{
	queue<Pos> q;
	q.push(startPos);
	q.push(knightPos);
	while (q.empty() == false)
	{
		Pos p = q.front();
		q.pop();
		int y = p.y;
		int x = p.x;
		int cnt = p.cnt;
		int flag = p.flag;

		for (int i = 0; i < 4; i++)
		{
			int nextY = y + dy[i];
			int nextX = x + dx[i];
			if (CanMove(nextY, nextX, flag) == false)
				continue;

			// 꺼낼 때 말고 여기서 방문체크 해줘야 훨씬 빠름 (중복 방지)
			visited[flag][nextY][nextX] = cnt + 1;
			q.push({ nextY, nextX, cnt + 1, flag });
		}
	}
}

int main()
{
	Init;

	cin >> W >> H;
	vec = vector<vector<int>>(H, vector<int>(W));
	visited = vector<vector<vector<int>>>(2, vector<vector<int>>(H, vector<int>(W)));
	for (int y = 0; y < H; y++)
	{
		for (int x = 0; x < W; x++)
		{
			int n;
			cin >> n;
			vec[y][x] = n;
			switch (n)
			{
			case 2:
				startPos = { y,x,1,0 };
				break;
			case 3:
				knightPos = { y,x,1,1 };
				break;
			case 4:
				strawberryPosList.push_back({ y,x });
				break;
			default:
				break;
			}
		}
	}

	BFS();

	int ret = INT32_MAX;
	for (Pos& pos : strawberryPosList)
	{
		if (visited[0][pos.y][pos.x] == 0 || visited[1][pos.y][pos.x] == 0)
			continue;
		ret = min(ret, visited[0][pos.y][pos.x] - 1 + visited[1][pos.y][pos.x] - 1);
	}

	cout << ret;

	return 0;
}