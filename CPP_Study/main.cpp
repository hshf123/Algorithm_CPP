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

		vector<int64> vec(100);
		vec[0] = 1;
		vec[1] = 1;
		vec[2] = 1;
		vec[3] = 2;
		vec[4] = 2;

		for (int n = 5; n < N; n++)
		{
			vec[n] = vec[n - 2] + vec[n - 3];
			if (n == N - 1)
				break;
		}

		cout << vec[N - 1] << endl;
	}

	return 0;
}

