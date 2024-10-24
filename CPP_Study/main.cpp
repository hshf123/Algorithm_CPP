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

int N;
vector<int> vec;
int ans = INT32_MAX;

int DP(int idx, int cnt)
{
	if (idx >= N)
		return cnt;

	int ret = INT32_MAX;
	ret = min(DP(idx + 1, cnt + vec[idx]), ret);
	ret = min(DP(idx + 2, cnt + vec[idx]), ret);
	return ret;
}

int main()
{
	Init;
	
	cin >> N;
	vec = vector<int>(N);
	for (int i = 0; i < N; i++)
		cin >> vec[i];

	int ret = min(DP(0, 0), DP(1, 0));
	cout << ret;

	return 0;
}