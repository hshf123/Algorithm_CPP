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
int ret = 0;

void DFS(int cnt, int idx, int flag)
{
	if (cnt == N)
	{
		int n = 0;
		string ans;
		for (int i = 1; i < N * 2 + 1; i++)
		{
			if (flag & (1 << i))
			{
				ans += "(";
				n++;
			}
			else
			{
				ans += ")";
				n--;
			}
			if (n < 0)
				return;
		}
		ret++;
		cout << ans << endl;
		return;
	}

	for (int i = idx + 1; i < N * 2; i++)
	{
		DFS(cnt + 1, i, (flag | (1 << i)));
	}
}

int main()
{
	Init;

	cin >> N;
	DFS(1, 1, 2);
	cout << ret;

	return 0;
}