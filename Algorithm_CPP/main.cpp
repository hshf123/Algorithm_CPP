#include <iostream>
using namespace std;
#define endl "\n"
using int64 = long long;

#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <set>
#include <stack>
#include <list>

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;
	
	vector<int> vec(N);
	for (int i = 0; i < N; i++)
	{
		int H;
		cin >> H;
		vec[i] = H;
	}
	sort(vec.begin(), vec.end());

	int height = 0;
	int left = 0;
	int right = vec.back();
	while (left <= right)
	{
		int mid = (left + right) / 2;
		int64 sum = 0;
		for (int i = 0; i < N; i++)
		{
			int tree = vec[i];
			sum += (tree - mid > 0 ? tree - mid : 0);
		}
		if (sum >= M)
		{
			if (height < mid)
				height = mid;
			left = mid + 1;
		}
		else
		{
			right = mid - 1;
		}
	}

	cout << height;
}
