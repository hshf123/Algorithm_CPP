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

vector<vector<int>> vec(128, vector<int>(128, -1));
pair<int, int> _count = make_pair(0, 0);

void Func(int sx, int ex, int sy, int ey)
{
	int start = vec[sy][sx];
	if (ex - sx == 1)
	{
		if (start == 0)
			_count.first++;
		else
			_count.second++;
		return;
	}

	bool check = true;
	for (int y = sy; y < ey; y++)
	{
		for (int x = sx; x < ex; x++)
		{
			if (start != vec[y][x])
			{
				check = false;
				break;
			}
		}
	}

	if (check)
	{
		if (start == 0)
			_count.first++;
		else
			_count.second++;
		return;
	}

	int n = (ex - sx) / 2;

	Func(sx, sx + n, sy, sy + n);

	Func(sx + n, ex, sy, sy + n);

	Func(sx, sx + n, sy + n, ey);

	Func(sx + n, ex, sy + n, ey);
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> vec[y][x];
		}
	}

	Func(0, N, 0, N);

	cout << _count.first << endl << _count.second << endl;

	return 0;
}

