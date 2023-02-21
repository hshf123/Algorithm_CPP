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

int n;
vector<vector<int>> triangle;
vector<vector<int>> cache;

int Search(int y, int x)
{
	if (y == n || x >= 2 * n - 1)
		return 0;

	int& ret = cache[y][x];
	if (ret != -1)
		return ret;

	return ret = triangle[y][x] + max(Search(y + 1, x - 1), Search(y + 1, x + 1));
}

int main()
{
	Init;

	cin >> n;
	triangle = vector<vector<int>>(n, vector<int>(2 * n - 1, -1));
	cache = vector<vector<int>>(n, vector<int>(2 * n - 1, -1));

	for (int i = 0; i < n; i++)
	{
		int idx = n - i - 1;
		for (int j = 0; j <= i; j++)
		{
			int num;
			cin >> num;
			triangle[i][idx] = num;
			idx += 2;
		}
	}

	cout << Search(0, n - 1);

	return 0;
}
