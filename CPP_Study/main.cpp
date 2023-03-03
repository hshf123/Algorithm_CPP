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
#include <memory.h>
#define endl "\n"
#define INT32_HALF (2147483647 / 2)
#define Init cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
using int64 = long long;
using uint64 = unsigned long long;

int n;
const int MOD = 1000000007;

vector<vector<int64>> MulMat(const vector<vector<int64>>& a, const vector<vector<int64>>& b)
{
	vector<vector<int64>> ret(2, vector<int64>(2));
	ret[0][0] = (a[0][0] * b[0][0] % MOD + a[0][1] * b[1][0] % MOD) % MOD;
	ret[1][0] = (a[0][0] * b[0][1] % MOD + a[0][1] * b[1][1] % MOD) % MOD;
	ret[0][1] = (a[1][0] * b[0][0] % MOD + a[1][1] * b[1][0] % MOD) % MOD;
	ret[1][1] = (a[1][0] * b[0][1] % MOD + a[1][1] * b[1][1] % MOD) % MOD;
	return ret;
}

vector<vector<int64>> Fibonacci(int64 n)
{
	if (n == 1) 
	{
		vector<vector<int64>> arr = { {1,1},{1,0} };
		return arr;
	}
	vector<vector<int64>> tmp = Fibonacci(n / 2);
	if (n % 2 == 1) {
		return MulMat(MulMat(tmp, tmp), Fibonacci(1));
	}
	else {
		return MulMat(tmp, tmp);
	}
}

int main()
{
	Init;

	int64 n;
	cin >> n;
	vector<vector<int64>> arr =  Fibonacci(n);
	cout << arr[0][1];

	return 0;
}
