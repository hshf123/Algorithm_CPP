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

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,int>>> pq;
	for (int i = 0; i < N; i++)
	{
		int startTime, endTime;
		cin >> startTime >> endTime;

		pq.push(make_pair(endTime, startTime));
	}

	int count = 1;
	auto copy = pq;
	pair<int, int> _pair = pq.top();
	pq.pop();
	int startTime = _pair.second;
	int endTime = _pair.first;
	while (pq.empty() == false)
	{
		_pair = pq.top();
		pq.pop();
		int nextStartTime = _pair.second;
		int nextEndTime = _pair.first;

		if (nextStartTime >= endTime)
		{
			count++;
			startTime = nextStartTime;
			endTime = nextEndTime;
		}
	}

	cout << count;

	return 0;
}

