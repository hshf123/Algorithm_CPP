#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int arr[42] = {};
	int count = 0;

	for (int i = 0; i < 10; i++)
	{
		int N;
		cin >> N;

		arr[N % 42]++;
	}

	for (int i = 0; i < 42; i++)
	{
		if (arr[i] != 0)
			count++;
	}

	if (count == 0)
		count++;
	cout << count;
}