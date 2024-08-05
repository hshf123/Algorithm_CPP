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

vector<vector<int>> cache;

int Solve(const vector<vector<int>>& path, const int& y, const int& x)
{
	if (y >= path.size() || x >= y + 1)
		return 0;
	if (y == path.size() - 1)
		return path[y][x];

	int& ret = cache[y][x];
	if (ret != -1)
		return ret;

	int add = path[y][x];
	return ret = max(Solve(path, y + 1, x), Solve(path, y + 1, x + 1)) + add;
}

int main()
{
	Init;
	
	int C;
	cin >> C;

	vector<int> ans(C);
	for (int c = 0; c < C; c++)
	{
		int n;
		cin >> n;
		vector<vector<int>> path(n, vector<int>(n));
		cache = vector<vector<int>>(n, vector<int>(n, -1));
		for (int i = 1; i <= n; i++)
		{
			for (int j = 0; j < i; j++)
			{
				cin >> path[i - 1][j];
			}
		}

		ans[c] = Solve(path, 0, 0);
	}

	cout << endl;
	for (const int& a : ans)
		cout << a << endl;
	
	return 0;
}