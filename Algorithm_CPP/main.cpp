#include <iostream>
using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;

	int ans = 0;
	int count = 665;

	while (N != ans)
	{
		count++;
		int temp = count;

		while(temp != 0)
		{
			if (temp % 1000 == 666)
			{
				ans++;
				break;
			}
			else
			{
				temp /= 10;
			}
		}
	}

	cout << count;
}