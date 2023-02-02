#include <iostream>
using namespace std;
#define endl "\n"
using int64 = long long;
using uint64 = unsigned long long;

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

struct Node
{
	int edge;
	int width;
};

int V;
vector<vector<Node>> vec;
vector<bool> visited;
int _max = 0;
int maxNode;

void DFS(int n, int width)
{
	if (visited[n] == true)
		return;

	visited[n] = true;

	if (_max < width)
	{
		_max = width;
		maxNode = n;
	}

	for (Node& node : vec[n])
	{
		DFS(node.edge, width + node.width);
	}
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> V;
	vec.resize(V + 1);

	for (int i = 1; i < V + 1; i++)
	{
		visited = vector<bool>(V + 1, false);

		int nodeNumber;
		cin >> nodeNumber;

		while (true)
		{
			int edge;
			cin >> edge;
			if (edge == -1)
				break;
			int width;
			cin >> width;

			vec[nodeNumber].push_back({ edge, width });
		}

		visited.clear();
	}
	
	visited = vector<bool>(V + 1, false);
	DFS(1, 0);

	_max = 0;

	visited = vector<bool>(V + 1, false);
	DFS(maxNode, 0);

	cout << _max;

	return 0;
}
