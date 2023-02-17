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
#define endl "\n"
#define INT32_HALF (2147483647 / 2)
#define Init cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
using int64 = long long;
using uint64 = unsigned long long;

int N;
vector<int> seq;
vector<int> cache;

int LIS(int n)
{
	int& ret = cache[n];
	if (ret != -1)
		return ret;

	ret = 1;
	for (int i = n + 1; i < N; i++)
	{
		if (seq[i] > seq[n])
			ret = max(ret, 1 + LIS(i));
	}
	return ret;
}

int main()
{
	Init;

	cin >> N;
	seq = vector<int>(N);
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		seq[i] = n;
	}
	cache = vector<int>(N, -1);
	int _max = -1;
	for (int i = 0; i < N; i++)
	{
		_max = max(_max, LIS(i));
	}

	cout << _max;

	return 0;
}
