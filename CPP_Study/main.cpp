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
		int year = 1;
		int M, N, x, y;
		cin >> M >> N >> x >> y;

		if (M < N)
		{
			year += (x - 1);
			int startY = x;
			int nextY = x;
			while (y != nextY)
			{
				nextY -= (N - M);
				if (nextY <= 0)
					nextY = N + nextY;

				year += M;

				if (nextY == startY)
				{
					year = -1;
					break;
				}
			}
		}
		else
		{
			year += (y - 1);
			int startX = y;
			int nextX = y;
			while (x != nextX)
			{
				nextX -= (M - N);
				if (nextX <= 0)
					nextX = M + nextX;

				year += N;

				if (nextX == startX)
				{
					year = -1;
					break;
				}
			}
		}

		cout << year << endl;;
	}

	return 0;
}

