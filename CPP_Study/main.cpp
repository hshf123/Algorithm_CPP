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

int dy[] = { 1,0,-1,0 };
int dx[] = { 0,1,0,-1 };
#pragma endregion

int L, N;
vector<pair<int, int>> vec;

int DP(int idx, int len, int cnt)
{
	if (len == L)
		return cnt;
	if (idx == N - 1 && len != L)
		return -1;

	int ret = 0;
	for (int i = idx + 1; i < N; i++)
	{
		int nlen = len + vec[i].first;
		if (nlen > L)
			continue;

		ret = max(ret, DP(i, nlen, min(cnt, vec[i].second)));
	}
	return ret;
}

int main()
{
	Init;
	
	cin >> L >> N;
	vec = vector<pair<int, int>>(N);
	for (int i = 0; i < N; i++)
	{
		cin >> vec[i].first >> vec[i].second;
	}

	cout << DP(-1, 0, INT32_MAX);
	
	return 0;
}