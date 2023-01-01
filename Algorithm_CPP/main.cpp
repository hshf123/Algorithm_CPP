#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	int max = INT32_MIN;
	int min = INT32_MAX;

	for (int i = 0; i < N; i++)
	{
		int n;
		cin >> n;

		if (n > max)
			max = n;
		if (n < min)
			min = n;
	}

	cout << min << " " << max;
}