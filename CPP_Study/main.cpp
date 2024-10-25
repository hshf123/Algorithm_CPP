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

int N, M;
vector<int> vec;
int ans = INT32_MAX;
int minVal = 0;


int Solve(int maxVal)
{
	if (maxVal <= minVal)
		return minVal;

	int cnt = 0;
	int sm = 0;
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		if (sum + vec[i] <= maxVal)
		{
			sum += vec[i];
		}
		else
		{
			sm = max(sm, sum);
			sum = vec[i];
			cnt++;
		}
	}
	cnt++;
	sm = max(sm, sum);
	
	if (cnt > M)
	{
		int temp = maxVal;
		maxVal = maxVal * 2 - minVal + (temp % 2 == 0 ? 1 : 0);
		minVal = temp + 1;
		sm = INT32_MAX;
	}
	if (cnt == M && minVal + 1 == maxVal)
		minVal = maxVal;

	return min(sm, Solve((maxVal + minVal) / 2));
}

int main()
{
	Init;

	cin >> N >> M;
	vec.resize(N, 0);
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> vec[i];
		sum += vec[i];
		minVal = max(vec[i], minVal);
	}

	int ans = Solve((minVal + sum) / 2);
	cout << ans;

	return 0;
}