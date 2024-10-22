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
vector<int> vec;

int main()
{
	Init;

	cin >> N;
	vec.resize(N + 1);
	for (int i = 0; i < N; i++)
		cin >> vec[i];
	sort(vec.begin(), vec.end());
	int res = 0;
	int i;
	for (i = N; i >= 4; i -= 2)
	{
		res += min(vec[i] + vec[2] + vec[i - 1] + vec[2], vec[2] * 2 + vec[1] + vec[i]);
	}
	if (i == 3)
		res += (vec[1] + vec[2] + vec[3]);
	if (i == 2)
		res += vec[2];
	if (i == 1)
		res += vec[1];

	cout << res;
	
	return 0;
}