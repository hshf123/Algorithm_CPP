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

vector<int> cache;

int Solve(const vector<int>& path, const int& start)
{
	int& ret = cache[start];
	if (ret != -1)
		return ret;

	ret = 1;
	for (int i = start; i < path.size(); i++)
	{
		if (path[start] < path[i])
			ret = max(Solve(path, i) + 1, ret);
	}
	return ret;
}

int main()
{
	Init;
	
	int C;
	cin >> C;

	vector<int> ans(C);
	for (int c = 0; c < C; c++)
	{
		int N;
		cin >> N;
		vector<int> numList(N);
		cache = vector<int>(N, -1);
		for (int i = 0; i < N; ++i)
			cin >> numList[i];

		ans[c] = Solve(numList, 0);
	}

	cout << endl;
	for (const int& a : ans)
		cout << a << endl;
	
	return 0;
}