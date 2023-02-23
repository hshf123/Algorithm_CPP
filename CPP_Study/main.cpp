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
#define endl "\n"
#define INT32_HALF (2147483647 / 2)
#define Init cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
using int64 = long long;
using uint64 = unsigned long long;

int N, M;
vector<vector<int>> board;
vector<vector<int>> cache;

int SectionSum(int y, int x)
{
	if (y < 0 || x < 0)
		return 0;

	int& ret = cache[y][x];
	if (ret != -1)
		return ret;

	int sum = 0;
	int yi = 0;
	int xi = 0;
	while (yi <= y)
	{
		sum += board[yi][xi];

		if (yi == 0)
			cache[yi][xi] = sum;

		if (yi > 0)
			cache[yi][xi] = sum - cache[yi - 1][x] + cache[yi - 1][xi];

		xi++;
		if (xi > x)
		{
			cache[yi][xi - 1] = sum;

			xi = 0;
			yi++;
		}
	}

	return ret = sum;
}

int main()
{
	Init;

	cin >> N >> M;
	board = vector<vector<int>>(N, vector<int>(N));
	cache = vector<vector<int>>(N, vector<int>(N, -1));
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cin >> board[y][x];
		}
	}
	for (int i = 0; i < M; i++)
	{
		int x1, y1, x2, y2;
		cin >> y1 >> x1 >> y2 >> x2;
		cout << SectionSum(y2 - 1, x2 - 1) - SectionSum(y2 - 1, x1 - 2) - SectionSum(y1 - 2, x2 - 1) + SectionSum(y1 - 2, x1 - 2) << endl;
	}
	
	return 0;
}
