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

	int Find(int u)
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
		u = Find(u);
		v = Find(v);

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

	int N, M;
	cin >> N >> M;

	vector<CostEdge> edges;
	vector<CostEdge> selected;
	int ret = 0;

	for (int i = 0; i < M; i++)
	{
		int A, B, C;
		cin >> A >> B >> C;
		edges.push_back({ C, A - 1, B - 1 });
		edges.push_back({ C, B - 1, A - 1 });
	}

	std::sort(edges.begin(), edges.end());

	DisjointSet ds(N);

	int lastCost = 0;
	for(CostEdge& edge : edges)
	{
		if (ds.Find(edge.u) == ds.Find(edge.v))
			continue;

		ds.Merge(edge.u, edge.v);
		selected.push_back(edge);
		ret += edge.cost;
		lastCost = edge.cost;
	}

	cout << ret - lastCost << endl;

	return 0;
}