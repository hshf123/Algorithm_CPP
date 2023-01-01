#include <iostream>

using namespace std;

int main()
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	int T;
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		string s;
		cin >> s;

		int sum = 0;
		int count = 0;
		for (int j = 0; j < s.length(); j++)
		{
			if (s[j] == 'O')
			{
				count += 1;
				sum += count;
			}
			else
				count = 0;
		}

		cout << sum << "\n";
	}
}