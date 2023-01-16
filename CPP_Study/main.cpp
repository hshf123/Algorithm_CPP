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
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int t = 0; t < T; t++)
	{
		int N;
		cin >> N;
		map<string, int> opts;
		for (int n = 0; n < N; n++)
		{
			string cloth, opt;
			cin >> cloth >> opt;
			
			auto findIt = opts.find(opt);
			if (findIt != opts.end())
			{
				findIt->second++;
			}
			else
			{
				opts.insert({ opt, 2 });
			}
		}

		int ans = 1;
		for (auto it = opts.begin(); it != opts.end(); ++it)
		{
			int n = it->second;
			ans *= n;
		}

		cout << ans - 1 << endl;
	}

	return 0;
}

