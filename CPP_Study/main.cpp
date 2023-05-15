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

#define endl "\n"
#define INT32_HALF (INT32_MAX / 2)
#define Init cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
using int64 = long long;
using uint64 = unsigned long long;

int n, m, r;
vector<int> t;
vector<vector<int>> road;

int Dijikstra(int pos)
{
	vector<int> best(n, INT32_MAX);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0, pos });
	best[pos] = 0;

	while (q.empty() == false)
	{
		auto& p = q.top();
		int cost = p.first;
		int now = p.second;
		q.pop();

		if (cost < best[now])
			best[now] = cost;

		if (best[now] < cost)
			continue;

		for (int next = 0; next < n; next++)
		{
			if (road[now][next] == -1)
				continue;

			int nextCost = best[now] + road[now][next];
			if (nextCost >= best[next])
				continue;

			best[next] = nextCost;
			q.push({ nextCost, next });
		}
	}

	int res = 0;
	for (int i = 0; i < n; i++)
	{
		if (best[i] <= m)
		{
			res += t[i];
		}
	}

	return res;
}

int main()
{
	Init;

	cin >> n >> m >> r;
	t.resize(n);
	road = vector<vector<int>>(n, vector<int>(n, -1));
	for (int i = 0; i < n; i++)
		cin >> t[i];
	for (int i = 0; i < r; i++)
	{
		int a, b, l;
		cin >> a >> b >> l;

		road[a - 1][b - 1] = l;
		road[b - 1][a - 1] = l;
	}

	int res = INT32_MIN;
	for (int i = 0; i < n; i++)
	{
		res = max(Dijikstra(i), res);
	}

	cout << res;

	return 0;
}