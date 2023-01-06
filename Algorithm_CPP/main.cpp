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

int DP(int N, int fCount)
{

	int tCount = (N - (5 * fCount)) / 3;
	if (N == 5 * fCount + 3 * tCount)
		return fCount + tCount;

	return -1;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	int min = INT32_MAX;
	for (int i = N / 5; i >= 0; i--)
	{
		int res = DP(N, i);
		if (res == -1)
			continue;

		if (res < min)
			min = res;
	}
	if (min == INT32_MAX)
		cout << -1;
	else
		cout << min;
}
