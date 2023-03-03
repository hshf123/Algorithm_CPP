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

int N, M;
vector<pair<int, int>> bus[1001];
int best[1001];

void Dijkstra(int start, int end)
{
	for (int i = 1; i <= N; i++)
		best[i] = INT32_MAX;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	best[start] = 0;
	q.push({ 0, start });
	
	while (q.empty() == false)
	{
		int weight = q.top().first;
		int now = q.top().second;
		q.pop();

		if (best[now] < weight)
			continue;

		for (pair<int,int>& p : bus[now])
		{
			int next = p.first;
			int nextWeight = best[now] + p.second;

			if (nextWeight > best[next])
				continue;

			best[next] = nextWeight;
			q.push({ nextWeight, next });
		}
	}

	cout << best[end];
}

int main()
{
	Init;

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int start, end, weight;
		cin >> start >> end >> weight;

		bus[start].push_back({ end,weight });
	}

	int start, end;
	cin >> start >> end;
	Dijkstra(start, end);

	return 0;
}
