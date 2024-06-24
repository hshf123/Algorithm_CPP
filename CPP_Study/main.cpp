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
vector<int> nums;
vector<int> arr;

int twoPointer(int left, int right, int cnt, int kind, int m)
{
	if (right >= N)
		return m;

	if (nums[arr[right]] == 0)
		kind++;

	cnt++;
	nums[arr[right]]++;

	// 만약 과일의 종류가 2개를 넘으면, 왼쪽의 포인터를 이동한다.
	if (kind > 2)
	{
		if (--nums[arr[left]] == 0)
			kind--;
		cnt--;
		left++;
	}

	m = max(m, cnt);
	return twoPointer(left, right + 1, cnt, kind, m);
}

int main()
{
	Init;
	cin >> N;
	nums.resize(10, 0);
	for (int i = 0; i < N; i++)
	{
		int t;
		cin >> t;
		arr.push_back(t);
	}

	cout << twoPointer(0, 0, 0, 0, 0);
}