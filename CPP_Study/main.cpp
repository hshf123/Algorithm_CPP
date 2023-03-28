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

vector<pair<int, int>> city[1001];
int parent[1001];
int64 best[1001];

void Dijkstra(int n, int end)
{
	for (int i = 0; i < 1001; i++)
		best[i] = INT32_HALF;
	priority_queue<pair<int64, int>, vector<pair<int64, int>>, greater<pair<int64, int>>> q;
	q.push({ 0, n });
	parent[n] = n;
	best[n] = 0;

	while (q.empty() == false)
	{
		int64 cost = q.top().first;
		int now = q.top().second;
		q.pop();

		if (best[now] < cost)
			continue;

		for (auto& p : city[now])
		{
			int64 nextCost = p.second + best[now];
			int next = p.first;

			if (best[next] <= nextCost)
				continue;

			q.push({ nextCost, next });
			best[next] = nextCost;
			parent[next] = now;
		}
	}

	int a = 0;
}

int main()
{
	Init;

	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int start, end, cost;
		cin >> start >> end >> cost;
		city[start].push_back({ end,cost });
	}

	int start, end;
	cin >> start >> end;
	Dijkstra(start, end);
	cout << best[end] << endl;

	stack<int> s;
	int prev = end;
	while (true)
	{
		s.push(prev);
		prev = parent[prev];

		if (prev == parent[prev])
			break;
	}

	if (start == prev && prev != end)
	{
		s.push(prev);
	}

	cout << s.size() << endl;
	while (s.empty() == false)
	{
		cout << s.top() << " ";
		s.pop();
	}

	return 0;
}