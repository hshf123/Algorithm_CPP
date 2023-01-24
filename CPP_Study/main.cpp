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

int N;
vector<vector<int>>			_vec;
map<int, set<int>>			_history;
vector<int>					_visitedOrder;
vector<vector<int>>			answer;
int							_visitedCount;
vector<bool>				_finished;
vector<int>					_parent;

void DFS(int here)
{
	if (_visitedOrder[here] != 0)
		return;

	if (_visitedCount != 0)
		_visitedOrder[here] = 1;
	_visitedCount++;

	auto findIt = _history.find(here);
	if (findIt == _history.end())
	{
		// 연결된 노드들이 없다.
		_finished[here] = true;
		return;
	}

	// 연결된 노드가 있다.
	set<int>& next = findIt->second;
	for (int there : next)
	{
		if (_visitedOrder[there] == 0)
		{
			_parent[there] = here;
			DFS(there);
			continue;
		}

		if (_visitedOrder[here] < _visitedOrder[there])
			continue;
	}

	_finished[here] = true;
}

void Push(int node, int edge)
{
	_vec[node].push_back(edge);
	set<int>& history = _history[node];
	history.insert(edge);
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	_vec.resize(N);

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			int n;
			cin >> n;
			if (n == 1)
				Push(y, x);
		}
	}

	for (int y = 0; y < N; y++)
	{
		_visitedOrder = vector<int>(N, 0);
		_visitedCount = 0;
		_finished = vector<bool>(N, false);
		_parent = vector<int>(N, -1);
		DFS(y);
		answer.push_back(_visitedOrder);
	}

	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < N; x++)
		{
			cout << answer[y][x] << " ";
		}
		cout << endl;
	}

	return 0;
}

