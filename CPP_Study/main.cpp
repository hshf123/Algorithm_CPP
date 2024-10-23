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

int N;

int main()
{
	Init;

	int maxCnt = 0;
	int cnt = 0;
	bool c = false;
	int sc = 0;
	int ec = 0;


	cin >> N;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		if (n == 1)
		{
			c = true;
			cnt = 0;
			continue;
		}
		if (c == false)
			sc++;
		cnt++;
		maxCnt = max(cnt, maxCnt);
		if (i == N - 1 && n == 0)
			ec = cnt;
	}

	maxCnt = max(max(maxCnt / 2 + (maxCnt % 2), sc), ec);

	cout << maxCnt;

	return 0;
}