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

	int N;
	cin >> N;
	if (N < 10)
	{
		cout << 0;
		return 0;
	}
	if (N == 10)
	{
		cout << 1;
		return 0;
	}

	vector<vector<vector<int>>> cache(N, vector<vector<int>>(10, vector<int>(1024, 0)));

	for (int i = 1; i < 10; i++) // 0은 제외하고
		cache[0][i][1 << i] = 1;  // 초기 경우의 수는 1 (k를 방문함도 동시에 표시)

	for (int i = 1; i < N; i++)// 각 자릿수에 대해
	{
		for (int k = 0; k < 10; k++)  //0에서 9까지의 숫자 방문
		{
			for (int bit = 0; bit < 1024; bit++) //이때, 모든 방문 기록 경우의 수를 고려
			{
				if (k - 1 >= 0)
					cache[i][k][bit | (1 << k)] += cache[i - 1][k - 1][bit];
				if (k + 1 <= 9)
					cache[i][k][bit | (1 << k)] += cache[i - 1][k + 1][bit];
				cache[i][k][bit | (1 << k)] %= 1'000'000'000;
			}
		}
	}

	int sum = 0;
	for (int k = 0; k < 10; k++)
	{
		sum += cache[N - 1][k][1023];
		sum %= 1'000'000'000;
	}
	
	cout << sum;

	return 0;
}