#include <iostream>
using namespace std;
#define endl "\n"
using int64 = long long;
using uint64 = unsigned long long;

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

	int n;
	cin >> n;

	vector<int> dp(n + 1);
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;

	for (int i = 4; i <= n; i++)
	{
		int minnum = INT32_MAX;
		for (int j = 1; j * j <= i; j++)
		{
			int idx = i - j * j;
			minnum = min(dp[idx], minnum);
		}

		dp[i] = minnum + 1;
	}

	cout << dp[n];

	return 0;
}
