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
#include <memory.h>
#define endl "\n"
#define INT32_HALF (2147483647 / 2)
#define Init cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
using int64 = long long;
using uint64 = unsigned long long;

int n, m;
vector<pair<int, int>> road[100];

void BFS(int now)
{
	vector<int> best(n, INT32_MAX);
	priority_queue<pair<int, int>> q;
	best[now] = 0;
	q.push({ 0, now });

	while (q.empty() == false)
	{
		int dist = q.top().first;
		now = q.top().second;
		q.pop();

		if (best[now] < dist)
			continue;

		for (pair<int, int> p : road[now])
		{
			int width = p.first;
			int next = p.second;
			
			if (best[next] > dist + width)
			{
				best[next] = dist + width;
				q.push({ dist + width, next });
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (best[i] == INT32_MAX)
			cout << 0 << " ";
		else
			cout << best[i] << " ";
	}
	cout << endl;
}

int main()
{
	Init;

	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		--a;
		--b;
		road[a].push_back({ c,b });
	}

	for (int i = 0; i < n; i++)
		BFS(i);

	return 0;
}
