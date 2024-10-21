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
vector<pair<int, int>> vec;

int DFS(int idx, int wCount, int bCount, int wSum, int bSum)
{
	if (idx > N)
		return INT32_MAX;

	if (idx == N)
		return abs(wSum - bSum);

	if (wCount == N / 2)
		return DFS(idx + 1, wCount, bCount + 1, wSum, bSum + vec[idx].second);
	if (bCount == N / 2)
		return DFS(idx + 1, wCount + 1, bCount, wSum + vec[idx].first, bSum);

	return min(DFS(idx + 1, wCount + 1, bCount, wSum + vec[idx].first, bSum), DFS(idx + 1, wCount, bCount + 1, wSum, bSum + vec[idx].second));
}

int main()
{
	Init;
	
	cin >> N;

	vec.resize(N);
	for (int i = 0; i < N; i++)
	{
		int w, b;
		cin >> w >> b;
		vec[i] = { w, b };
	}

	cout << min(DFS(1, 1, 0, vec[0].first, 0), DFS(1, 0, 1, 0, vec[0].second));

	return 0;
}