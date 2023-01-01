#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int max = 0;
	int count = 1;

	for (int i = 0; i < 9; i++)
	{
		int n;
		cin >> n;
		if (n > max)
		{
			max = n;
			count = i + 1;
		}
	}

	cout << max << "\n" << count;
}