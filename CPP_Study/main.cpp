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
#define INT32_HALF (INT32_MAX / 2)
#define Init cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
using int64 = long long;
using uint64 = unsigned long long;

int dy[] = { 1, 0, -1, 0 };
int dx[] = { 0, 1, 0, -1 };

int R, C, T;
vector<vector<int>> grid;
vector<vector<int>> tempVec;
pair<int, int> air;

bool CanGo(int y, int x)
{
	if (y < 0 || x < 0)
		return false;

	if (y >= R || x >= C)
		return false;

	return true;
}

void Diffusion(int y, int x)
{
	if (grid[y][x] == -1 || grid[y][x] == 0 || grid[y][x] < 5)
		return;

	int value = grid[y][x];
	int diffuse = value / 5;

	for (int i = 0; i < 4; i++)
	{
		int nextY = y + dy[i];
		int nextX = x + dx[i];

		if (CanGo(nextY, nextX) && grid[nextY][nextX] != -1)
		{
			tempVec[y][x] -= diffuse;
			tempVec[nextY][nextX] += diffuse;
;		}
	}
}

void AirCleaner()
{
	{
		int airY = air.first;

		grid[airY].insert(grid[airY].begin() + 1, 0);
		int value = grid[airY].back();
		grid[airY].pop_back();

		for (int y = airY - 1; y > 0; y--)
		{
			int temp = grid[y][C - 1]; 
			grid[y][C - 1] = value;
			value = temp;
		}

		grid[0].push_back(value);
		value = grid[0].front();
		grid[0].erase(grid[0].begin());

		for (int y = 1; y < airY; y++)
		{
			int temp = grid[y][0];
			grid[y][0] = value;
			value = temp;
		}
	}
	{
		int airY = air.second;

		grid[airY].insert(grid[airY].begin() + 1, 0);
		int value = grid[airY].back();
		grid[airY].pop_back();

		for (int y = airY + 1; y < R - 1; y++)
		{
			int temp = grid[y][C - 1];
			grid[y][C - 1] = value;
			value = temp;
		}

		grid[R - 1].push_back(value);
		value = grid[R - 1][0];
		grid[R - 1].erase(grid[R - 1].begin());

		for (int y = R - 2; y >= airY + 1; y--)
		{
			int temp = grid[y][0];
			grid[y][0] = value;
			value = temp;
		}
	}
}

int main()
{
	Init;

	cin >> R >> C >> T;

	grid = vector<vector<int>>(R, vector<int>(C));

	for (int y = 0; y < R; y++)
	{
		for (int x = 0; x < C; x++)
		{
			cin >> grid[y][x];

			if (grid[y][x] == -1)
			{
				air.first = y - 1;
				air.second = y;
			}
		}
	}

	for (int i = 0; i < T; i++)
	{
		tempVec = grid;
		for (int y = 0; y < R; y++)
		{
			for (int x = 0; x < C; x++)
			{
				Diffusion(y, x);
			}
		}
		grid = tempVec;
		AirCleaner();

		// cout << endl;
		// cout << i + 1 << "¹øÂ°";
		// cout << endl;
		// for (int y = 0; y < R; y++)
		// {
		// 	for (int x = 0; x < C; x++)
		// 	{
		// 		cout << tempVec[y][x] << " ";
		// 	}
		// 	cout << "                    ";
		// 	for (int x = 0; x < C; x++)
		// 	{
		// 		cout << grid[y][x] << " ";
		// 	}
		// 	cout << endl;
		// }
	}
	

	int sum = 0;
	for (int y = 0; y < R; y++)
	{
		for (int x = 0; x < C; x++)
		{
			sum += grid[y][x];
		}
	}

	cout << sum + 2;

	return 0;
}