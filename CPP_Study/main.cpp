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

int TC;
int N, M, W;
vector<pair<pair<int, int>, int>> roads;

void BellmanFord()
{
	bool flag = false;
	vector<int> best(N + 1, INT32_HALF / 2);
	best[1] = 0;

	for (int i = 1; i < N; i++)
	{
		for (pair<pair<int, int>, int> p : roads)
		{
			int now = p.first.first;
			int next = p.first.second;
			int width = p.second;

			if (best[next] > best[now] + width)
			{
				best[next] = best[now] + width;
			}
		}
	}

	for (pair<pair<int, int>, int> p : roads)
	{
		int now = p.first.first;
		int next = p.first.second;
		int width = p.second;

		if (best[next] > best[now] + width)
			flag = true;
	}

	if (flag)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;
}

int main()
{
	Init;

	cin >> TC;
	for (int i = 0; i < TC; i++)
	{
		cin >> N >> M >> W;
		roads.clear();
		for (int j = 0; j < M; j++)
		{
			int S, E, T;
			cin >> S >> E >> T;
			roads.push_back({ {S,E},T });
			roads.push_back({ {E,S},T });
		}

		for (int j = 0; j < W; j++)
		{
			int S, E, T;
			cin >> S >> E >> T;
			roads.push_back({ {S,E},-T });
		}

		BellmanFord();
	}

	return 0;
}
