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
#include <cmath>


int main()
{
	cin.tie(NULL);
	cout.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<int> vec(N);
	vector<int> ans(M);
	int sum = 0;
	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;
		sum += n;
		vec[i] = sum;
	}

	for (int m = 0; m < M; m++)
	{
		int i, j;
		cin >> i >> j;

		if (i == 1)
		{
			ans[m] = vec[j - 1];
		}
		else
		{
			ans[m] = vec[j - 1] - vec[i - 2];
		}
	}

	for (int& n : ans)
		cout << n << endl;

	return 0;
}

