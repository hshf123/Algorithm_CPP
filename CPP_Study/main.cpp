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

int dy[] = { 1,0,-1,0 };
int dx[] = { 0,1,0,-1 };
#pragma endregion

class DisjointSet
{
public:
	DisjointSet(int n) : _parent(n), _rank(n, 1)
	{
		for (int i = 0; i < n; i++)
			_parent[i] = i;
	}

	int Find(int u)
	{
		while (u != _parent[u])
		{
			u = _parent[u];
		}

		return u;
	}

	void Union(int u, int v)
	{
		u = Find(u);
		v = Find(v);
		if (u == v)
			return;

		if (_rank[u] > _rank[v])
			swap(u, v);

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
	double cost = -1.f;
	int u;
	int v;

	bool operator<(const CostEdge& other) const
	{
		return cost < other.cost;
	}
};

int main()
{
	Init;
	
	int N, M;
	cin >> N >> M;

	vector<CostEdge> edge;
	vector<pair<int, int>> pos(N);
	vector<vector<pair<int, int>>> node(N, vector<pair<int,int>>(N, { -1,-1 }));

	for (int i = 0; i < N; i++)
	{
		int y, x;
		cin >> y >> x;
		pos[i] = { y - 1,x - 1 };
	}
	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;
		pair<int,int>& nodeA = pos[A - 1];
		pair<int,int>& nodeB = pos[B - 1];

		node[A - 1][B - 1] = { B - 1,0 };
		node[B - 1][A - 1] = { A - 1,0 };
	}
	for (int a = 0; a < N; a++)
	{
		for (int b = a + 1; b < N; b++)
		{
			pair<int, int>& nodeA = pos[a];
			pair<int, int>& nodeB = pos[b];

			double cost = 0;
			if (node[a][b].second != 0)
				cost = sqrt(pow(nodeA.first - nodeB.first, 2) + pow(nodeA.second - nodeB.second, 2));

			edge.push_back({ cost, a,b });
		}
	}

	sort(edge.begin(), edge.end());
	DisjointSet ds(N);

	double ans = 0;
	for (CostEdge& e : edge)
	{
		if (ds.Find(e.u) == ds.Find(e.v))
			continue;

		ds.Union(e.u, e.v);
		ans += e.cost;
	}

	cout << fixed;
	cout.precision(2);
	cout << ans;
	return 0;
}