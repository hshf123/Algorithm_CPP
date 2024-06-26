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

class DisjointSet
{
public:
	DisjointSet(const int& nodeCount) : _parent(nodeCount), _rank(nodeCount, 1)
	{
		for (int i = 0; i < nodeCount; i++)
			_parent[i] = i;
	}

	int FindBoss(int u)
	{
		while (true)
		{
			if (u == _parent[u])
				return u;

			u = _parent[u];
		}
	}

	void Merge(int u, int v)
	{
		u = FindBoss(u);
		v = FindBoss(v);
		if (u == v)
			return;

		if (_rank[u] > _rank[v])
			::swap(u, v);

		_parent[u] = v;
		if (_rank[u] == _rank[v])
			_rank[v]++;
	}
	
private:
	vector<int> _parent;
	vector<int> _rank;
};

struct CostEdge
{
	int cost;
	int u;
	int v;

	bool operator<(const CostEdge& other)
	{
		return cost < other.cost;
	}
};

int main()
{
	Init;

	int V, E;
	cin >> V >> E;

	vector<vector<pair<int, int>>> nodes(V);
	for (int edge = 0; edge < E; edge++)
	{
		int A, B, C;
		cin >> A >> B >> C;
		A -= 1;
		B -= 1;
		nodes[A].push_back({ B, C });
		nodes[B].push_back({ A, C });
	}

	vector<CostEdge> edges;
	for (int u = 0; u < nodes.size(); u++)
	{
		for (int v = 0; v < nodes[u].size(); v++)
		{
			if (u > nodes[u][v].first)
				continue;

			int cost = nodes[u][v].second;
			if (cost == 100'0001)
				continue;

			edges.push_back(CostEdge{ cost, u, nodes[u][v].first });
		}
	}

	nodes.clear();
	std::sort(edges.begin(), edges.end());

	int ans = 0;
	DisjointSet sets(V);
	for (CostEdge& edge : edges)
	{
		if (sets.FindBoss(edge.u) == sets.FindBoss(edge.v))
			continue;

		sets.Merge(edge.u, edge.v);
		ans += edge.cost;
	}
	
	cout << ans;
	return 0;
}