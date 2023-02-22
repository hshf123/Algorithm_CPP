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

int dx[] = { 0,1,0,-1 };
int dy[] = { 1,0,-1,0 };
int n;

vector<vector<int>> stickers;
vector<vector<int>> cache;

int DP()
{
	cache[0][0] = stickers[0][0];
	cache[1][1] = stickers[1][1] + cache[0][0];

	cache[1][0] = stickers[1][0];
	cache[0][1] = stickers[0][1] + cache[1][0];

	for (int i = 2; i < n; i++) {
		cache[0][i] = stickers[0][i] + max(cache[1][i - 1], cache[1][i - 2]);
		cache[1][i] = stickers[1][i] + max(cache[0][i - 1], cache[0][i - 2]);
	}

	return max(cache[0][n - 1], cache[1][n - 1]);
}

int main()
{
	Init;

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> n;
		stickers = vector<vector<int>>(2, vector<int>(n));
		cache = vector<vector<int>>(2, vector<int>(n, -1));
		for (int k = 0; k < 2; k++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> stickers[k][j];
			}
		}

		cout << DP() << endl;
	}
	
	return 0;
}
