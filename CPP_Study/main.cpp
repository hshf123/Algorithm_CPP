#include <iostream>
using namespace std;
#define endl "\n"
using int64 = long long;

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

int N, M;
vector<vector<int>> vec;
vector<bool> visited;
int _count = 0;

void DFS(int here)
{
	visited[here] = true;

	for (int& there : vec[here])
	{
		if (visited[there] == false)
		{
			visited[there] = true;
			DFS(there);
		}
	}
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;

	vec = vector<vector<int>>(N);
	visited = vector<bool>(N, false);
	for (int i = 0; i < M; i++)
	{
		int u, v;
		cin >> u >> v;

		vec[u - 1].push_back(v - 1);
		vec[v - 1].push_back(u - 1);
	}

	for (int i = 0; i < N; i++)
	{
		if (visited[i] == false)
		{
			_count++;
			DFS(i);
		}
	}

	cout << _count;

	return 0;
}

