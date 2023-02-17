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

int N;
vector<vector<int>> tree;
vector<int> parent;
vector<bool> visited;

void DFS(int n)
{
	if (visited[n])
		return;

	visited[n] = true;

	for (int v : tree[n])
	{
		if (visited[v] == false)
		{
			DFS(v);
			parent[v] = n;
		}
	}

}

int main()
{
	Init;

	cin >> N;
	tree = vector<vector<int>>(N + 1);
	for (int i = 0; i <= N; i++)
		parent.push_back(i);
	visited = vector<bool>(N + 1, false);
	for (int i = 0; i < N - 1; i++)
	{
		int u, v;
		cin >> u >> v;

		tree[u].push_back(v);
		tree[v].push_back(u);
	}
	for (int i = 1; i <= N; i++)
	{
		DFS(i);
	}
	for (int i = 2; i < N + 1; i++)

	{
		cout << parent[i] << endl;
	}

	return 0;
}
