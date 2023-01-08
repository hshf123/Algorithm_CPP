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

	int N, M;
	int B;
	cin >> N >> M >> B;
	vector<vector<int>> vec(N, vector<int>(M));
	for (int y = 0; y < N; y++)
	{
		for (int x = 0; x < M; x++)
		{
			int h;
			cin >> h;

			vec[y][x] = h;
		}
	}

	int minTime = INT32_MAX;
	int ansH;
	for (short height = 0; height <= 256; height++)
	{
		int getBlock = 0; // 얻게될 블럭
		int useBlock = 0; // 사용할 블럭
		for (int y = 0; y < N; y++)
		{
			for (int x = 0; x < M; x++)
			{
				int val = vec[y][x] - height;
				if (val > 0)
					getBlock += val;
				else if (val < 0)
					useBlock += val;
			}
		}

		int time = getBlock * 2 - useBlock;
		if (((B + getBlock) >= useBlock) && (minTime >= time))
		{
			minTime = time;
			ansH = height;
		}
	}

	cout << minTime << " " << ansH;

	return 0;
}
