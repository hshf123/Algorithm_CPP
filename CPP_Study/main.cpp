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

#define endl "\n"
#define INT32_HALF (INT32_MAX / 2)
#define Init cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
using int64 = long long;
using uint64 = unsigned long long;

int64 M;
const int64 MOD = 1'000'000'007;

int64 f(int64 x, int64 y)
{
	if (y == 1) 
		return x;
	if (y % 2 == 1) 
		return x * f(x, y - 1) % MOD;
	int64 p = f(x, y / 2);
	return p * p % MOD;
}

int main()
{
	Init;

	cin >> M;
	int64 ans = 0;
	for (int i = 0; i < M; i++)
	{
		int64 N, S;
		cin >> N >> S;

		int64 g = ::gcd(N, S);

		N /= g;
		S /= g;
		ans += S * f(N, MOD - 2) % MOD;
		ans %= MOD;
	}

	cout << ans;

	return 0;
}