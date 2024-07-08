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

vector<int> GetPrimeNumberList(const int& number)
{
	vector<int> ret;
	vector<bool> vec(number + 1, false);
	for (int i = 2; i <= number; i++)
	{
		if (vec[i])
			continue;
		ret.push_back(i);
		for (int idx = i; idx <= number; idx += i)
			vec[idx] = true;
	}

	return ret;
}

int main()
{
	Init;

	int N;
	cin >> N;
	vector<int> primeNumberList = GetPrimeNumberList(N);

	int ans = 0;
	int sum = 0;

	int start = 0;
	int end = 0;
	while (true)
	{
		if ((end >= primeNumberList.size() || start >= primeNumberList.size()) && sum < N)
			break;

		if (sum == N)
			ans++;

		if (sum >= N)
		{
			sum -= primeNumberList[start];
			start++;
		}
		else
		{
			sum += primeNumberList[end];
			end++;
		}
	}
	
	cout << ans;

	return 0;
}