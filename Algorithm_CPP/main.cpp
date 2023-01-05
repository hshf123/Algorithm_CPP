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
#include <list>

int KFloorNRoom(int k, int n)
{
	int res = 0;

	if (k == 0)
		return n;

	for (int i = 1; i <= n; i++)
	{
		res += KFloorNRoom(k - 1, i);
	}

	return res;
}

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int k, n;
		cin >> k >> n;

		cout << KFloorNRoom(k, n) << endl;
	}
}
