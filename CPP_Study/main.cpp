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

struct Vertex
{
	bool operator<(const Vertex& other) const { return cost < other.cost; }
	bool operator>(const Vertex& other) const { return cost > other.cost; }

	int edge;
	int cost;
};

int V, E, K;
vector<vector<Vertex>> vec;
vector<int> best;

void Dijikstra(int now)
{
	priority_queue<Vertex, vector<Vertex>, greater<Vertex>> discovered;
	discovered.push(Vertex{now, 0});
	best[now] = 0;

	while (discovered.empty() == false)
	{
		Vertex vertex = discovered.top();
		discovered.pop();
		int bestCost = vertex.cost;
		now = vertex.edge;

		if (best[now] < bestCost)
			continue;

		for (auto it = vec[now].begin(); it != vec[now].end(); ++it)
		{
			int next = it->edge;
			int nextCost = best[now] + it->cost;
			if (nextCost >= best[next])
				continue;

			best[next] = nextCost;
			discovered.push(Vertex{ next, nextCost });
		}
	}
}

int main()
{
	Init;

	cin >> V >> E >> K;
	vec = vector<vector<Vertex>>(V + 1);
	best = vector<int>(V + 1, INT32_MAX);

	for (int i = 0; i < E; i++)
	{
		int u, v, w;
		cin >> u >> v >> w;

		vec[u].push_back(Vertex{ v,w });
	}

	Dijikstra(K);

	for (int i = 1; i <= V; i++)
	{
		if (best[i] == INT32_MAX)
			cout << "INF" << endl;
		else
			cout << best[i] << endl;
	}

	return 0;
}
