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

#define endl "\n"
#define INT32_HALF (INT32_MAX / 2)
#define Init cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
using int64 = long long;
using uint64 = unsigned long long;

int N;
int seq[1000];
int maxCache[1000];
int minCache[1000];

void Bitonic()
{
	for (int i = 0; i < N; i++)
	{
		maxCache[i] = 1;
		for (int j = 0; j <= i; j++)
		{
			if (seq[j] < seq[i] && maxCache[i] < maxCache[j] + 1)
			{
				maxCache[i] = maxCache[j] + 1;
			}
		}
	}

	for (int i = N - 1; i >= 0; i--)
	{
		minCache[i] = 1;
		for (int j = N - 1; j >= i; j--)
		{
			if (seq[i] > seq[j] && minCache[i] < minCache[j] + 1)
			{
				minCache[i] = minCache[j] + 1;
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		ans = max(ans, maxCache[i] + minCache[i] - 1);
	}
	cout << ans;
}

int main()
{
	Init;

	cin >> N;
	for (int i = 0; i < N; i++)
	{
		cin >> seq[i];
	}
	Bitonic();
	
	return 0;
}