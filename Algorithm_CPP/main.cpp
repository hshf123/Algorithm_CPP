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

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	// y, x
	map<int, priority_queue<int, vector<int>, greater<int>>> _map;
	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		_map[y].push(x);
	}

	for (auto it = _map.begin(); it != _map.end(); ++it)
	{
		int y = it->first;
		while (it->second.empty() == false)
		{
			int x = it->second.top();
			it->second.pop();
			cout << x << " " << y << endl;
		}
	}

	return 0;
}
