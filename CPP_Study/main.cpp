#include <iostream>
using namespace std;
#define endl "\n"
using int64 = long long;
using uint64 = unsigned long long;

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

vector<int> truth;
vector<int> parent;
vector<int> _rank;
vector<vector<int>> party;

int Find(int n)
{
	if (n == parent[n])
		return n;

	return Find(parent[n]);
}

void Union(int u, int v)
{
	u = Find(u);
	v = Find(v);

	if (u == v)
		return;

	parent[u] = v;
}

int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M; 
	cin >> N >> M;

	parent = vector<int>(N + 1);
	for (int i = 1; i <= N; i++)
		parent[i] = i;

	int truthCount;
	cin >> truthCount;
	for (int i = 0; i < truthCount; i++)
	{
		int num;
		cin >> num;
		truth.push_back(num);
	}

	party = vector<vector<int>>(M);
	for (int i = 0; i < M; i++)
	{
		int p;
		cin >> p;
		for (int j = 1; j <= p; j++)
		{
			int num;
			cin >> num;
			party[i].push_back(num);
		}
	}

	for (int i = 0; i < M; i++) {
		int n1 = party[i][0];
		for (int j = 1; j < party[i].size(); j++) {
			int n2 = party[i][j];
			Union(n1, n2);
		}
	}

	int ans = 0;
	for (int i = 0; i < M; i++) {
		bool flag = false;
		for (int j = 0; j < party[i].size(); j++) {
			int n1 = party[i][j];
			for (int k = 0; k < truth.size(); k++) {
				if (Find(n1) == Find(truth[k])) {
					flag = true;
					break;
				}
			}
			if (flag) break;
		}

		if (flag == false)
			ans++;
	}

	cout << ans;

	return 0;
}
