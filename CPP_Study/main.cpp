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
vector<bool> discovered;
vector<int> bacon;

void BFS(int now)
{
	vector<int> distance(N, 0);

	discovered[now] = true;
	queue<int> _queue;
	_queue.push(now);

	distance[now] = 0;

	while (_queue.empty() == false)
	{
		int here = _queue.front();
		_queue.pop();

		for (int& there : vec[here])
		{
			if (discovered[there] == true)
				continue;

			_queue.push(there);
			discovered[there] = true;
			distance[there] = distance[here] + 1;
		}
	}

	int sum = 0;
	for (int& n : distance)
		sum += n;

	bacon[now] = sum;
	discovered = vector<bool>(N, false);
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	vec = vector<vector<int>>(N);
	discovered = vector<bool>(N, false);
	bacon = vector<int>(N, 0);

	for (int i = 0; i < M; i++)
	{
		int A, B;
		cin >> A >> B;
		vec[A - 1].push_back(B - 1);
		vec[B - 1].push_back(A - 1);
	}

	for (int i = 0; i < N; i++)
	{
		BFS(i);
	}

	int min = INT32_MAX;
	int minIdx = 0;
	for (int i = 0; i < N; i++)
	{
		if (bacon[i] < min)
		{
			min = bacon[i];
			minIdx = i;
		}
	}

	cout << minIdx + 1;

	return 0;
}

