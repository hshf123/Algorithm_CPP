#include <iostream>
using namespace std;
#define endl "\n"
#define int64 long long

#include <cmath>
#include <map>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N, M;
	cin >> N >> M;

	vector<int> vec(N);
	for (int i = 0; i < N; i++)
	{
		int card;
		cin >> card;
		vec[i] = card;
	}

	sort(vec.begin(), vec.end(), [](int i, int j) {return i > j; });
	
	int max = 0;
	for (int i = 0; i < N - 2; i++)
	{
		for (int j = i + 1; j < N - 1; j++)
		{
			for (int k = j + 1; k < N; k++)
			{
				int sum = vec[i] + vec[j] + vec[k];
				if (sum > max && M >= sum)
					max = sum;
			}
		}
	}
	cout << max;
}
