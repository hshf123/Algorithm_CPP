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

struct Student
{
	int cnt = 0;
	int flag = 0;
};

int N, D, K;
vector<Student> vec;

int GetCount(int flag)
{
	int ret = 0;
	for (Student& s : vec)
	{
		if (s.flag == (flag & s.flag))
			ret++;
	}

	return ret;
}

int DFS(const int& cnt, const int& idx, const int& flag)
{
	if (cnt == K)
	{
		return GetCount(flag);
	}

	int ret = 0;
	for (int i = idx; i <= D; i++)
	{
		if ((flag & (1 << i)))
			continue;
		ret = max(ret, DFS(cnt + 1, i + 1, flag | (1 << i)));
	}
	return ret;
}

int main()
{
	Init;

	cin >> N >> D >> K;
	vec.resize(N);
	for (int i = 0; i < N; i++)
	{
		int cnt;
		cin >> cnt;
		Student s;
		s.cnt = cnt;
		for (int j = 0; j < cnt; j++)
		{
			int flag;
			cin >> flag;
			s.flag |= (1 << flag);
		}

		vec[i] = s;
	}

	int ret = DFS(0, 1, 0);
	cout << ret;
	return 0;
}