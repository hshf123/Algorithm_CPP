#include <iostream>
#include <vector>
using namespace std;


int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	cin >> T;
	vector<long> v;
	for (int i = 0; i < T; i++)
	{
		long x, y;
		cin >> x >> y;
		v.push_back(y - x);
	}

	for (int k = 0; k < T; k++)
	{
		long i = 1;
		while (v[k] >= i * i)
		{
			i++;
		}

		int count = --i;
		v[k] -= i * i;

		if (v[k] == 0)
		{
			count = count * 2 - 1;
		}
		else if (v[k] > i)
		{
			count = count * 2 - 1 + (v[k] / i);
		}
		else
		{
			count = count * 2;
		}

		cout << count << "\n";
	}
}