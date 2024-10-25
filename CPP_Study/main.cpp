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

int N, M;
vector<vector<pair<int,int>>> bridge;
vector<int> cache;
int A, B;
int val = 0;
int ans = 0;

int BFS(int maxVal)
{
	cache = vector<int>(N, -1);
	queue<int> q;
	q.push(A - 1);
	cache[A - 1] = 1;
	while (q.empty() == false)
	{
		int n = q.front();
		q.pop();

		for (int i = 0; i < bridge[n].size(); i++)
		{
			int& next = bridge[n][i].second;
			if (next == -1)
				continue;
			if (next < maxVal)
				continue;
			if (cache[bridge[n][i].first] != -1)
				continue;
			cache[bridge[n][i].first] = 1;
			q.push(bridge[n][i].first);
		}
	}

	return cache[B - 1];
}

int main()
{
	Init;

	cin >> N >> M;
	bridge = vector<vector<pair<int,int>>>(N);
	for (int i = 0; i < M; i++)
	{
		int a, b, c;
		cin >> a >> b >> c;
		a -= 1;
		b -= 1;
		bridge[a].push_back({ b, c });
		bridge[b].push_back({ a, c });
		val = max(val, c);
	}
	cin >> A >> B;

	int start = 0;
	int end = val;
	int ans = 0;
	while (start <= end)
	{
		int mid = (start + end) / 2;
		if (BFS(mid) == 1)
		{
			ans = mid;
			start = mid + 1;
		}
		else
		{
			end = mid -1;
		}
	}
	
	cout << ans;

	return 0;
}