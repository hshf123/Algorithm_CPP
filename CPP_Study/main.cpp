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
#include <functional>

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	map<int, priority_queue<int, vector<int>, greater<int>>> _map;

	for (int n = 0; n < N; n++)
	{
		int x;
		cin >> x;

		if (x == 0)
		{
			if (_map.empty())
				cout << 0 << endl;
			else
			{
				auto it = _map.begin();
				cout << it->second.top() << endl;
				it->second.pop();
				if (it->second.empty())
				{
					_map.erase(it);
				}
			}
		}
		else
		{
			auto findIt = _map.find(abs(x));
			if (findIt == _map.end())
			{
				priority_queue<int, vector<int>, greater<int>> ms;
				ms.push(x);
				_map.insert({ abs(x), ms });
			}
			else
			{
				findIt->second.push(x);
			}
		}
	}

	return 0;
}

