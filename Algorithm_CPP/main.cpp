#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int K, N;
	cin >> K >> N;

	vector<int> vec;

	for (int i = 0; i < K; i++)
	{
		int num;
		cin >> num;

		vec.push_back(num);
	}

	sort(vec.begin(), vec.end());

	int max = vec.back();

	long long left = 1;
	long long right = max;

	int count;
	int ans = 0;
	while (left <= right)
	{
		count = 0;
		long long mid = (left + right) / 2;

		for (int n : vec)
			count += (n / mid);

		if (count >= N)
		{
			if (ans < mid)
				ans = mid;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}

	cout << ans;
}