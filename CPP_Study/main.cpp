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

int N, K;
unordered_map<int, pair<int, int>> backpack;
vector<vector<int>> cache;

int DP()
{
	for (int y = 1; y < N + 1; y++)
	{
		for (int x = 1; x < K + 1; x++)
		{
			cache[y][x] = max(cache[y - 1][x], cache[y][x - 1]);
			if (x - backpack[y].first >= 0)
			{
				cache[y][x] = max(cache[y - 1][x], cache[y - 1][x - backpack[y].first] + backpack[y].second);
			}
			else
			{
				cache[y][x] = cache[y - 1][x];
			}
		}
	}

	return cache[N][K];
}

int main()
{
	Init;

	cin >> N >> K;
	cache = vector<vector<int>>(N + 1, vector<int>(K + 1, 0));
	for (int i = 0; i < N; i++)
	{
		int W, V;
		cin >> W >> V;
		backpack[i + 1] = { W,V };
	}

	cout << DP();

	return 0;
}
