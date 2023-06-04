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

vector<int> cache;
vector<int> parent;
int N;

int MakeOne(int n)
{
	// 기저 사례
	if (n == N)
		return 0;
	if (n > N)
		return INT32_MAX;

	// 캐시 확인
	int& ret = cache[n];
	if (ret != -1)
		return ret;

	int a = MakeOne(n * 3);
	int b = MakeOne(n * 2);
	int c = MakeOne(n + 1);

	ret = min(a, min(b, c));
	if (ret == a)
	{
		parent[n] = n * 3;
	}
	else if (ret == b)
	{
		parent[n] = n * 2;
	}
	else if (ret == c)
	{
		parent[n] = n + 1;
	}

	return ret += 1;
}

int main()
{
	cin >> N;

	if (N == 1)
	{
		cout << 0 << endl << 1;
		return 0;
	}

	cache = vector<int>(N + 1, -1);
	parent = vector<int>(N + 1, -1);

	parent[N] = N;
	cout << MakeOne(1) << endl;

	stack<int> s;
	int n = 1;
	while (true)
	{
		s.push(n);
		n = parent[n];
		if (n == parent[n])
		{
			s.push(n);
			break;
		}
	}

	while (s.empty() == false)
	{
		cout << s.top() << " ";
		s.pop();
	}

	return 0;
}