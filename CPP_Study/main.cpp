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

struct Study
{
	int st = 0;
	int et = 0;
	int e = 0;

	bool operator<(const Study& other)
	{
		return et < other.et;
	}
};

int N, M, R;
vector<int> cache;  // N시간 까지 최대 효율
vector<Study>  vec;

int ans = 0;

void DP()
{
	for (int i = 0; i < M; i++)
	{
		Study& study = vec[i];
		int& ret = cache[i];
		ret = study.e;
		for (int j = i - 1; j >= 0; j--)
		{
			Study& before = vec[j];
			if (before.et + R <= study.st)
				ret = max(ret, cache[j] + study.e);
		}

		ans = max(ans, ret);
	}
}

int main()
{
	Init;
	
	cin >> N >> M >> R;
	cache.resize(M, -1);
	vec.resize(M);
	for (int i = 0; i < M; i++)
	{
		int st, et, e;
		cin >> st >> et >> e;
		vec[i] = { st, et, e };
	}

	sort(vec.begin(), vec.end());

	DP();
	
	cout << ans;
	return 0;
}