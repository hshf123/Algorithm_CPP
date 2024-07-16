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

int main()
{
	Init;

	int N, S;
	cin >> N >> S;

	vector<int> seq(N);

	for (int i = 0; i < N; i++)
		cin >> seq[i];

	int ans = INT32_MAX;
	
	int s = 0;
	int e = 1;
	int sum = seq[s];
	while (true)
	{
		if (e > N || s > e)
			break;

		if (sum >= S)
		{
			ans = min(ans, e - s);
			sum -= seq[s];
			s++;
		}
		else
		{
			if (e == N)
				break;

			sum += seq[e];
			e++;
		}
	}

	cout << (ans == INT32_MAX ? 0 : ans);
	
	return 0;
}