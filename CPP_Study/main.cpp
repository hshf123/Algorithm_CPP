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

int N, M;
vector<int> seq;
vector<bool> visited;

void BackTracking(int num, int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
			cout << seq[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = num; i <= N; i++)
	{
		if (!visited[i])
		{
			seq[cnt] = i;
			BackTracking(i, cnt + 1);
		}
	}
}

int main()
{
	Init;

	cin >> N >> M;
	seq = vector<int>(9, 0);
	visited = vector<bool>(9, false);
	BackTracking(1, 0);

	return 0;
}
