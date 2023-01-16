#include <iostream>
using namespace std;
#define endl "\n"
using int64 = long long;

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

int X, Y, Z;
vector<vector<vector<int>>> box;
				// 위 아래 왼쪽 오른쪽 앞 뒤
int xdir[6] = { 0, 0, -1, 1, 0, 0 };
int ydir[6] = { 0, 0, 0, 0, 1, -1 };
int zdir[6] = { 1, -1, 0, 0, 0, 0 };

bool CheckDir(int z, int y, int x)
{
	if (z < 0 || z >= Z || y < 0 || y >= Y || x < 0 || x >= X)
		return false;

	if (box[z][y][x] == -1 || box[z][y][x] == 1)
		return false;

	return true;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> X >> Y >> Z;
	box = vector<vector<vector<int>>>(Z, vector<vector<int>>(Y, vector<int>(X)));
	vector<pair<int, pair<int, int>>> xyz;

	for (int z = 0; z < Z; z++)
	{
		for (int y = 0; y < Y; y++)
		{
			for (int x = 0; x < X; x++)
			{
				int a;
				cin >> a;
				box[z][y][x] = a;
				if (a == 1)
					xyz.push_back({ z,{y,x} });
			}
		}
	}

	queue<pair<int, pair<int, int>>> q;
	vector<vector<vector<bool>>> discovered = vector<vector<vector<bool>>>(Z, vector<vector<bool>>(Y, vector<bool>(X, false)));

	for (pair<int, pair<int,int>>& p : xyz)
	{
		int z = p.first;
		int y = p.second.first;
		int x = p.second.second;

		q.push({ z,{y,x} });
	}

	while (q.empty() == false)
	{
		pair<int, pair<int, int>> now = q.front();
		q.pop();

		int nowZ = now.first;
		int nowY = now.second.first;
		int nowX = now.second.second;

		for (int i = 0; i < 6; i++)
		{
			int nextZ = nowZ + zdir[i];
			int nextY = nowY + ydir[i];
			int nextX = nowX + xdir[i];
			if (CheckDir(nextZ, nextY, nextX) && discovered[nextZ][nextY][nextX] == false)
			{
				q.push({ nextZ, {nextY, nextX} });
				discovered[nextZ][nextY][nextX] = true;
				int day = box[nowZ][nowY][nowX] + 1;
				// 0이 아니어야함. 그 중 최솟값
				if (box[nextZ][nextY][nextX] != 0)
				{
					if (day < box[nextZ][nextY][nextX])
						box[nextZ][nextY][nextX] = day;
				}
				else
					box[nextZ][nextY][nextX] = day;
			}
		}
	}

	int max = 0;
	for (int z = 0; z < Z; z++)
	{
		for (int y = 0; y < Y; y++)
		{
			for (int x = 0; x < X; x++)
			{
				if (box[z][y][x] == 0)
				{
					cout << -1 << endl;
					return 0;
				}

				if (max < box[z][y][x])
					max = box[z][y][x];
			}
		}
	}

	cout << max - 1 << endl;

	return 0;
}

