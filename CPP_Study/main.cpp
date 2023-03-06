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

#define endl "\n"
#define INT32_HALF (2147483647 / 2)
#define Init cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
using int64 = long long;
using uint64 = unsigned long long;

int N;
vector<vector<int>> grid;

enum STATE
{
	WIDTH,
	HEIGHT,
	DIAGONAL
};

struct Pos 
{
	int y;
	int x;
	STATE state;
};

bool CheckDir(int y, int x)
{
	if (y < 0 || x < 0 || y >= N || x >= N)
		return false;

	return true;
}

int _count = 0;
void MovePipe(int y, int x)
{
	queue<Pos> q;
	q.push({ y,x,WIDTH });

	while (q.empty() == false)
	{
		int nowY = q.front().y;
		int nowX = q.front().x;
		STATE nowState = q.front().state;
		q.pop();

		if (CheckDir(nowY, nowX) == false)
			continue;

		if (nowState == WIDTH || nowState == HEIGHT)
		{
			if (grid[nowY][nowX] == 1)
				continue;
		}
		else
		{
			if (grid[nowY - 1][nowX] == 1 || grid[nowY][nowX - 1] == 1 || grid[nowY][nowX] == 1)
				continue;
		}

		if (nowY == N - 1 && nowX == N - 1)
			_count++;

		int nextY;
		int nextX;
		STATE nextState;
		switch (nowState)
		{
		case STATE::WIDTH:
		{
			nextY = nowY;
			nextX = nowX + 1;
			nextState = WIDTH;
			q.push({ nextY, nextX, nextState });
			nextY = nowY + 1;
			nextX = nowX + 1;
			nextState = DIAGONAL;
			q.push({ nextY, nextX, nextState });
			break;
		}
		case STATE::HEIGHT:
		{
			nextY = nowY + 1;
			nextX = nowX;
			nextState = HEIGHT;
			q.push({ nextY, nextX, nextState });
			nextY = nowY + 1;
			nextX = nowX + 1;
			nextState = DIAGONAL;
			q.push({ nextY, nextX, nextState });
			break;
		}
		case STATE::DIAGONAL:
		{
			nextY = nowY;
			nextX = nowX + 1;
			nextState = WIDTH;
			q.push({ nextY, nextX, nextState });
			nextY = nowY + 1;
			nextX = nowX;
			nextState = HEIGHT;
			q.push({ nextY, nextX, nextState });
			nextY = nowY + 1;
			nextX = nowX + 1;
			nextState = DIAGONAL;
			q.push({ nextY, nextX, nextState });
			break;
		}
		}
	}
}

int main()
{
	Init;

	cin >> N;
	grid = vector<vector<int>>(N, vector<int>(N));
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> grid[y][x];
		}
	}

	MovePipe(0, 1);
	cout << _count;

	return 0;
}
