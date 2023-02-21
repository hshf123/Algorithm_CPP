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
#define endl "\n"
#define INT32_HALF (2147483647 / 2)
#define Init cin.tie(NULL); cout.tie(NULL); ios::sync_with_stdio(false);
using namespace std;
using int64 = long long;
using uint64 = unsigned long long;

int A, B;

int Double(int n)
{
	return n * 2;
}

int AppendOne(int n)
{
	return n * 10 + 1;
}

void Search(int n)
{
	queue<pair<int, int>> q;
	q.push({ n, 1 });

	while (q.empty() == false)
	{
		int now = q.front().first;
		int count = q.front().second;
		q.pop();

		if (now > B)
			continue;

		if (now == B)
		{
			cout << count;
			return;
		}

		q.push({ Double(now), count + 1 });
		q.push({ AppendOne(now), count + 1 });
	}

	cout << -1;
	return;
}

int main()
{
	Init;

	cin >> A >> B;
	Search(A);

	return 0;
}
