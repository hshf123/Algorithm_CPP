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

void BackTracking(int n, int count)
{
	if (count == M)
	{
		for (int i = 0; i < M; i++)
			cout << ans[i] << " ";
		cout << endl;
		return;
	}

	int prevNum = 0;
	for (int i = n; i < seq.size(); i++)
	{
		if (visited[i] == false && seq[i] != prevNum)
		{
			visited[i] = true;
			ans[count] = seq[i];
			prevNum = seq[i];
			BackTracking(1, count + 1);
			visited[i] = false;
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
	ans = vector<int>(M, -1);
	visited = vector<bool>(seq.size(), false);
	BackTracking(1, 0);

	return 0;
}
