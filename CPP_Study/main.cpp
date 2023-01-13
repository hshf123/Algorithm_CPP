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

void Func(int sx, int ex, int sy, int ey)
{
	int firstNum = vec[sy][sx];
	bool diff = false;

	if (ex - sx == 1)
	{
		cout << firstNum;
		return;
	}

	for (int y = sy; y < ey; y++)
	{
		for (int x = sx; x < ex; x++)
		{
			if (vec[y][x] != firstNum)
			{
				diff = true;
				break;
			}
		}
	}

	if (diff == false)
	{
		cout << firstNum;
		return;
	}

	int n = (ex - sx) / 2;
	cout << "(";
	Func(sx, sx + n, sy, sy + n);
	Func(sx + n, ex, sy, sy + n);
	Func(sx, sx + n, sy + n, ey);
	Func(sx + n, ex, sy + n, ey);
	cout << ")";
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vec = vector<vector<int>>(N, vector<int>(N));
	for (int y = 0; y < N; y++)
	{
		string line;
		cin >> line;
		for (int x = 0; x < N; x++)
		{
			vec[y][x] = (int)(line[x] - '0');
		}
	}

	Func(0, N, 0, N);

	return 0;
}

