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
vector<int> ans;
vector<bool> visited;

void BackTracking(int num, int cnt)
{
	if (cnt == M)
	{
		for (int i = 0; i < M; i++)
			cout << ans[i] << " ";
		cout << endl;
		return;
	}
	for (int i = num; i <= N; i++)
	{
		if (!visited[seq[i]])
		{
			visited[seq[i]] = true;
			ans[cnt] = seq[i];
			BackTracking(1, cnt + 1);
			visited[seq[i]] = false;
		}
	}
}

int main()
{
	Init;

	cin >> N >> M;
	seq.push_back(0);
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		seq.push_back(n);
	}
	::sort(seq.begin(), seq.end());
	ans = vector<int>(seq.back() + 1, 0);
	visited = vector<bool>(seq.back() + 1, false);
	BackTracking(1, 0);

	return 0;
}
