#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int n;
	int arr[8];

	for (int i = 0; i < 8; i++)
	{
		cin >> n;
		arr[i] = n;
	}

	int prev = arr[0];
	for (int i = 1; i < 8; i++)
	{
		if (arr[i] - prev != 1)
			break;

		prev = arr[i];
		if (i==7)
		{
			cout << "ascending";
			return 0;
		}
	}
	prev = arr[0];
	for (int i = 1; i < 8; i++)
	{
		if (prev - arr[i] != 1)
			break;

		prev = arr[i];
		if (i == 7)
		{
			cout << "descending";
			return 0;
		}
	}

	cout << "mixed";
	return 0;
}