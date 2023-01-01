#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	double arr[1000];

	int max = 0;
	for (int i = 0; i < N; i++)
	{
		int num;
		cin >> num;

		arr[i] = num;
		if (num > max)
			max = num;
	}

	double sum = 0;
	for (int i = 0; i < N; i++)
	{
		arr[i] = arr[i] / max * 100;
		sum += arr[i];
	}

	cout << fixed;
	cout.precision(3);
	cout << sum / (double)N;
}