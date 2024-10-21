#pragma region Headers
#include <iostream>
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
#include <cstring>
#include <numeric>
#include <sstream>
#include <array>

#define endl "\n"
#define INT32_HALF (INT32_MAX / 2)
#define Init cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false)
using namespace std;
using int64 = long long;
using uint64 = unsigned long long;
#pragma endregion

int main()
{
	Init;
	
	int W, H, T, S;
	cin >> W >> H >> T >> S;

	vector<int> vecx(T);
	vector<int> vecy(T);

	for (int i = 0; i < T; i++)
	{
		cin >> vecx[i] >> vecy[i];
	}

	int ret = 0;
	int res = 0;

	for (int x = 0; x < T; x++)
	{
		for (int y = 0; y < T; y++)
		{
			ret = 0;
			for (int i = 0; i < T; i++)
			{
				if (vecx[i] >= vecx[x] && vecx[i] <= vecx[x] + S && vecy[i] >= vecy[y] && vecy[i] <= vecy[y] + S)
					ret++;
			}

			res = max(ret, res);
		}
	}
	cout << res;

	return 0;
}