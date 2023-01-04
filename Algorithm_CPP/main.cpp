#include <iostream>
using namespace std;
#define endl "\n"
#define int64 long long

#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	for (int i = 1; i < N; i++)
	{
		int now = i;
		int sum = now;
		int ten = 10;
		while (now != 0)
		{
			int plus = (now % ten) / (ten / 10);
			sum += plus;

			now -= (plus * (ten / 10));
			ten *= 10;
		}

		if (sum == N)
		{
			cout << i;
			return 0;
		}
	}

	cout << "0";
}
