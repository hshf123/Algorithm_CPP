#include <iostream>
using namespace std;
#define endl "\n"
using int64 = long long;

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

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<pair<int, int>> vec(N);
	for (int i = 0; i < N; i++)
	{
		int kg, cm;
		cin >> kg >> cm;
		int rank = i;
		vec[i] = make_pair(kg, cm);
	}

	for (int i = 0; i < N; i++)
	{
		pair<int, int>& now = vec[i];
		int rank = 1;
		for (pair<int, int>& next : vec)
		{
			if (now.first < next.first && now.second < next.second)
				rank++;
		}

		cout << rank << " ";
	}

	return 0;
}
