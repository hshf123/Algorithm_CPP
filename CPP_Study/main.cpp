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



void BFS(int now)
{
	
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, K;
	vector<bool> discovered(100001, false);
	cin >> N >> K;

	discovered[N] = true;
	queue<int> _queue;
	_queue.push(N);
	vector<int>distance(100001, -1);
	distance[N] = 0;

	while (_queue.empty() == false)
	{
		int here = _queue.front();
		_queue.pop();
		for (int i = 0; i < 3; i++)
		{
			if (here == K)
			{
				cout << distance[K];
				return 0;
			}

			int there = -1;
			if (i == 0)
				there = here - 1;
			else if (i == 1)
				there = here + 1;
			else if (i == 2)
				there = 2 * here;

			if (there > -1 && there <= 100000 && discovered[there] == false)
			{
				_queue.push(there);
				discovered[there] = true;
				distance[there] = distance[here] + 1;
			}
		}
	}

	return 0;
}

