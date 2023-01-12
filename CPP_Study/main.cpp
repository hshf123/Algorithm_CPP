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

	int T;
	cin >> T;
	vector<string> ans(T);
	for (int i = 0; i < T; i++)
	{
		int k;
		cin >> k;

		multiset<int, greater<int>> _set;
		for (int j = 0; j < k; j++)
		{
			char c;
			int n;
			cin >> c >> n;

			if (c == 'D')
			{
				if (_set.empty())
					continue;

				multiset<int>::iterator it;
				if (n == 1)
					it = _set.begin();
				else
					it = --_set.end();
				int count = _set.count(*it);
				int number = *it;
				_set.erase(*it);
				for (int l = 0; l < count - 1; l++)
					_set.insert(number);
			}
			else
			{
				_set.insert(n);
			}
		}

		if (_set.empty())
		{
			ans[i] = "EMPTY";
		}
		else
		{
			ans[i] = to_string(*_set.begin()) + " " + to_string(*--_set.end());
		}
	}

	for (string& str : ans)
		cout << str << endl;

	return 0;
}

