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
unordered_map<int, int> m;
unordered_set<int> s1;
unordered_set<int> s2;
unordered_set<int> s3;

int main()
{
	Init;
	
	cin >> N;

	int ans = -1;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		if (s1.insert(n).second)
			++m[n];
	}
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		if (s2.insert(n).second)
			++m[n];
	}
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		if (s3.insert(n).second)
			ans = max(ans, ++m[n] == 3 ? n : ans);
	}

	cout << ans;
	
	return 0;
}