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

int dy[] = { 1,0,-1,0 };
int dx[] = { 0,1,0,-1 };
#pragma endregion

int N, M;
vector<vector<int>> vec;
vector<vector<int>> cache;

int main()
{
	Init;
	
	cin >> N >> M;
	vec = vector<vector<int>>(N, vector<int>(M, 0));
	cache = vector<vector<int>>(N, vector<int>(M, 0));
	for (int y = 0; y < N; y++)
	{
		string str;
		cin >> str;
		for (int x = 0; x < M; x++)
		{
			vec[y][x] = str[x] - '0';
			int& n = vec[y][x];
			if (n == 1)
			{
				int& dp = cache[y][x];
				dp = INT32_MAX;
				if (y > 0 && x > 0)
					dp = min(dp, cache[y - 1][x - 1]);
				else
					dp = 0;

				if (y > 0)
					dp = min(dp, cache[y - 1][x]);
				if (x > 0)
					dp = min(dp, cache[y][x - 1]);

				dp += 1;
			}
		}
	}

	vector<int> ans(min(N, M) + 1, 0);
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			int& dp = cache[y][x];
			for (int i = 1; i <= dp; i++)
			{
				ans[i]++;
			}
		}
	}

	for (int i = 1; i < min(N, M) + 1; i++)
	{
		if (ans[i] == 0)
			continue;
		cout << i << " " << ans[i] << endl;
	}
	
	return 0;
}