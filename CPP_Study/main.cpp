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

#define endl "\n"
#define INT32_HALF (INT32_MAX / 2)
#define Init cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
using int64 = long long;
using uint64 = unsigned long long;

int HalfUp(const float& val)
{
	int t = static_cast<int>(val * 10) % 10;
	if (t >= 5)
		t = static_cast<int>(val) + 1;
	else
		t = static_cast<int>(val);

	return t;
}

int TrimmedMean(const int& n)
{
	return HalfUp(static_cast<float>(n) * 0.15f);
}

int main()
{
	int N = 0;
	cin >> N;
	if (N == 0)
	{
		cout << 0;
		return 0;
	}

	std::multiset<int> opList;
	for (int i = 0; i < N; i++)
	{
		int op;
		cin >> op;
		opList.insert(op);
	}

	int tm = TrimmedMean(N);
	int i = 0;
	int opSum = 0;
	for (const int& n : opList)
	{
		if (i < tm || i >= N - tm)
		{
			++i;
			continue;
		}

		opSum += n;
		++i;
	}

	cout << HalfUp(static_cast<float>(opSum) / static_cast<float>(N - tm - tm));
}