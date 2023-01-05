#include <iostream>
using namespace std;
#define endl "\n"
#define int64 long long

#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
#include <stack>

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	map<int, priority_queue<int>> _map;
	for (int i = 0; i < N; i++)
	{
		int x, y;
		cin >> x >> y;
		auto findIt = _map.find(x);
		if (findIt == _map.end())
		{
			priority_queue<int> _queue;
			_queue.push(y);
			_map.insert(make_pair(x, _queue));
		}
		else
		{
			findIt->second.push(y);
		}
	}

	for (auto it = _map.begin(); it != _map.end(); ++it)
	{
		stack<int> _stack;
		while (it->second.empty() == false)
		{
			_stack.push(it->second.top());
			it->second.pop();
		}

		while (_stack.empty() == false)
		{
			cout << it->first << " " << _stack.top() << endl;
			_stack.pop();
		}
	}

	return 0;
}
