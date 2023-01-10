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

vector<vector<int>> vec;
vector<int> _count(3, 0);

void Func(int sx, int ex, int sy, int ey)
{
	int firstNum = vec[sy][sx];
	if (sx == ex - 1)
	{
		_count[firstNum + 1]++;
		return;
	}

	bool div = false;
	for (int y = sy; y < ey; y++)
	{
		for (int x = sx; x < ex; x++)
		{
			if (firstNum != vec[y][x])
			{
				div = true;
				break;
			}
		}
	}

	if (div == false)
	{
		_count[firstNum + 1]++;
		return;
	}

	int n = (ey - sy) / 3;
	Func(sx,			sx + n,				sy,				sy + n);
	Func(sx + n,		sx + (n * 2),		sy,				sy + n);
	Func(sx + (n * 2),	ex,					sy,				sy + n);

	Func(sx,			sx + n,				sy + n,			sy + (n * 2));
	Func(sx + n,		sx + (n * 2),		sy + n,			sy + (n * 2));
	Func(sx + (n * 2),	ex,					sy + n,			sy + (n * 2));

	Func(sx,			sx + n,				sy + (n * 2),			ey);
	Func(sx + n,		sx + (n * 2),		sy + (n * 2),			ey);
	Func(sx + (n * 2),	ex,					sy + (n * 2),			ey);
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	vec = vector<vector<int>>(N + 1, vector<int>(N + 1));

	for (int y = 0; y < N; y++)
		for (int x = 0; x < N; x++)
			cin >> vec[y][x];

	Func(0, N, 0, N);

	for (int& n : _count)
		cout << n << endl;

	return 0;
}

