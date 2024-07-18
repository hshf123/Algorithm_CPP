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

#define SHIFT(x) 1 << x

vector<int> switchList =
{
	SHIFT(0) | SHIFT(1) | SHIFT(2),
	SHIFT(3) | SHIFT(7) | SHIFT(9) | SHIFT(11),
	SHIFT(4) | SHIFT(10) | SHIFT(14) | SHIFT(15),
	SHIFT(0) | SHIFT(4) | SHIFT(5) | SHIFT(6) | SHIFT(7),
	SHIFT(6) | SHIFT(7) | SHIFT(8) | SHIFT(10) | SHIFT(12),
	SHIFT(0) | SHIFT(2) | SHIFT(14) | SHIFT(15),
	SHIFT(3) | SHIFT(14) | SHIFT(15),
	SHIFT(4) | SHIFT(5) | SHIFT(7) | SHIFT(14) | SHIFT(15),
	SHIFT(1) | SHIFT(2) | SHIFT(3) | SHIFT(4) | SHIFT(5),
	SHIFT(3) | SHIFT(4) | SHIFT(5) | SHIFT(9) | SHIFT(13),
};

void Push(vector<int>& timeList, const int& btn)
{
	int idx = 0;
	for (int i = 1; i < SHIFT(16); i <<= 1)
	{
		if (switchList[btn] & i)
		{
			timeList[idx] += 3;
			if (timeList[idx] == 15)
				timeList[idx] = 3;
		}
		idx++;
	}
}

int Solution(vector<int>& timeList, int btn)
{
	// 모든 시계가 12시를 가리키고 있다면 땡
	if (btn == 10)
	{
		bool done = true;
		for (const int& time : timeList)
		{
			if (time != 12)
			{
				done = false;
				break;
			}
		}
		if (done)
			return 0;
		if (btn == 10)
			return INT32_HALF;
	}

	int ret = INT32_HALF;
	for (int i = 0; i < 4; i++)
	{
		ret = min(ret, Solution(timeList, btn + 1) + i);
		Push(timeList, btn);
	}
	return ret;
}

int main()
{
	Init;

	int C;
	cin >> C;
	vector<int> ansList(C, 0);
	for (int c = 0; c < C; c++)
	{
		vector<int> timeList(16);
		for (int i = 0; i < 16; i++)
			cin >> timeList[i];

		ansList[c] = Solution(timeList, 0);
	}
	
	for (const int& ans : ansList)
		cout << ans << endl;
	
	return 0;
}