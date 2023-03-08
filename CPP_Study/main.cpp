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

#define endl "\n"
#define INT32_HALF (INT32_MAX / 2)
#define Init cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
using int64 = long long;
using uint64 = unsigned long long;

int N, K;
int firstArrive = -1;
int arriveCount = 0;

void HideAndSeek(int n)
{
	vector<int> visited(100001, -1);
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
	q.push({ 0, n });

	while (q.empty() == false)
	{
		int time = q.top().first;
		int now = q.top().second;
		q.pop();

		if (time < 0)
			continue;
		if (now < 0 || now > 100000)
			continue;

		if (visited[now] == -1)
			visited[now] = time;
		else if (visited[now] < time)
			continue;

		visited[now] = time;

		if (now == K)
		{
			if (firstArrive == -1)
			{
				firstArrive = time;
				arriveCount++;
				continue;
			}
			else if (firstArrive == time)
			{
				arriveCount++;
			}
			else
				break;
		}

		q.push({ time + 1, now - 1 });
		q.push({ time + 1, now + 1 });
		q.push({ time + 1, now * 2 });
	}
}

int main()
{
	Init;

	cin >> N >> K;
	HideAndSeek(N);
	cout << firstArrive << endl;
	cout << arriveCount;
	
	return 0;
}